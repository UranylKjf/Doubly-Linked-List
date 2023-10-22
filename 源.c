#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Dnode {
	int data;
	struct Dnode* prev;
	struct Dnode* next;
}Dnode;

//����Ԫ�أ�˫����Ҫд��Ķ����϶࣬������ʡʱ��
Dnode* GetNewnode(int x){
	Dnode* newnode = (Dnode*)malloc(sizeof(Dnode));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

//ͷ�巨
void HeadInsert(Dnode** head, int x) {
	Dnode* newnode = GetNewnode(x);
	if (*head == NULL) {
		*head = newnode;
	}
	else {
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}

//β�巨
void TailInsert(Dnode** head, int x) {
	Dnode* newnode = GetNewnode(x);
	Dnode* temp = *head;
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
}

//ɾ��ָ��λ��Ԫ�� n��λ��
void Delete(Dnode** head,int n) {
	if (n == 1) {
		Dnode* temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else {
		Dnode* temp1 = *head;
		for (int i = 0; i < n-1; i++) {
			temp1 = temp1->next;
		}
		if (temp1->next == NULL) {
			(temp1->prev)->next = NULL;
		}
		else {
			(temp1->prev)->next = temp1->next;
			(temp1->next)->prev = temp1->prev;
			free(temp1);
		}
	}
}

//��ӡ����
void Print(Dnode* head) {
	printf("The List is:\n");
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("\n");
}

//��ת����
void Reverse(Dnode** head) {
	if (*head == NULL || (*head)->next == NULL) {
		return;
	}
	Dnode* temp = NULL, *curr = *head;
	while (curr != NULL) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	*head = temp->prev;

}


int main() {
	Dnode* head=NULL;
	TailInsert(&head, 5);
	TailInsert(&head, 6);
	TailInsert(&head, 7);
	Delete(&head, 3);
	Print(head);
	return 0;
}
