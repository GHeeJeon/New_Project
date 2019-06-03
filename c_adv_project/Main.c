/* Main.c */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
#include "Menu.h"

int main(void)
{
	CONTACT *contacts = NULL; // CONTACT 구조체 배열의 주소
	int max_contacts = 0; // 최대 저장 가능한 연락처의 개수
	int contacts_cnt = 0; // 지금까지 등록된 연락처의 개수
	int menu = 0;
	do {
		printf("최대 연락처의 개수를 입력하세요 : ");
		if (scanf("%d", &max_contacts) == 0)
		{
			printf("잘못 입력하셨습니다.\n");
			CLEAR_INPUT();
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