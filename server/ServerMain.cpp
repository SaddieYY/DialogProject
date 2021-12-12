#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "server.h"
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#define PUTH_F "C:\\Users\\Saddie\\source\\repos\\lab11OS\\files\\"
using namespace std;

void writeFile(string mes){ //функція для запису повідомлення
	string filename = (string)PUTH_F + "DialogFile";
	ofstream out(filename, std::ofstream::ate | std::ofstream::app); 
	out.write((mes + '\n').data(), mes.size() + 1);
	out.close();
	return;
}

int id = 1;

class cUserServer {
public:
	cUserServer(const CHAR* file, const CHAR* term, const CHAR* send, const CHAR* reload) {
		hMail = CreateMailslotA(file, 100, MAILSLOT_WAIT_FOREVER, NULL);
		hEventTerm = CreateEventA(NULL, false, false, term);
		hEventSend = CreateEventA(NULL, false, false, send);
		h[0] = hEventTerm;
		h[1] = hEventSend;
	}
	HANDLE h[2];
	HANDLE hMail;
private:
	
	HANDLE hEventTerm;
	HANDLE hEventSend;
	
};

int main(void)
{
	string fileName = (string)PUTH_F + "DialogFile";
	ofstream in(fileName);
	in.close();
	HANDLE hEventServer;
	HANDLE hEventReload; 
	HANDLE hEventCreateClient; 
	HANDLE hEventCreatedClient; 
	HANDLE hCreateMail;
	HANDLE hEventTerminateA;
	STARTUPINFOA* si = nullptr;
	PROCESS_INFORMATION* pi = nullptr;
	list<cUserServer> list;
	hEventServer = CreateEventA(NULL, true, true, "$MyEventCreateServer$");
	if (!hEventServer) {
		return GetLastError();
	}
	hEventCreateClient = CreateEventA(NULL, true, false, "$MyEventCreateUser$");
	if (!hEventCreateClient) {
		return GetLastError();
	}
	hEventCreatedClient = CreateEventA(NULL, false, false, "$MyEventCreatedUser$");
	if (!hEventCreatedClient) {
		return GetLastError();
	}
	hEventReload = CreateEventA(NULL, true, false, "$MyEventReload$");
	if (!hEventReload) {
		return GetLastError();
	}
	hEventTerminateA = CreateEventA(NULL, true, false, "$MyEventTerminated$");
	const HANDLE h[2]{ hEventCreateClient,hEventTerminateA };
	hCreateMail = CreateMailslotA("\\\\.\\mailslot\\$createmail$", 100, MAILSLOT_WAIT_FOREVER, NULL);
	DWORD dwCode = WaitForMultipleObjects(2, h, false, INFINITE);
	if(dwCode == WAIT_OBJECT_0)
	while(true)
	{
		DWORD dwCode = WaitForSingleObject(hEventCreateClient, 5);
		if (dwCode == WAIT_OBJECT_0) {
			ResetEvent(hEventCreateClient);
			string mail = "\\\\.\\mailslot\\$mail" + to_string(id) + "$", term = "$UserTerm" + to_string(id) + "$", send = "$UserSend" + to_string(id) + "$", reload = "$UserReload" + to_string(id) + "$";
			cUserServer* a = new cUserServer(mail.c_str(), term.c_str(), send.c_str(), reload.c_str());
			list.push_back(*a);
			string temp = to_string(id);
			char buf[100];
			DWORD tempD;
			bool bB = ReadFile(hCreateMail, buf, 100, &tempD, NULL);
			string mes(buf);
			mes += " ";
			cout << mes << endl;
			char* b = new char[100];
			char* c = new char[100];
			strcpy(b, "moderator.exe ");
			strcpy(c, "user.exe ");
			strcat(c, mes.c_str());
			strcat(c, temp.c_str());
			strcat(b, temp.c_str());

			pi = new PROCESS_INFORMATION();
			si = new STARTUPINFOA();
			ZeroMemory(si, sizeof(si));
			si->cb = sizeof(si);
			ZeroMemory(pi, sizeof(pi));
			CreateProcessA(NULL, b, NULL, NULL, false, CREATE_NO_WINDOW, NULL, NULL, si, pi); //створення модера
			pi = new PROCESS_INFORMATION();
			si = new STARTUPINFOA();
			ZeroMemory(si, sizeof(si));
			si->cb = sizeof(si);
			ZeroMemory(pi, sizeof(pi));
			bool tempb = CreateProcessA(NULL, c, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, si, pi); //створення модера
			SetEvent(hEventCreatedClient);
			cout << "Item " << id << endl;
			++id;
			delete[] c;
			delete[] b;
		}
		else{
			if (list.size() == 0) break;
			for (auto i = list.begin(); i != list.end(); ++i) {
				DWORD tempD = WaitForMultipleObjects(2, (*i).h, false, 1);
				if (tempD == WAIT_TIMEOUT) continue;
				if (tempD == WAIT_OBJECT_0 + 1) {
					char buf[100];
					if (ReadFile((*i).hMail, buf, 100, NULL, NULL)) cout << "Reading ended!"  << endl;
					string temp(buf);
					writeFile(temp);
					SetEvent(hEventReload);
					Sleep(2);
					ResetEvent(hEventReload);
					cout << "Reload end" << endl;
				}
				else{
					list.erase(i);
					break;
				}
			}
		}
	}
	CloseHandle(hEventServer);
	CloseHandle(hEventTerminateA);
	CloseHandle(hEventCreateClient);
	CloseHandle(hEventCreatedClient);
	return 0;
}