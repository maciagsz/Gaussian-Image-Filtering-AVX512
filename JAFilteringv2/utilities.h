#ifndef UTILITIES_H
#define	UTILITIES_H

#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

struct Bitmap
{
    PBITMAPFILEHEADER file_header; //The BITMAPFILEHEADER structure contains information about the type, size, and layout of a file that contains a DIB.
    //"https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader"

    PBITMAPINFOHEADER info_header; //The BITMAPINFOHEADER structure contains information about the dimensions and color format of a DIB.
    //"https://learn.microsoft.com/en-us/previous-versions/dd183376(v=vs.85)"

    BYTE* pixel_array;
    char* image_data;

    ~Bitmap();
};

void MarshalString(System::String^ s, std::string& os);
void MarshalString(System::String^ s, std::wstring& os);

HINSTANCE loadDll(bool dll_mode);

void run(const std::string& filename, int thread_number, int sharpening_amount, bool dll_mode);
void checkCpuInstructionSet();
void loadImage(const std::string& filepath, Bitmap* image);
void checkImage(const Bitmap* image);
void saveImage(const std::string& filepath, Bitmap* image);
void processImage(Bitmap* image, HINSTANCE library, int thread_number, int sharpening_amount, bool dll_mode);
void finalize(Bitmap* image, HINSTANCE library);

#endif
