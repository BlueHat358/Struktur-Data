#include <iostream>
#include <windows.h>

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void xy(short x, short y){
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle, coord);
}

void color(short fg, short bg){
    FlushConsoleInputBuffer(handle);
    SetConsoleTextAttribute(handle, bg * 16 + fg);
}