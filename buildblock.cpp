#include<iostream>
#include<string>
#include<vector>
#include <Windows.h>
using namespace std;

vector <string> BlockT(7);
int nScreenWidth = 80;			
int nScreenHeight = 30;int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;
	


int main(){
    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
    
    BlockT.push_back("..X...X...X...X."); 
	BlockT.push_back("..X..XX...X.....");
	BlockT.push_back(".....XX..XX.....");
	BlockT.push_back("..X..XX..X......");
	BlockT.push_back(".X...XX...X.....");
	BlockT.push_back(".X...X...XX.....");
	BlockT.push_back("..X...X..XX.....");

    pField = new unsigned char[nFieldWidth*nFieldHeight]; 
	for (int x = 0; x < nFieldWidth; x++){
		for (int y = 0; y < nFieldHeight; y++){
			pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
        }
    }


    return 0;

}