/*
��������GNU GCC Compiler
���뻷����Windows 8.1
*/

#include "calculator_windows.h"

using namespace System;

int main()
{
	//System::Console::WriteLine("hello");
	Calculator_Windows^ c = gcnew Calculator_Windows();
	c->Show();
    return 0;
}
