// C program that uses functions to perform the following:
// (a) Create a binary search tree of characters
// (b) Traverse the binary tree recursively in postorder, preorder and inorder

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node *left, *right;
}node;

node* insert(node* root, char v)
{
    node *p = (node*) malloc(sizeof(node));
    p -> data = v;
    p -> left = NULL;
    p -> right = NULL;
    if (root == NULL) {
        return p;
    }
    node *pp, *q = root;
    while (q != NULL) {
        pp = q;
        if(v < q->data)
            q = q->left;
        else
            q = q->right;
    }
    if (v > pp->data)
        pp->right = p;
    else
        pp->left = p;
    return root;
}

void preorder (node *root)
{
    if(root != NULL)
    {
        printf("%c ", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

void inorder (node *root)
{
    if(root != NULL)
    {
        inorder (root->left);
        printf("%c ", root->data);
        inorder (root->right);
    }
}

void postorder (node *root)
{
    if(root != NULL)
    {
        postorder (root->left);
        postorder (root->right);
        printf("%c ", root->data);
    }
}

int main ()
{
    node *root = NULL;
    printf("\n");
    printf(" -------------------\n");
    printf("|   1. Insert       |\n");
    printf("|   2. Preorder     |\n");
    printf("|   3. Inorder      |\n");
    printf("|   4. Postorder    |\n");
    printf("|   5. Exit         |\n");
    printf(" -------------------\n");
    int ch;
    char v;
    do {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        char temp;
        scanf("%c", &temp);
        switch (ch) {
            case 1:
                printf("\nEnter the character to insert: ");
                scanf("%c", &v);
                root = insert(root, v);
                break;
            case 2:
                printf("\nPreorder traversal of BST:\n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nInorder traversal of BST:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder traversal of BST:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                break;
        }
    }while(ch!=5);
}
