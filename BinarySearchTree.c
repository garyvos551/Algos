#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *createNode(int data)
{
    struct tree *n = (struct tree *)malloc(sizeof(struct tree));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct tree *n)
{
    if (n != NULL)
    {
        printf("%d ", n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
}

void postOrder(struct tree *n)
{
    if (n != NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        printf("%d ", n->data);
    }
}

void inOrder(struct tree *n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
}

int isBST(struct tree *n)
{
    static struct tree *prev = NULL;
    if (n != NULL)
    {
        if (!isBST(n->left))
        {
            return 0;
        }
        if (prev != NULL && n->data <= prev->data)
        {
            return 0;
        }
        prev = n;
        return isBST(n->right);
    }
    return 1;
}

struct tree *search(struct tree *n, int value)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (n->data == value)
    {
        return n;
    }
    else if (value < n->data)
    {
        search(n->left, value);
    }
    else
    {
        search(n->right, value);
    }
}

struct tree *iterativeSearch(struct tree *n, int value)
{
    while (n != NULL)
    {
        if (value == n->data)
        {
            return n;
        }
        else if (value < n->data)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }
    return NULL;
}

void insert(struct tree *n, int value)
{
    struct tree *prev = NULL;
    while (n != NULL)
    {
        prev = n;
        if (value == n->data)
        {
            printf("Cannot insert a duplicate number\n");
            return;
        }
        else if (value < n->data)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }
    struct tree *new = createNode(value);
    if (value < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct tree *inOrderPre(struct tree *n)
{
    struct tree *temp = n;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct tree *delete (struct tree *n, int value)
{
    if (value < n->data)
    {
        n->left = delete (n->left, value);
    }
    else if (value > n->data)
    {
        n->right = delete (n->right, value);
    }
    else
    {
        if (n->left == NULL)
        {
            struct tree *temp = n->right;
            free(n);
            return temp;
        }
        else if (n->right == NULL)
        {
            struct tree *temp = n->left;
            free(n);
            return temp;
        }
        struct tree *temp = inOrderPre(n->right);
        n->data = temp->data;
        n->right = delete (n->right, temp->data);
    }
}

int main()
{
    struct tree *root = createNode(5);
    struct tree *c1 = createNode(3);
    struct tree *c2 = createNode(6);
    struct tree *c3 = createNode(2);
    struct tree *c4 = createNode(4);
    root->left = c1;
    root->right = c2;
    c1->left = c3;
    c1->right = c4;
    /*

         5
        / \
       3   6
      / \
     2   4

    */
    // inOrder(root);
    // if (isBST(root))
    // {
    //     printf("It is a BST\n");
    // }
    // else
    //     printf("Not a BST\n");

    // struct tree *temp = search(root, 4);
    // struct tree *temp = iterativeSearch(root, 4);
    // if (temp != NULL)
    // {
    //     printf("Found : %d", temp->data);
    // }
    // else
    //     printf("Not Found");

    // inOrder(root);
    // insert(root, 9);
    // printf("\n");
    // inOrder(root);

    inOrder(root);
    delete(root, 4);
    printf("\n");
    inOrder(root);
    return 0;
}
