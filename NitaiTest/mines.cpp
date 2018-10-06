#include "stdafx.h"
#include "lib.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#define BOARD_SIZE 10
#define NUM_MINES 1
#define MINE 9
#define NO_MINES 0
#define TMP_NO_MINES 10

int mines[BOARD_SIZE][BOARD_SIZE];
bool opened[BOARD_SIZE][BOARD_SIZE];

bool isNoMine(int x, int y) {
	return mines[y][x] == NO_MINES;
}

bool isInRange(int x, int y) {
	return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE;
}

int MinesChecker(int x, int y) {
	int q = 0;
	if(isInRange(x-1, y-1) && mines[y - 1][x-1] == MINE) {
		q++;
	}
	if (isInRange(x, y - 1) && mines[y - 1][x] == MINE) {
		q++;
	}
	if (isInRange(x + 1, y - 1) && mines[y - 1][x + 1] == MINE) {
		q++;
	}
	if (isInRange(x - 1, y) && mines[y][x - 1] == MINE) {
		q++;
	}
	if (isInRange(x + 1, y) && mines[y][x + 1] == MINE){
		q++;
	}
	if (isInRange(x - 1, y + 1) && mines[y + 1][x - 1] == MINE) {
		q++;
	}
	if (isInRange(x, y + 1) && mines[y + 1][x] == MINE) {
		q++;
	}
	if (isInRange(x + 1, y + 1) && mines[y + 1][x + 1] == MINE) {
		q++;
	}

	return q;
}

bool isWin() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (mines[y][x] != MINE && !opened[y][x]) {
				return false;
			}
		}
	}
	return true;
}

void printer() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {

			if (mines[y][x] != MINE) {
				cout << " " << mines[y][x];
			}

			else {
				cout << " *";
			}
		}
		cout << endl;
	}
}

void printer2() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {

			if (mines[y][x] != MINE) {
				if (opened[y][x] == true) {
					cout << " " << mines[y][x];
				}

				else {
					cout << " -";
				}
			}

			else {
				if (opened[y][x] == true) {
					cout << " *";
				}

				else {
					cout << " -";
				}
			}
		}
		cout << endl;
	}
}

void putMine() {
	int y = rand() % BOARD_SIZE;
	int x = rand() % BOARD_SIZE;
	mines[y][x] = MINE;
}

void reset() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			opened[y][x] = false;
		}
	}
}

void fail() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			opened[y][x] = true;
		}
	}
	clrscr();
	printer2();
	cout << endl;
	setColor(RED);
	cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$        /$$$$$$   /$$$$$$  /$$$$$$$$" << endl;
	cout << "|  $$   /$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$__  $$| $$_____/" << endl;
	cout << " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$      | $$  \\ $$| $$  \\__/| $$      " << endl;
	cout << "  \\  $$$$/ | $$  | $$| $$  | $$      | $$      | $$  | $$|  $$$$$$ | $$$$$   " << endl;
	cout << "   \\  $$/  | $$  | $$| $$  | $$      | $$      | $$  | $$ \\____  $$| $$__/   " << endl;
	cout << "    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \\ $$| $$      " << endl;
	cout << "    | $$   |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/| $$$$$$$$" << endl;
	cout << "    |__/    \\______/  \\______/       |________/ \\______/  \\______/ |________/" << endl;
	setColor(WHITE);
}

void win() {
	clrscr();
	cout << "you win" << endl;
}

void open(int x, int y) {
	if (!isInRange(x, y) || opened[y][x] || mines[y][x] == MINE) {
		return;
	}
	opened[y][x] = true;
	if (mines[y][x] != NO_MINES) {
		return;
	}
	open(x - 1, y - 1);
	open(x, y - 1);
	open(x + 1, y - 1);
	open(x - 1, y);
	open(x + 1, y);
	open(x - 1, y + 1);
	open(x, y + 1);
	open(x + 1, y + 1);
}

void game() {
	setColor(WHITE);
	srand(time(NULL));
	clrscr();
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			mines[y][x] = 0;
		}
	}

	for (int i = 0; i < NUM_MINES; i++) {
		putMine();
	}

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (mines[y][x] != MINE) {
				mines[y][x] = MinesChecker(x, y);
			}
		}
	}

	//printer();
	reset();

	opened[7][8] = false;

	printer2();
	gotoxy(1, 0);


	bool done = false;
	while (!done) {
		char t = getch();
		if (t == 's') {
			gotoxy(wherex(), wherey() + 1);
		}
		if (t == 'w') {
			gotoxy(wherex(), wherey() - 1);
		}
		if (t == 'a') {
			gotoxy(wherex() - 2, wherey());
		}
		if (t == 'd') {
			gotoxy(wherex() + 2, wherey());
		}
		if (t == ' ') {
			if (mines[wherey()][(wherex() - 1) / 2] == MINE) {
				done = true;
			}
			else {
				open((wherex() - 1) / 2, wherey());
				if (isWin() == true) {
					win();
				}
				else {
					int currentX = wherex();
					int currentY = wherey();
					clrscr();
					printer2();
					gotoxy(currentX, currentY);
				}
			}



		}
	}
	fail();
	getch();
}

void welcome() {
	cout << "this game is called Mines." << endl;
	cout << "the rules are simple:" << endl;
	cout << "you move with A D S W." << endl << "and you open with Space." << endl;
	cout << "if you opened a Mine, you failed" << endl;
	cout << "if you didn't opened a mine, there will be a number." << endl;
	cout << "this number means how many mines there are near to this number" << endl;
	cout << "you win if you opened all the numbers" << endl << endl << endl;
	cout << "press any key to continue...";
}

void main() {
	welcome();
	getch();
	game();
}
	

