#pragma comment(linker,"/subsystem:windows")
#include "MyForm.h"

using namespace calculator_windows;

int main(array<System::String^>^arg)
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}

