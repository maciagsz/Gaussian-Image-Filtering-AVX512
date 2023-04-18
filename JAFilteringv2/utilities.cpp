#include "utilities.h"

#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

typedef void(_stdcall* GuassianFilter)(BYTE*, int, int, int, int, int);

void MarshalString(System::String^ s, std::string& os) {
    const char* chars =
        static_cast<const char*>((System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer());
    os = chars;
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

void MarshalString(System::String^ s, std::wstring& os) {
    const wchar_t* chars =
        static_cast<const wchar_t*>((System::Runtime::InteropServices::Marshal::StringToHGlobalUni(s)).ToPointer());
    os = chars;
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

HINSTANCE loadDll(bool dll_mode)
{
    HINSTANCE library;
    if (dll_mode)
    {
        library = LoadLibraryA("ASMDLL.dll");
    }
    else
    {
        library = LoadLibraryA("CPPDLL.dll");
    }

    if (library == nullptr)
    {
        throw gcnew System::DllNotFoundException();
    }

    return library;
}

void run(const std::string& filename, const int thread_number, const int sharpening_amount, const bool dll_mode)
{
    if (dll_mode)
    {
        checkCpuInstructionSet();
    }

    Bitmap* image = new Bitmap;
    HINSTANCE library = loadDll(dll_mode);
    loadImage(filename, image);
    checkImage(image);
    processImage(image, library, thread_number, sharpening_amount, dll_mode);
    saveImage(filename, image);
    finalize(image, library);
}

void checkCpuInstructionSet()
{
    if (!IsProcessorFeaturePresent(PF_AVX512F_INSTRUCTIONS_AVAILABLE))
    {
        throw gcnew System::Exception("This machine does not support AVX512 instruction set.");
    }
}

void loadImage(const std::string& filepath, Bitmap* image)
{
    std::ifstream input_file(filepath, std::ios::in | std::ios::binary | std::ios::ate);

    if (!input_file.is_open())
    {
        throw gcnew System::IO::FileLoadException;
    }

    const long long image_size = input_file.tellg();
    image->image_data = new char[image_size];
    input_file.seekg(0, std::ios::beg);
    input_file.read(image->image_data, image_size);
    image->file_header = reinterpret_cast<PBITMAPFILEHEADER>(image->image_data);
    image->info_header = reinterpret_cast<PBITMAPINFOHEADER>(image->image_data + sizeof(BITMAPFILEHEADER));
    image->pixel_array = reinterpret_cast<uint8_t*>(image->image_data + image->file_header->bfOffBits);

    input_file.close();
}

void checkImage(const Bitmap* image)
{
    if (image->file_header->bfType != 0x4D42) {
        throw gcnew System::Exception("Unrecognized file format.");
    }

    if (image->info_header->biBitCount != 24) {
        throw gcnew System::Exception("Incorrect image color depth.");
    }

    if (image->info_header->biCompression != BI_RGB) {
        throw gcnew System::Exception("Incorrect image compression.");
    }
}

void saveImage(const std::string& filepath, Bitmap* image)
{
    std::string outpath = filepath;
    outpath.erase(outpath.size() - 4, 4);
    outpath.append("_out.bmp");

    std::ofstream output_file(outpath, std::ios::out | std::ios::binary);
    if (!output_file.is_open())
    {
        throw gcnew System::Exception("Could not save file.");
    }

    output_file.write(image->image_data, image->file_header->bfSize);
    output_file.close();
}

void processImage(Bitmap* image, HINSTANCE library, int thread_number, int sharpening_amount, bool dll_mode)
{
    GuassianFilter gauss = (GuassianFilter)GetProcAddress(library, "GaussianFilter");
    if (gauss == nullptr)
    {
        throw gcnew System::Exception("Could not load procedure from library.");
    }

    int subpx_width = image->info_header->biWidth * 3;
    while (subpx_width % 4 != 0)
    {
        subpx_width++;
    }

    int division_parts = image->info_header->biSizeImage / thread_number;
    int fsharpening_amount = sharpening_amount;
    std::thread* threads = new std::thread[thread_number];

    for (int i = 0; i < thread_number - 1; i++)
    {
        int start_pos = i * division_parts;
        int end_pos = (i + 1) * division_parts;
        threads[i] = std::thread(gauss, image->pixel_array, image->info_header->biSizeImage, subpx_width, start_pos, end_pos, fsharpening_amount);
    }

    threads[thread_number - 1] = std::thread(gauss, image->pixel_array, image->info_header->biSizeImage, subpx_width, (thread_number - 1) * division_parts, image->info_header->biSizeImage, fsharpening_amount);

    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < thread_number; i++)
    {
        threads[i].join();
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

    std::fstream outfile("timelog.txt", std::ios::app);

    outfile << "Thread count: " << thread_number << " " << time << " ns, mode: " << dll_mode << "\n";

    delete[] threads;
}

void finalize(Bitmap* image, HINSTANCE library)
{
    FreeLibrary(library);
    delete image;

    System::Windows::Forms::MessageBox::Show("Program completed successfully", "Success", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
}

Bitmap::~Bitmap()
{
    delete image_data;
    image_data = nullptr;
}