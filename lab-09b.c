// Program in C to implement double ended queue ADT using (b) Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10000

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* front = NULL;
node* back = NULL;
int size = 0;

void push_front(int v) {
    node* new_n = (node*) malloc(sizeof(node));
    new_n -> data = v;
    new_n -> left = NULL;
    new_n -> right = NULL;
    if(front==NULL && back==NULL) {
        front = new_n;
        back = new_n;
        size++;
    }
    else if(size==SIZE)
        printf("\nDequeue Overflow!\n");
    else {
        front -> left = new_n;
        new_n -> right = front;
        size++;
    }
    front = new_n;
}

void push_back(int v) {
    node* new_n = (node*) malloc(sizeof(node));
    new_n -> data = v;
    new_n -> left = NULL;
    new_n -> right = NULL;
    if(front==NULL && back==NULL) {
        front = new_n;
        back = new_n;
        size++;
    }
    else if(size==SIZE)
        printf("\nDequeue Overflow!\n");
    else {
        new_n -> left = back;
        back -> right = new_n;
        size++;
    }
    back = new_n;
}

void pop_front()
{
    if(front==NULL && back==NULL) {
        printf("\nDequeue Underflow!\n");
    }
    else if(size==1) {
        printf("\n%d popped\n", front->data);
        front = back = NULL;
        size--;
    }
    else {
        printf("\n%d popped\n", front->data);
        node* temp = front;
        front = front -> right;
        front -> left = NULL;
        free(temp);
        size--;
    }
}

void pop_back()
{
    if(front==NULL && back==NULL) {
        printf("\nDeque Underflow!\n");
    }
    else if(size==1) {
        printf("\n%d popped\n", back->data);
        front = back = NULL;
        size--;
    }
    else {
        printf("\n%d popped\n", back->data);
        node* temp = back;
        back = back -> left;
        back -> right = NULL;
        free(temp);
        size--;
    }
}
void is_empty()
{
    if(front==NULL && back==NULL)
        printf("\nDequeue is empty\n");
    else
        printf("\nDequeue is not empty\n");
}

void dispSize()
{
    printf("\nSize: %d\n", size);
}

void display()
{
    if(size==0) {
        printf("\nDeque is Empty!\n");
        return;
    }
    printf("\nDequeue is:\n");
    node *p = front;
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->right;
    }
    printf("\n");
}


int main ()
{
    printf("\n");
    printf(" ---------------------\n");
    printf("|   1. Push (Front)   |\n");
    printf("|   2. Push (Back)    |\n");
    printf("|   3. Pop (Front)    |\n");
    printf("|   4. Pop (Back)     |\n");
    printf("|   5. Is Empty?      |\n");
    printf("|   6. Size           |\n");
    printf("|   7. Display        |\n");
    printf("|   8. Exit           |\n");
    printf(" ---------------------\n");
    int ch=0;
    int v;
    while (ch!=8) {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &v);
                push_front(v);
                break;
            case 2:
                printf("\nEnter the element to push: ");
                scanf("%d", &v);
                push_back(v);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_back();
                break;
            case 5:
                is_empty();
                break;
            case 6:
                dispSize();
                break;
            case 7:
                display();
                break;
            case 8:
                break;
            default:
                printf("\nEnter correct choice!\n");
        }
    }

}
