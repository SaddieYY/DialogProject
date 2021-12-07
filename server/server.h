#pragma once
#ifndef SERVER_H
#define SERVER_H



#include <Windows.h>
#include <vector>

class cUserConnect {
public:
	cUserConnect();
	~cUserConnect();
	HANDLE h[];

};

//авторизація відправляє сигнал про нового учасника,
//сервер створює його і повертає в pipe його id
// авторизація створює форму юзер, модератора
// юзер і модератор open а не create лише ті, які потрібні серверу
//
class cServer
{
public:
	cServer();
	~cServer();
	void Create();
	static int id;
private:
	//vector <cUserConnect> p;
};

#endif // !SERVER_H
