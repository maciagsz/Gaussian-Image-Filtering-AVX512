#include "pch.h"
#include "Form1.h"

[System::STAThread]
int main()
{
    try
    {
        System::Windows::Forms::Application::EnableVisualStyles();
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
        System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
        System::Windows::Forms::Application::Run(gcnew CppCLRWinFormsProject::Form1());
    }
    catch (System::Exception^ ex)
    {
        System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(ex->Message, "Warning", System::Windows::Forms::MessageBoxButtons::RetryCancel, System::Windows::Forms::MessageBoxIcon::Warning);

        if (result == System::Windows::Forms::DialogResult::Retry)
        {
            System::Windows::Forms::Application::Restart();
        }
    }

    return 0;
}