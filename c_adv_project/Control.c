/* FileIO.c */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <windows.h> 
#include "Control.h"

int KeyControl() {
	
	char inputKey = '\0';
	inputKey = _getch();
	
	if (inputKey == -32) {
		inputKey = _getch();

		switch (inputKey) {
		case UP:
			return UP;
			break;
		case LEFT:
			return LEFT;
			break;
		case RIGHT:
			return RIGHT;
			break;
		case DOWN:
			return DOWN;
			break;
		default:
			return -1;
			break;
		}
	}
	else if (inputKey == ENTER)
		return ENTER;
	//return 0;
}




void CoverPage() {
	printf("\n\n\n\n\n              **********");
	printf("\n            **          **");
	printf("\n           **            **");
	printf("\n          **              **");
	printf("\n         **                **");
	printf("\n         **                **");
	printf("\n         **                **");
	printf("\n          **              **");
	printf("\n           **            **");
	printf("\n            **          **");
	printf("\n              **********");



	printf("\n\n\n        Press Enter Key To Start");
	getchar();
	system("cls");
}

void MainPage() {
	printf("\n\n\n\n");
	printf("\n   ####  ###  ##  # #####   #    #### #####  ###");
	printf("\n  ##    #   # # # #   #    # #  ##      #   ##");
	printf("\n  ##    #   # #  ##   #   ##### ##      #     ##");
	printf("\n   ####  ###  #  ##   #   #   #  ####   #   ###");
	printf("\n           ");
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos); // �ش� �����ǿ� �ܼ��� ��ġ
}

void MainMenu() {
	gotoxy(24 - 2, 12);
	printf("> �� �� �� ��");
	gotoxy(24, 13);
	printf(" �� �� �� ��");
	gotoxy(24, 14);
	printf("   ��  ��   ");
}



