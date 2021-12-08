#pragma once
#include <Windows.h>
#include <string>
using namespace std;
class cUser
{
public:
	cUser(int a) {
		id = a;
		string send = "$MyEventSend" + to_string(id) + "$", term = "$MyEventTerm" + to_string(id) + "$", fileMail = "\\\\.\\mailslot\\$usermail" + to_string(id) + "$";
		string modercr = "$ModerCreated"  + to_string(id) + "$";
		do {
			hEventModerCreated = OpenEventA(READ_CONTROL, false, modercr.c_str());
		} while (!hEventModerCreated);
		WaitForSingleObject(hEventModerCreated, INFINITE);
		hEventSend = OpenEventA(EVENT_ALL_ACCESS, false, send.c_str());
		hEventTermination = OpenEventA(EVENT_ALL_ACCESS, false, term.c_str());
		hMail = CreateFileA(fileMail.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		string sended = "$MyEventSended" + to_string(id) + "$", notsended = "$MyEventNotSended" + to_string(id) + "$";
	}
	~cUser() {
		SetEvent(hEventTermination);
		CloseHandle(hEventSend);
		CloseHandle(hMail);
		CloseHandle(hEventTermination);
	}
	int Send(string mes) {
		const char* buf = mes.c_str();
		DWORD temp;
		bool a = WriteFile(hMail, buf, strlen(buf) + 1, &temp, NULL);
		string sended = "$MyEventSended" + to_string(id) + "$", notsended = "$MyEventNotSended" + to_string(id) + "$";
		hEventSended = OpenEventA(EVENT_ALL_ACCESS, false, sended.c_str());
		hEventNotSended = OpenEventA(EVENT_ALL_ACCESS, false, notsended.c_str());
		SetEvent(hEventSend);
		if (!hEventNotSended || hEventNotSended == INVALID_HANDLE_VALUE) return -1;
		if (!hEventSended || hEventSended == INVALID_HANDLE_VALUE) return -2;
		Sleep(1);
		const HANDLE h[2]{ hEventSended, hEventNotSended };
		DWORD dwCode = WaitForMultipleObjects(2, h, false, INFINITE);
		if (dwCode == WAIT_OBJECT_0 + 0) return 0;
		if (dwCode == WAIT_OBJECT_0 + 1) return 1;
		return -3;
	}
private:
	HANDLE hEventSend;
	HANDLE hMail;
	HANDLE hEventTermination;
	HANDLE hEventSended;
	HANDLE hEventNotSended;
	HANDLE hEventModerCreated;
	int id;
};

