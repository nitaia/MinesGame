#include "stdafx.h"
#include "lib.h"

void clrscr() {
	system("cls");
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

char getch() {
	return _gettch();
}

void delay(long timeMilli) {
	Sleep(timeMilli);
}

int wherex() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition.X;
}

int wherey() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition.Y;
}

void setColor(WORD color) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, color);
}
