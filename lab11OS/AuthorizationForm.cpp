#include "AuthorizationForm.h"
#include <Windows.h>

using namespace lab11OS;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AuthorizationForm);
}