#include "MyForm.h"
#include "system.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project::MyForm form;
	Application::Run(%form);
}

