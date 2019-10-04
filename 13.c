/*
Program to implement all the functions of a dictionary (ADT) using hashing
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#define N 20

typedef struct node {
	char key[N], value[N];
	struct node *next;
}node;

node *root[SIZE];

int hash (char key[]) {
	int s = 0;
	for (int i = 0; key[i] != '\0'; i++)
		s = s + key[i]*key[i];
	return s % SIZE;
}

void insert(char k[], char v[]) {
	int i = hash(k);
	node *n = (node*) malloc(sizeof(node));
	strcpy(n -> key, k);
	strcpy(n -> value, v);
	n -> next = NULL;
	if (root[i] == NULL) {
		root[i] = n;
	}
	else {
		node *p = root[i];
		while (p -> next != NULL)
			p = p -> next;
		p -> next = n;
	}
	printf("%s : %s inserted\n", k, v);
}

void search(char k[]) {
	int i = hash(k);
	node *p = root[i];
	while (p!=NULL) {
		if(strcmp(p->key, k) == 0) {
			printf("Found! - %s : %s\n", p->key, p->value);
			return;
		}
		else p = p->next;
	}
	printf("Not Found!\n");
}

void del(char k[]) {
	int i = hash(k);
	if(root[i]==NULL) {
		printf("Not Found!\n");
		return;
	}
	if (strcmp(root[i]->key, k) == 0) {
		printf("%s : %s is deleted\n", root[i]->key, root[i]->value);
		node *temp = root[i];
		root[i] = root[i] -> next;
		free(temp);
		return;
	}
	node *p = root[i], *prev;
	while(p!=NULL) {
		if(strcmp(p->key, k) == 0) {
			prev -> next = p -> next;
			free(p);
			printf("%s : %s is deleted\n", p->key, p->value);
			return;
		}
		prev = p;
		p = p->next;
	}
	printf("Not Found!\n");
}

void display() {
	for (int i = 0; i < SIZE; i++) {
		if(root[i]==NULL) continue;
		node *p = root[i];
		while (p != NULL) {
			printf("%s : %s\n", p->key, p->value);
			p = p->next;
		}
	}
}

int main () {
	int ch;
	char k[N], v[N];
	printf("--------------\n");
	printf("| 1. Insert   |\n");
	printf("| 2. Delete   |\n");
	printf("| 3. Search   |\n");
	printf("| 4. Display  |\n");
	printf("| 5. Exit     |\n");
	printf("--------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d", &ch);
	while (ch!=5) {
		switch(ch) {
			case 1: printf("Enter key: ");
					scanf("%s", k);
					printf("Enter value: ");
					scanf("%s", v);
					insert(k, v);
					break;
			case 2: printf("Enter the key to delete: ");
					scanf("%s", k);
					del(k);
					break;
			case 3: printf("Enter the key to search: ");
					scanf("%s", k);
					search(k);
					break;
			case 4: display();
					break;
			case 5: break;
			default: printf("\nINVALID CHOICE!\n");
		}
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d", &ch);
	}
}
