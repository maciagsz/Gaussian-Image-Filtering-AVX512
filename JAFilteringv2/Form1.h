#ifndef FORM1_H
#define FORM1_H

#include "utilities.h"

namespace CppCLRWinFormsProject {
    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ runButton;
    private: System::Windows::Forms::RadioButton^ radioButtonAsm;
    private: System::Windows::Forms::RadioButton^ radioButtonCpp;
    protected:

    private: System::Windows::Forms::GroupBox^ groupBoxMode;
    private: System::Windows::Forms::TrackBar^ trackBarThreadCount;

    private: System::Windows::Forms::GroupBox^ groupBoxThreads;
    private: System::Windows::Forms::TextBox^ textBoxThreadCount;

    private: System::Windows::Forms::TextBox^ textBoxThreads;

    private: System::Windows::Forms::Button^ openFileButton;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::TextBox^ textBoxFilepath;

    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::GroupBox^ groupBoxSharpening;

    private: System::Windows::Forms::TextBox^ textBoxSharpening;
    private: System::Windows::Forms::TrackBar^ trackBarSharpeningAmount;
    private: System::Windows::Forms::TextBox^ textBoxSharpeningAmount;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->runButton = (gcnew System::Windows::Forms::Button());
            this->radioButtonAsm = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonCpp = (gcnew System::Windows::Forms::RadioButton());
            this->groupBoxMode = (gcnew System::Windows::Forms::GroupBox());
            this->trackBarThreadCount = (gcnew System::Windows::Forms::TrackBar());
            this->groupBoxThreads = (gcnew System::Windows::Forms::GroupBox());
            this->textBoxThreads = (gcnew System::Windows::Forms::TextBox());
            this->textBoxThreadCount = (gcnew System::Windows::Forms::TextBox());
            this->openFileButton = (gcnew System::Windows::Forms::Button());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->textBoxFilepath = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->groupBoxSharpening = (gcnew System::Windows::Forms::GroupBox());
            this->textBoxSharpeningAmount = (gcnew System::Windows::Forms::TextBox());
            this->textBoxSharpening = (gcnew System::Windows::Forms::TextBox());
            this->trackBarSharpeningAmount = (gcnew System::Windows::Forms::TrackBar());
            this->groupBoxMode->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreadCount))->BeginInit();
            this->groupBoxThreads->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->groupBoxSharpening->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSharpeningAmount))->BeginInit();
            this->SuspendLayout();
            //
            // runButton
            //
            this->runButton->AutoSize = true;
            this->runButton->Location = System::Drawing::Point(113, 400);
            this->runButton->Name = L"runButton";
            this->runButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->runButton->Size = System::Drawing::Size(95, 34);
            this->runButton->TabIndex = 0;
            this->runButton->Text = L"Run";
            this->runButton->UseVisualStyleBackColor = true;
            this->runButton->Click += gcnew System::EventHandler(this, &Form1::runButton_Click);
            //
            // radioButtonAsm
            //
            this->radioButtonAsm->AutoSize = true;
            this->radioButtonAsm->Checked = true;
            this->radioButtonAsm->Location = System::Drawing::Point(6, 26);
            this->radioButtonAsm->Name = L"radioButtonAsm";
            this->radioButtonAsm->Size = System::Drawing::Size(68, 25);
            this->radioButtonAsm->TabIndex = 1;
            this->radioButtonAsm->TabStop = true;
            this->radioButtonAsm->Text = L"ASM";
            this->radioButtonAsm->UseVisualStyleBackColor = true;
            this->radioButtonAsm->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonAsm_CheckedChanged);
            //
            // radioButtonCpp
            //
            this->radioButtonCpp->AutoSize = true;
            this->radioButtonCpp->Location = System::Drawing::Point(6, 58);
            this->radioButtonCpp->Name = L"radioButtonCpp";
            this->radioButtonCpp->Size = System::Drawing::Size(63, 25);
            this->radioButtonCpp->TabIndex = 2;
            this->radioButtonCpp->Text = L"CPP";
            this->radioButtonCpp->UseVisualStyleBackColor = true;
            this->radioButtonCpp->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonCpp_CheckedChanged);
            //
            // groupBoxMode
            //
            this->groupBoxMode->Controls->Add(this->radioButtonAsm);
            this->groupBoxMode->Controls->Add(this->radioButtonCpp);
            this->groupBoxMode->Location = System::Drawing::Point(12, 13);
            this->groupBoxMode->Name = L"groupBoxMode";
            this->groupBoxMode->Size = System::Drawing::Size(312, 123);
            this->groupBoxMode->TabIndex = 3;
            this->groupBoxMode->TabStop = false;
            this->groupBoxMode->Text = L"DLL mode";
            this->groupBoxMode->Enter += gcnew System::EventHandler(this, &Form1::groupBoxMode_Enter);
            //
            // trackBarThreadCount
            //
            this->trackBarThreadCount->LargeChange = 4;
            this->trackBarThreadCount->Location = System::Drawing::Point(6, 26);
            this->trackBarThreadCount->Maximum = 64;
            this->trackBarThreadCount->Minimum = 1;
            this->trackBarThreadCount->Name = L"trackBarThreadCount";
            this->trackBarThreadCount->Size = System::Drawing::Size(300, 69);
            this->trackBarThreadCount->SmallChange = 2;
            this->trackBarThreadCount->TabIndex = 0;
            this->trackBarThreadCount->TickFrequency = 0;
            this->trackBarThreadCount->Value = 1;
            this->trackBarThreadCount->Scroll += gcnew System::EventHandler(this, &Form1::trackBarThreadCount_Scroll);
            //
            // groupBoxThreads
            //
            this->groupBoxThreads->Controls->Add(this->textBoxThreads);
            this->groupBoxThreads->Controls->Add(this->textBoxThreadCount);
            this->groupBoxThreads->Controls->Add(this->trackBarThreadCount);
            this->groupBoxThreads->Location = System::Drawing::Point(12, 142);
            this->groupBoxThreads->Name = L"groupBoxThreads";
            this->groupBoxThreads->Size = System::Drawing::Size(312, 123);
            this->groupBoxThreads->TabIndex = 5;
            this->groupBoxThreads->TabStop = false;
            this->groupBoxThreads->Text = L"Number of threads";
            this->groupBoxThreads->Enter += gcnew System::EventHandler(this, &Form1::groupBoxThreads_Enter);
            //
            // textBoxThreads
            //
            this->textBoxThreads->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBoxThreads->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->textBoxThreads->Location = System::Drawing::Point(7, 79);
            this->textBoxThreads->Name = L"textBoxThreads";
            this->textBoxThreads->ReadOnly = true;
            this->textBoxThreads->Size = System::Drawing::Size(240, 22);
            this->textBoxThreads->TabIndex = 7;
            this->textBoxThreads->Text = L"Selected number of threads:";
            this->textBoxThreads->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxThreads_TextChanged);
            //
            // textBoxThreadCount
            //
            this->textBoxThreadCount->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBoxThreadCount->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->textBoxThreadCount->Location = System::Drawing::Point(253, 79);
            this->textBoxThreadCount->Name = L"textBoxThreadCount";
            this->textBoxThreadCount->ReadOnly = true;
            this->textBoxThreadCount->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->textBoxThreadCount->Size = System::Drawing::Size(53, 22);
            this->textBoxThreadCount->TabIndex = 6;
            this->textBoxThreadCount->Text = L"1";
            this->textBoxThreadCount->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxThreadCount_TextChanged);
            //
            // openFileButton
            //
            this->openFileButton->AutoSize = true;
            this->openFileButton->Location = System::Drawing::Point(12, 400);
            this->openFileButton->Name = L"openFileButton";
            this->openFileButton->Size = System::Drawing::Size(95, 34);
            this->openFileButton->TabIndex = 6;
            this->openFileButton->Text = L"Open file";
            this->openFileButton->UseVisualStyleBackColor = true;
            this->openFileButton->Click += gcnew System::EventHandler(this, &Form1::openFileButton_Click);
            //
            // openFileDialog1
            //
            this->openFileDialog1->Filter = L"bmp files (*.bmp)|*.bmp";
            this->openFileDialog1->RestoreDirectory = true;
            this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
            //
            // textBoxFilepath
            //
            this->textBoxFilepath->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBoxFilepath->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->textBoxFilepath->Location = System::Drawing::Point(0, 591);
            this->textBoxFilepath->Name = L"textBoxFilepath";
            this->textBoxFilepath->ReadOnly = true;
            this->textBoxFilepath->Size = System::Drawing::Size(778, 22);
            this->textBoxFilepath->TabIndex = 7;
            this->textBoxFilepath->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxFilepath_TextChanged);
            //
            // pictureBox1
            //
            this->pictureBox1->Location = System::Drawing::Point(339, 13);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(427, 307);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 8;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
            //
            // groupBoxSharpening
            //
            this->groupBoxSharpening->Controls->Add(this->textBoxSharpeningAmount);
            this->groupBoxSharpening->Controls->Add(this->textBoxSharpening);
            this->groupBoxSharpening->Controls->Add(this->trackBarSharpeningAmount);
            this->groupBoxSharpening->Location = System::Drawing::Point(12, 271);
            this->groupBoxSharpening->Name = L"groupBoxSharpening";
            this->groupBoxSharpening->Size = System::Drawing::Size(312, 123);
            this->groupBoxSharpening->TabIndex = 9;
            this->groupBoxSharpening->TabStop = false;
            this->groupBoxSharpening->Text = L"Sharpening amount";
            this->groupBoxSharpening->Enter += gcnew System::EventHandler(this, &Form1::groupBoxSharpening_Enter);
            //
            // textBoxSharpeningAmount
            //
            this->textBoxSharpeningAmount->BackColor = System::Drawing::SystemColors::Control;
            this->textBoxSharpeningAmount->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBoxSharpeningAmount->Location = System::Drawing::Point(253, 76);
            this->textBoxSharpeningAmount->Name = L"textBoxSharpeningAmount";
            this->textBoxSharpeningAmount->ReadOnly = true;
            this->textBoxSharpeningAmount->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->textBoxSharpeningAmount->Size = System::Drawing::Size(53, 22);
            this->textBoxSharpeningAmount->TabIndex = 2;
            this->textBoxSharpeningAmount->Text = L"1";
            //
            // textBoxSharpening
            //
            this->textBoxSharpening->BackColor = System::Drawing::SystemColors::Control;
            this->textBoxSharpening->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBoxSharpening->Location = System::Drawing::Point(6, 76);
            this->textBoxSharpening->Name = L"textBoxSharpening";
            this->textBoxSharpening->Size = System::Drawing::Size(241, 22);
            this->textBoxSharpening->TabIndex = 1;
            this->textBoxSharpening->Text = L"Selected sharpening amount:";
            //
            // trackBarSharpeningAmount
            //
            this->trackBarSharpeningAmount->LargeChange = 100;
            this->trackBarSharpeningAmount->Location = System::Drawing::Point(7, 29);
            this->trackBarSharpeningAmount->Maximum = 500;
            this->trackBarSharpeningAmount->Minimum = 100;
            this->trackBarSharpeningAmount->Name = L"trackBarSharpeningAmount";
            this->trackBarSharpeningAmount->Size = System::Drawing::Size(299, 69);
            this->trackBarSharpeningAmount->SmallChange = 50;
            this->trackBarSharpeningAmount->TabIndex = 0;
            this->trackBarSharpeningAmount->TickFrequency = 100;
            this->trackBarSharpeningAmount->Value = 100;
            this->trackBarSharpeningAmount->Scroll += gcnew System::EventHandler(this, &Form1::trackBarSharpeningAmount_Scroll);
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->AutoSize = true;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(778, 613);
            this->Controls->Add(this->groupBoxSharpening);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->textBoxFilepath);
            this->Controls->Add(this->openFileButton);
            this->Controls->Add(this->groupBoxThreads);
            this->Controls->Add(this->groupBoxMode);
            this->Controls->Add(this->runButton);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Name = L"Form1";
            this->Text = L"JAFiltering";
            this->groupBoxMode->ResumeLayout(false);
            this->groupBoxMode->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreadCount))->EndInit();
            this->groupBoxThreads->ResumeLayout(false);
            this->groupBoxThreads->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->groupBoxSharpening->ResumeLayout(false);
            this->groupBoxSharpening->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSharpeningAmount))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private: System::Void runButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if ((openFileDialog1->FileName == "") || (openFileDialog1->FileName == nullptr))
        {
            throw gcnew System::Exception("Select a bitmap first");
        }

        std::string std_str;
        MarshalString(openFileDialog1->FileName->ToString(), std_str);
        run(std_str, trackBarThreadCount->Value, trackBarSharpeningAmount->Value, radioButtonAsm->Checked);
    }
    private: System::Void radioButtonAsm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void radioButtonCpp_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void groupBoxMode_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void groupBoxThreads_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void trackBarThreadCount_Scroll(System::Object^ sender, System::EventArgs^ e) {
        textBoxThreadCount->Text = trackBarThreadCount->Value.ToString();
    }
    private: System::Void textBoxThreadCount_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBoxThreads_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
        openFileDialog1->ShowDialog();
    }
    private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        textBoxFilepath->Text = openFileDialog1->FileName->ToString();
        delete pictureBox1->Image;
        pictureBox1->Image = System::Drawing::Image::FromFile(textBoxFilepath->Text);
    }
    private: System::Void textBoxFilepath_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void trackBarSharpeningAmount_Scroll(System::Object^ sender, System::EventArgs^ e) {
        float value = trackBarSharpeningAmount->Value;
        value /= 100;
        textBoxSharpeningAmount->Text = value.ToString();
    }
    private: System::Void groupBoxSharpening_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}

#endif