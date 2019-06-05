/* Main.c */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // Sleep 함수 사용하기 위해 포함 (sleep 함수 n000을 입력하면 n초만큼 후 다음 동작 실행)
#include "Contact.h"
#include "Menu.h"
#include "Control.h"


int main(void)
{
	//system("mode con: cols=84 lines=20");      // 콘솔 화면창 조절 cols = 가로 lines = 세로
	system("mode con: cols=50 lines=30");      // 콘솔 화면창 조절 cols = 가로 lines = 세로
	CONTACT *contacts = NULL; // CONTACT 구조체 배열의 주소
	int max_contacts = 0; // 최대 저장 가능한 연락처의 개수
	int contacts_cnt = 0; // 지금까지 등록된 연락처의 개수
	int menu = 0;
	
	CoverPage();
	MainPage();
	MainMenu();

	while (1) {
		//int h = KeyControl();
		printf("%d", KeyControl());
	}
	
	do {
		printf("최대 연락처의 개수를 입력하세요 : ");
		
		scanf("%d", &max_contacts);
		/*
		if (scanf("%d", &max_contacts) == 0) 에서 코드 분리, 이대로 넣으면 코드 씹힘 20190604 kdj
		*/
		if (max_contacts == 0)
		{
			printf("잘못 입력하셨습니다.\n");
			//Sleep(2000); // 2초 대기
			CLEAR_INPUT();
			getchar();
			system("cls"); //화면 지움
			continue;
		}
	} while (max_contacts <= 0);

	contacts = Initialize(max_contacts);
	if (contacts == NULL)
	{
		printf("동적 메모리 할당 실패\n");
		exit(1);
	}

	while (1)
	{
		menu = SelectMenu();
		if (menu == QUIT_PROGRAM)
			break;
		switch (menu)
		{
		case ADD_CONTACT:
			if (AddContactInfo(contacts, max_contacts, &contacts_cnt) != 0)
			{
				printf("연락처가 추가되었습니다.\n");
			}
			break;
		case LIST_BY_NAME:
			ListByName(contacts, contacts_cnt);
			break;
		}
	}
}