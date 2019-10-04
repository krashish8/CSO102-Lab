#include<stdio.h>
#include<stdlib.h>
struct double_stack{
	int *a;
	int top1 = -1;
	int top2 = 100;
};
void push1(struct double_stack *st, int n){
	(*st).top1++;
	(*st).a[(*st).top1] = n;
}
void push2(struct double_stack *st, int n){
	(*st).top2--;
	(*st).a[(*st).top2] = n;
}
void pop1(struct double_stack *st)
{
	(*st).top1--;
}
void pop2(struct double_stack *st)
{
	(*st).top2++;
}
int main()
{
	struct double_stack st;
	st.a = (int *)(malloc(sizeof(int)*100));
	push1(&st,5);
	push2(&st,2);
	printf("%d",st.a[st.top2]);
}
