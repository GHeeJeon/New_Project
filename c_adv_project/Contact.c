/* Contact.c */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contact.h"
#include "menu.h"

CONTACT* Initialize(int totalCnt) {
	// ����ü �����͸� ����ü ũ�⸸ŭ ����
	CONTACT *p = (CONTACT*)malloc(sizeof(CONTACT) * totalCnt);

	// ����ü�� ���� ��������� �ʱ�ȭ
	if (p != NULL)
		memset(p, 0, sizeof(CONTACT) * totalCnt);

	/* ���� �ڵ�� ����
	for (int i = 0; i < totalCnt; i++) {
		*(p  + i)->name = '\0';
		*(p  + i)->phone = '\0';
	}
	*/

	return p;
}

int AddContactInfo(CONTACT *contacts, int maxCnt, int *pCurCnt) {
	CONTACT *p = NULL;
	int ring;

	if (maxCnt == *pCurCnt)
		return 0;


	p = &contacts[*pCurCnt];
	printf("\n��    �� : ");
	fgets(p->name, MAX_STR, stdin);
	p->name[strlen(p->name) - 1] = '\0';  // �ٹٲ� ���� ����
	printf("��ȭ��ȣ : ");
	fgets(p->phone, MAX_STR, stdin);
	p->phone[strlen(p->phone) - 1] = '\0'; // �ٹٲ� ���� ����

	do {
		printf("[1.��ȭ�� 2.�ǾƳ� 3.������ 4.����] ���Ҹ� ���� : ");
		scanf("%d", &ring);
		CLEAR_INPUT();
	} while (ring < 0 || ring > 4);
	p->ring = ring - 1;

	(*pCurCnt)++;
	return *pCurCnt;
}

void ListByName(CONTACT *contacts, int cnt)
{
	if (cnt == 0)
	{
		printf("����� ������ �����ϴ�.\n");
		return;
	}
	qsort(contacts, cnt, sizeof(CONTACT), CompareByName);
	PrintAllContacts(contacts, cnt);
}

void PrintAllContacts(const CONTACT *contacts, int cnt)
{
	int i;
	const char* ringtones[] = {
		"��ȭ��", "�ǾƳ�", "������", "����"
	};

	printf("\n==================================\n");
	printf(" �̸�        ��ȭ��ȣ     ���Ҹ�\n");
	printf("==================================\n");
	for (i = 0; i < cnt; i++)
	{
		printf("%-10s %-14s %s\n", contacts[i].name, contacts[i].phone,
			ringtones[contacts[i].ring]);
	}
	printf("==================================\n");
}

int CompareByName(const void* e1, const void* e2)
{
	const CONTACT *p1 = (const CONTACT*)e1;
	const CONTACT *p2 = (const CONTACT*)e2;
	return strcmp(p1->name, p2->name);
	// �̺κ��� �Ʒ��� ����
	/*
	if (p1->name < p2->name) return -1;
	else if (p1->name > p2->name) return 1;
	else return 0;
	*/
}

