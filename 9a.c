// Program in C to implement double ended queue ADT using (a) Array

#include<stdio.h>

#define SIZE 10000
int q[SIZE];
int front = -1, back = -1;

void push_front(int v) {
    if(front==-1 && back==-1) {
        front++; back++;
        q[front] = v;
    }
    else if(front-back==1 || back-front==SIZE-1)
        printf("\nDequeue Overflow!\n");
    else {
        if(front==0) {
            front=SIZE-1;
            q[front] = v;
        }
        else
            q[--front] = v;
    }
}

void push_back(int v) {
    if(front==-1 && back==-1) {
        front++; back++;
        q[front] = v;
    }
    else if(front-back==1 || back-front==SIZE-1)
        printf("\nDequeue Overflow!\n");
    else {
        if(back==SIZE-1) {
            back=0;
            q[back] = v;
        }
        else
            q[++back] = v;
    }
}

void pop_front()
{
    if(front==-1 && back==-1) {
        printf("\nDeque Underflow!\n");
    }
    else if(front==back) {
        printf("\n%d popped\n", q[front]);
        front = back = -1;
    }
    else {
        printf("\n%d popped\n", q[front]);
        front = (front+1)%SIZE;
    }
}

void pop_back()
{
    if(front==-1 && back==-1) {
        printf("\nDeque Underflow!\n");
    }
    else if(front==back) {
        printf("\n%d popped\n", q[back]);
        front = back = -1;
    }
    else {
        printf("\n%d popped\n", q[back]);
        back = (back-1+SIZE)%SIZE;
    }
}

void is_empty()
{
    if(front==-1 && back==-1)
        printf("\nDequeue is empty\n");
    else
        printf("\nDequeue is not empty\n");
}

void size()
{
    if(front==-1 && back==-1)
        printf("\nSize: 0\n");
    else printf("\nSize: %d\n", (back-front+SIZE)%SIZE+1);
}

void display()
{
    if(front==-1 && back==-1) {
        printf("\nDeque is Empty!\n");
        return;
    }
    printf("\nDequeue is:\n");
    if(back>front) {
        for (int i = front; i <= back; i++)
            printf("%d ", q[i]);
    }
    else {
        for (int i = front; i <= SIZE-1; i++)
            printf("%d ", q[i]);
        for (int i = 0; i <= back; i++)
            printf("%d ", q[i]);
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
                size();
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
