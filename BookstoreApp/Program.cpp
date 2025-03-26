#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the main form
    BookstoreApp::MainForm^ mainForm = gcnew BookstoreApp::MainForm();
    Application::Run(mainForm);

    return 0;
}



