#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void printList(struct Node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

void enqueue(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        temp->data = value;
        temp->next = NULL;
        if (f == NULL)
        {
            f = r = temp;
        }
        else
        {
            r->next = temp;
            r = temp;
        }
    }
}

void dequeue()
{
    int value = -1;
    if (f == NULL)
    {
        printf("Queue Underflow\n");
    }
    struct Node *temp = f;
    f = f->next;
    value = temp->data;
    free(temp);
    printf("Dequeuing Element : %d\n", value);
}

int main()
{
    enqueue(21);
    enqueue(22);
    enqueue(23);
    enqueue(24);
    dequeue();
    dequeue();
    printList(f);
    return 0;
}
