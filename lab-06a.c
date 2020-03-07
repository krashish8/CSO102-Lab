/* Program to implement two stack using 1-D array where the total size of both stacks are fixed
   but individual size may differ (use dynamics memory allocation and structure concepts) */
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10000

struct DoubleStack{
    int *a;
    int top1, top2, size;
};

struct DoubleStack* init()
{
    struct DoubleStack* st = (struct DoubleStack*) malloc(sizeof(struct DoubleStack));
    st->top1 = -1;
    st->top2 = SIZE;
    st->size = SIZE;
    st->a = (int*) malloc (sizeof(int)*SIZE);
    return st;
}

void push1(struct DoubleStack *st, int n){
    if(st->top1 < st->top2-1)
    {
        st->top1++;
        st->a[st->top1] = n;
        printf("%d pushed\n", n);
    }
    else
    {
        printf("Stack1 Overflow\n");
    }

}

void push2(struct DoubleStack *st, int n){
    if(st->top1 < st->top2-1)
    {
        st->top2--;
        st->a[st->top2] = n;
        printf("%d pushed\n", n);
    }
    else
    {
        printf("Stack2 Overflow\n");
    }

}

void pop1(struct DoubleStack *st)
{
    if(st->top1 >= 0)
    {
        printf("%d popped\n",st->a[st->top1]);
        st->top1--;
    }
    else
    {
        printf("Stack1 Underflow\n");
    }
}

void pop2(struct DoubleStack *st)
{
    if(st->top2 < st->size)
    {
        printf("%d popped\n",st->a[st->top2]);
        st->top2++;
    }
    else
    {
        printf("Stack2 Underflow\n");
    }
}

void top1 (struct DoubleStack* st)
{
    if(st->top1!=-1) printf("Top Element: %d\n",st->a[st->top1]);
    else printf("Stack1 is empty\n");
}

void top2 (struct DoubleStack* st)
{
    if(st->top2!=st->size) printf("Top Element: %d\n",st->a[st->top2]);
    else printf("Stack2 is empty\n");
}

void display1 (struct DoubleStack* st)
{
    for(int i = st->top1; i>=0; i--)
        printf("%d\n",st->a[i]);
}

void display2 (struct DoubleStack* st)
{
    for(int i = st->top2; i<10000; i++)
        printf("%d\n",st->a[i]);
}

int main()
{
    int ch, n, s;
    struct DoubleStack* st = init();
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    printf("\n");
    while(1) {
    switch (ch)
    {
    case 1:
        printf("Stack 1 or Stack 2: ");
        scanf("%d", &s);
        printf("Enter Element to push: ");
        scanf("%d", &n);
        if(s==1) push1(st, n);
        else if(s==2) push2(st, n);
        break;
    case 2:
        printf("Stack 1 or Stack 2: ");
        scanf("%d", &s);
        if(s==1) pop1(st);
        else if(s==2) pop2(st);
        break;
    case 3:
        printf("Stack 1 or Stack 2: ");
        scanf("%d", &s);
        if(s==1) top1(st);
        else if(s==2) top2(st);
        break;
    case 4:
        printf("Stack 1 or Stack 2: ");
        scanf("%d", &s);
        if(s==1) display1(st);
        else if(s==2) display2(st);
        break;
    case 5:
        return 0;
    }
    printf("Enter your choice: ");
    scanf("%d", &ch);
    }
}
