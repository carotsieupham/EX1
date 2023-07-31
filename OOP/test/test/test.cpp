#include <iostream> 
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)//x,y là t?a di?m x,y trên màn hình
{
    //Các hàm này là hàm thao tác API v?i windows b?n c? coppy thôi không c?n ph?i hi?u quá sâu.
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = { x, y };
    SetConsoleCursorPosition(h, a);
}

int main()
{
  
    return 0;
}