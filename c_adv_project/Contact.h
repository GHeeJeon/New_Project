/* Contact.h */
#ifndef CONTACT_H

#define CONTACT_H

#define MAX_STR 32

enum ringtone { old_phone, piano, marimba, harp };

typedef struct contact {
	char name[32]; // 이름
	char phone[32]; // 전화번호
	enum ringtone ring; // 벨소리
} CONTACT;

CONTACT* Initialize(int totalCnt);
int AddContactInfo(CONTACT *contacts, int maxCnt, int *pCurCnt);
void ListByName(CONTACT *contacts, int cnt);
void PrintAllContacts(const CONTACT *contact, int cnt);
int CompareByName(const void* e1, const void* e2);

#endif