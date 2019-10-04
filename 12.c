/*
Program to check whether two trees are symmetric or not and also find that given tree is BST or not
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
}node;

node* newNode(int value) {
    node* n = (node*) malloc(sizeof(node));
    n -> data = value;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

int checkSym (node *a, node *b) {
    if (a == NULL && b == NULL) return 1;
    if ((a == NULL && b != NULL) || (b == NULL && a != NULL)) return 0;
    if (a -> data != b -> data) return 0;
    return checkSym (a -> left, b -> right) && checkSym (a -> right, b -> left);
}

int arr[1000], i;

void inorder (node *root) {
    if (root == NULL) return;
    inorder (root -> left);
    arr[i] = root -> data;
    i++;
    inorder (root -> right);
}

int checkBST (node *root) {
    i = 0;
    inorder(root);
    for (int j = 0; j < i-1; j++) {
        if(arr[j] > arr[j+1]) return 0;
    }
    return 1;
}


int main() {
    // For checking symmetry
    node* root1 = newNode(10);
    root1 -> left = newNode(8);
    root1 -> right = newNode(15);
    root1 -> left -> left = newNode(2);
    root1 -> left -> right = newNode(5);

    node* root2 = newNode(10);
    root2 -> left = newNode(15);
    root2 -> right = newNode(8);
    root2 -> right -> left = newNode(5);
    root2 -> right -> right = newNode(2);

    //For checking BST
    node *root = newNode(10);
    root -> left = newNode(5);
    root -> left -> left = newNode(2);
    root -> left -> right = newNode(7);
    root -> right = newNode(12);
    root -> right -> left = newNode(11);
    printf("--------------------------\n");
    printf("| 1. Check for symmetry   |\n");
    printf("| 2. Check for BST        |\n");
    printf("| 3. Exit                 |\n");
    printf("--------------------------\n");
    int ch;
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &ch);
    while (ch!=3) {
        switch (ch) {
            case 1: if (checkSym(root1, root2))
                        printf("The tree is Symmetric\n");
                    else
                        printf("The tree is not Symmetric\n");
                    break;
            case 2: if(checkBST(root))
                        printf("The tree is a BST\n");
                    else
                        printf("The tree is not a BST\n");
                    break;
            case 3: break;
            default: printf("\nINVALID CHOICE!\n");
        }
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
    }
}
