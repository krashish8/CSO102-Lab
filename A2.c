#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;


node *removeDup (node *head) {
    node *p = head, *prev;
    while (p != NULL) {
        if (p == head) {
            prev = p;
            p = p -> next;
        }
        else if (prev->data != p->data) {
            prev -> next = p;
            prev = p;
            p = p -> next;
        }
        else if(prev -> data == p->data) {
            node *temp = p;
            p = p -> next;
            free(temp);
        }
    }
    return head;
}

int main ()
{

}


