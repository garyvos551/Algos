#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    int height;
};

int getHeight(struct tree *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct tree *createNode(int key)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct tree *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct tree *rightRotate(struct tree *y)
{
    struct tree *x = y->left;
    struct tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct tree *leftRotate(struct tree *x)
{
    struct tree *y = x->right;
    struct tree *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct tree *insert(struct tree *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct tree *n)
{
    if (n != NULL)
    {
        printf("%d ", n->key);
        preOrder(n->left);
        preOrder(n->right);
    }
}

int main()
{
    struct tree *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}
