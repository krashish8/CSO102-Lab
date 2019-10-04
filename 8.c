/* Program that uses functions to perform the following:
a) Create a singly linked list of integers
b) Delete a given integer from the above list
c) Display the contents of the above list after deletion
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* createList (node* head) {
    node *p, *new_n;
    printf("\nEnter the elements to insert (-1 to Exit): \n");
    int v;
    scanf("%d", &v);
    while (v!= -1)
    {
        new_n = (node*) malloc(sizeof(node));
        new_n -> data = v;
        new_n -> next = NULL;

        if(head==NULL)
        {
            head = new_n;
        }
        else
        {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = new_n;
        }
        scanf("%d", &v);
    }
    printf("Linked List Created!\n");
    return head;

};

node* delete (node* head, int v) {
    node *p, *prev;
    p = head, prev = head;
    while (p!=NULL) {
        if(p->data == v) {
            if(p==head) head = head->next;
            else prev->next = p->next;
            free(p);
            printf("%d deleted\n", v);
            return head;
        }
        else {
            prev = p;
            p = p->next;
        }
    }
    printf("%d not found!\n", v);
    return head;
};

void displayList (node* head) {
    node *p = head;
    printf("\nLinked List is: \n");
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
};

int main ()
{
    node *head = NULL;
    int ch = 0;
    printf("\n");
    printf(" -----------------\n");
    printf("|   1. CREATE     |\n");
    printf("|   2. DELETE     |\n");
    printf("|   3. DISPLAY    |\n");
    printf("|   4. EXIT       |\n");
    printf(" -----------------\n");
    while (ch!=4) {
        printf("\nENTER YOUR CHOICE: ");
        int v;
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = createList(head);
                break;
            case 2:
                printf("\nEnter the element to delete: ");
                scanf("%d", &v);
                head = delete(head, v);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                break;
            default:
                printf("\nEnter correct choice!\n");
        }
    }
}
