/*C program that uses stack operations to convert given infix expression into its postfix equivalent.
  Implement the stack using an array. */
#include<stdio.h>
#define SIZE 10000

char st[SIZE];
int top = -1;

void push (char n)
{
    if(top == SIZE-1) printf("Stack Overflow\n");
    else st[++top] = n;
}

void pop ()
{
    if(top == -1) printf("Stack Underflow\n");
    else top--;
}

int isempty()
{
    if(top==-1) return 1;
    else return 0;
}

int priority (char ch) {
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='%' || ch=='/' || ch=='*') return 2;
    else if(ch=='^') return 3;
    else return 0;
}

int main ()
{
    char s[1000];
    int i;
    printf("Enter the infix expression: ");
    scanf("%s",s);
    printf("Equivalent postfix expression: ");
    for (i = 0; s[i]!='\0'; i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            printf("%c", s[i]);
        else if(s[i]=='(')
                push(s[i]);
        else if(s[i]==')')
        {
            while (!isempty() && st[top] !='(') {
                printf("%c", st[top]);
                pop();
            }
            if(!isempty()) pop();
        }
        else if(isempty())
            push(s[i]);
        else if(priority(s[i]) > priority(st[top]))
            push(s[i]);
        else {
            while (!isempty() && (st[top]!='(' && priority(s[i]) <= priority(st[top]))){
                printf("%c", st[top]);
                pop();
            }
            push(s[i]);
        }
    }

    while (!isempty()) {
        printf("%c", st[top]);
        pop();
    }
    printf("\n");
}
