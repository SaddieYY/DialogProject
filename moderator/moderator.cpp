#include "moderator.h"

void cModerator::Moderate(int id)
{
	string file = "UserFileMap" + to_string(id);
	HANDLE hFileMap = OpenFileMappingA(FILE_MAP_READ, true, file.c_str());
	//������� pipe
	//��������� �������-������ ��������
	//��������� ��� ���������� ������� �������� ������������ �����
	//���� ���������� SetEvent(hEventSend);

}
