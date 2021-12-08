#include "UserForm.h"

#include <Windows.h>
#include <string>
#include "user.h"

using namespace user;
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	string a = GetCommandLineA();
	string tempa = a;
	char* temp = strtok(&tempa[0], " ");
	temp = strtok(NULL, " ");
	string tempName(temp);
	temp = strtok(NULL, " ");
	string temps(temp);
	int id = atoi(temps.c_str()); //зчитування аргументів командного рядка
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew UserForm(tempName, id));
	
}