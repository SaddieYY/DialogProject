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

//����������� ��������� ������ ��� ������ ��������,
//������ ������� ���� � ������� � pipe ���� id
// ����������� ������� ����� ����, ����������
// ���� � ��������� open � �� create ���� �, �� ������ �������
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
