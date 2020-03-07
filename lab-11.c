// To implement Priority Queue using Binary Heap

#include<stdio.h>
#define SIZE 10000

int tree[SIZE], N = 0;

void insert_heap(int item)
{
    N++;
    int pos = N;
    while(pos > 1) {
        int par = pos / 2;
        if( item <= tree[par]) {
            tree[pos] = item;
            //printf("%d", pos);
            return;
        }
        tree[pos] = tree[par];
        pos = par;
    }
    tree[1] = item;
}

void del_max()
{
    if(N==0) return;
    int max = tree[1];
    int last = tree[N];
    N--;
    int pos = 1;
    int left = pos + 1;
    int right = pos + 2;
    while (right <= N) {
        if(last >= tree[left] && last >= tree[right]) {
            tree[pos] = last;
            return;
        }
        if(tree[right] <= tree[left]) {
            tree[pos] = tree[left];
            pos = left;
        }
        else {
            tree[pos] = tree[right];
            pos = right;
        }
        left = 2*pos;
        right = 2*pos + 1;
    }
    if(left == N && last < tree[left])
        pos = left;
    tree[pos] = last;
}

void size()
{
    printf("Size of priority queue: %d\n", N);
}

void top()
{
    if(N==0) printf("Empty!\n");
    else printf("Top element: %d\n", tree[1]);
}

void display()
{
    while (N!=0) {
        printf("%d ", tree[1]);
        del_max();
    }
}

int main ()
{
    printf("\n");
    printf(" ---------------\n");
    printf("|   1. Push     |\n");
    printf("|   2. Pop      |\n");
    printf("|   3. Top      |\n");
    printf("|   4. Size     |\n");
    printf("|   5. Display  |\n");
    printf("|   6. Exit     |\n");
    printf(" ---------------\n");
    int ch, v;
    do {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &v);
                insert_heap(v);
                printf("%d inserted\n", v);
                break;
            case 2:
                if(N==0) printf("Priority Queue is empty!\n");
                else {
                    printf("%d popped\n", tree[1]);
                    del_max();
                }
                break;
            case 3:
                top();
                break;
            case 4:
                size();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
        }
    }while(ch!=6);
}
