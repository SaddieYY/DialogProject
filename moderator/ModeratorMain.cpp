#include <windows.h>
#include <iostream>
#include <string>
#include "moderator.h"
using namespace std;



int main(int argc, char* argv[])
{
	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
	int id = atoi(argv[1]);

	HANDLE hEventSend, hEventUserSend, hEventTermination, hEventUserTermination;
	HANDLE hUserMail;
	HANDLE h[2];

	string send = "$UserSend" + to_string(id) + "$", term = "$UserTerm" + to_string(id) + "$", usermail = "\\\\.\\mailslot\\$usermail" + to_string(id) + "$";
	string sendu = "$MyEventSend" + to_string(id) + "$", termu = "$MyEventTerm" + to_string(id) + "$";

	string sended = "$MyEventSended" + to_string(id) + "$", notsended = "$MyEventNotSended" + to_string(id) + "$", modercr = "$ModerCreated" + to_string(id) + "$";
	HANDLE hEventModerCreated = CreateEventA(NULL, false, false, modercr.c_str());
	HANDLE hEventSended = CreateEventA(NULL, false, false, sended.c_str());
	HANDLE hEventNotSended = CreateEventA(NULL, false, false, notsended.c_str());

	string mail = "\\\\.\\mailslot\\$mail" + to_string(id) + "$";
	HANDLE hMail = CreateFileA(mail.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE , NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	hEventUserSend = CreateEventA(NULL, false, false, sendu.c_str());
	if (!hEventUserSend) {
		return GetLastError();
	}
	hEventUserTermination = CreateEventA(NULL, false, false, termu.c_str());
	if (!hEventUserTermination) {
		return GetLastError();
	}

	hEventSend = OpenEventA(EVENT_ALL_ACCESS, true, send.c_str());
	if (!hEventSend) {
		return GetLastError();
	}
	hEventTermination = OpenEventA(EVENT_ALL_ACCESS, true, term.c_str());
	if (!hEventTermination) {
		return GetLastError();
	}
	hUserMail = CreateMailslotA(usermail.c_str(), 1000, MAILSLOT_WAIT_FOREVER, NULL); 
	if (!hUserMail || hUserMail == INVALID_HANDLE_VALUE) {
		return GetLastError();
	}

	h[0] = hEventUserTermination;
	h[1] = hEventUserSend;

	if (!hEventModerCreated) {
		return GetLastError();
	}

	if (!hEventSended || hEventNotSended == INVALID_HANDLE_VALUE) {
		return GetLastError();
	}
	if (!hEventNotSended || hEventNotSended == INVALID_HANDLE_VALUE) {
		return GetLastError();
	}

	SetEvent(hEventModerCreated);

	
	while (true) {
		cout << "Wait for signal" << endl;
		DWORD dwCode = WaitForMultipleObjects(2, h, false, INFINITE);
		cout << "Signal detected" << endl;
		if (dwCode == WAIT_OBJECT_0 + 1) {
			char buf[100];
			DWORD temp;
			//SetFilePointer(hMail, NULL, NULL, FILE_BEGIN);
			bool b = ReadFile(hUserMail, buf, 100, &temp, NULL);
			string mes(buf);
			cout << mes << endl;
			if (cModerator::Moderate(mes)) {

				if (SetEvent(hEventSended)) cout << "User send" << endl;
				if (WriteFile(hMail, buf, strlen(buf) + 1, &temp, NULL)) cout << "Writing ended!" << endl;
				if (SetEvent(hEventSend)) cout << "Server send" << endl;
				
			}
			else {
				SetEvent(hEventNotSended);
			}
		}
		else {
			CloseHandle(hUserMail);
			SetEvent(hEventTermination);
			break;
		}
	}
	//FreeConsole();
	CloseHandle(hEventSended);
	CloseHandle(hEventNotSended);
	return 0;
}


	

	
