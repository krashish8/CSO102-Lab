/* Traversing elements, Adding n elements from keyboard, display, search, insert_front, insert_end, insert_pos, insert_asc, delete */
#include<stdio.h>       // iostream.h is for c++ only
#include<stdlib.h>      // For malloc

struct node
{
    int data;
    struct node* next;
};

void traverse (struct node *head)
{
    struct node *p = head;
    while (p!=NULL)
    {
        printf("%d",(p->data));
        p = p->next;
    }
}

// Whenever we need to input elements, we need to dynamically allocate memory for a node
// Just after dynamic allocation, we should store the value of data and next for the node.
void inputting (int n)
{
    struct node *head = NULL, *p, *prev;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d",&num);
        struct node *p;
        p = (struct node*) malloc(sizeof(struct node));
        p->data = num;
        if(head==NULL)
            head = p;
        else {
            prev->next = p;
        }
        prev = p;
    }
}

void display (struct node *head)
{
    struct node *p = head;
    while (p!=NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}

struct node *search (struct node *head, int s)
{
    struct node *p = head;
    while (p!=NULL)
    {
        if(p->data==s) return p;
        p = p->next;
    }
    return p;
}
struct node *insert_front (struct node *head, int n)
{
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->data = n;
    p->next = head;
    return p;
};

struct node *insert_end(struct node *head, int n)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL; // storing data and next in node p
    struct node *q = head;
    if(head==NULL) return p;
    while (q->next!=NULL)
        q=q->next;
    q->next = p;
    return head;
};

struct node *insert_asc (struct node *head, int n)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    struct node *q=head, *prev=q;
    while (q!=NULL)
    {
        if(q->data >= n)
        {
            if(q==head) {p->next = head; return p;}
            prev->next = p;
            p->next = q;
            return head;
        }
        prev = q;
        q = q->next;
    }
    if(head==NULL) {head = p; return p;}
    if(q==NULL) {
        prev->next = p;
        return head;
    }
};


struct node *delete (struct node *head, int value)
{
    struct node *p=head, *prev=p;
    while (p!=NULL)
    {
        if(p->data==value) {
            if(p==head) head = p->next;
            else prev->next = p->next;
            p->next = NULL;
            free(p);
            return head;
        }
        else {
            prev = p;
            p = p->next;
        }
    }
    return p;
};

void main()
{
    int n;
}
