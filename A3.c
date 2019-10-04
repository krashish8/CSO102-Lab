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

void insert (Q, x) {
    push (S1, x);
}

void delete (Q) {
    if (stack-empty (S2))
        if(stack-empty (S1)) {
            printf("Q is empty");
            return;
        }
    else while (!(stack-empty(S1))) {
        x = pop (S1);
        push (S2, x);
    }
    x = pop (S2);
}

