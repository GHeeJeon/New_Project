/* Main.c */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // Sleep �Լ� ����ϱ� ���� ���� (sleep �Լ� n000�� �Է��ϸ� n�ʸ�ŭ �� ���� ���� ����)
#include "Contact.h"
#include "Menu.h"
#include "Control.h"


int main(void)
{
	//system("mode con: cols=84 lines=20");      // �ܼ� ȭ��â ���� cols = ���� lines = ����
	system("mode con: cols=50 lines=30");      // �ܼ� ȭ��â ���� cols = ���� lines = ����
	CONTACT *contacts = NULL; // CONTACT ����ü �迭�� �ּ�
	int max_contacts = 0; // �ִ� ���� ������ ����ó�� ����
	int contacts_cnt = 0; // ���ݱ��� ��ϵ� ����ó�� ����
	int menu = 0;
	
	CoverPage();
	MainPage();
	MainMenu();

	while (1) {
		//int h = KeyControl();
		printf("%d", KeyControl());
	}
	
	do {
		printf("�ִ� ����ó�� ������ �Է��ϼ��� : ");
		
		scanf("%d", &max_contacts);
		/*
		if (scanf("%d", &max_contacts) == 0) ���� �ڵ� �и�, �̴�� ������ �ڵ� ���� 20190604 kdj
		*/
		if (max_contacts == 0)
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			//Sleep(2000); // 2�� ���
			CLEAR_INPUT();
			getchar();
			system("cls"); //ȭ�� ����
			continue;
		}
	} while (max_contacts <= 0);

	contacts = Initialize(max_contacts);
	if (contacts == NULL)
	{
		printf("���� �޸� �Ҵ� ����\n");
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
				printf("����ó�� �߰��Ǿ����ϴ�.\n");
			}
			break;
		case LIST_BY_NAME:
			ListByName(contacts, contacts_cnt);
			break;
		}
	}
}