#include <iostream> 
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)//x,y l� t?a di?m x,y tr�n m�n h�nh
{
    //C�c h�m n�y l� h�m thao t�c API v?i windows b?n c? coppy th�i kh�ng c?n ph?i hi?u qu� s�u.
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = { x, y };
    SetConsoleCursorPosition(h, a);
}

int main()
{
  
    return 0;
}