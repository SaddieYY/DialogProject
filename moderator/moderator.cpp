#include "moderator.h"

void cModerator::Moderate(int id)
{
	string file = "UserFileMap" + to_string(id);
	HANDLE hFileMap = OpenFileMappingA(FILE_MAP_READ, true, file.c_str());
	//читання pipe
	//створення функцій-потоків перевірок
	//структура для повернення кількості входжень забороненого слова
	//якщо виконується SetEvent(hEventSend);

}
