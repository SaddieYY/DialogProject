#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int Number = 0;
HANDLE mymutex;
#define PUTH_F "C:\\Users\\Saddie\\source\\repos\\lab11OS\\files\\"
void StringSearch(string WordsArr, string WordToFind) //функція пошуку підстрічки
{
    int j;

    int textsize = WordsArr.length();
    int wordsize = WordToFind.length();

    for (int i = 0; i <= (textsize - wordsize); ++i)
    {
        for (j = 0; j < wordsize, i + j < textsize; ++j)
        {
            if (WordsArr[i + j] != WordToFind[j]) break;
        }

        if (j == wordsize)
        {
            WaitForSingleObject(mymutex, INFINITE);
            ++Number;
            ReleaseMutex(mymutex);
        }
    }
}

typedef struct ModData //структура для функції-потоку
{
	string message;
	string forbword;
};


DWORD WINAPI Moderator(LPVOID lpParam) //функція-потік
{
	ModData* prmts = (ModData*)lpParam;

	StringSearch(prmts->message, prmts->forbword);

	return 0;
}


class cModerator
{
public:
	static bool Moderate(string mes) { //статичний метод для перевірки на входження заборонених слів 
        Number = 0;
        vector<string> forbwords = { "forbiden", "kaka", "poop" };

        ModData* tmp = new ModData[forbwords.size()];

        HANDLE* arrth = new HANDLE[forbwords.size()];
        int* arrthid = new int[forbwords.size()];

        mymutex = CreateMutex(NULL, FALSE, NULL);

        for (int i = 0; i < forbwords.size(); ++i)
        {
            tmp[i].message = mes;
            tmp[i].forbword = forbwords[i];
            arrth[i] = CreateThread(NULL, 0, Moderator, &tmp[i], 0, (LPDWORD)&arrthid[i]);
        }
        WaitForMultipleObjects(forbwords.size(), arrth, TRUE, INFINITE);
        string fileName = (string)PUTH_F + "ErrorFile";
        ofstream in(fileName, ios::app);
        in << mes << " (" << Number << ")\n";
        in.close();
        if (Number > 2) return false;
        return true;
	}
private:
	cModerator();
};

