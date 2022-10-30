#include <stdio.h>
#define n 5
int DEQueue[n];
int f = -1, r = -1;

void printQueue()
{
    int i = f;
    int j = 1;

    while (i != r + 1)
    {
        printf("Element %d : %d\n", j, DEQueue[i]);
        j++;
        i = (i + 1) % n;
    }
}

void enqueueFront(int data)
{
    if ((f == 0 && r == n - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        DEQueue[f] = data;
    }
    else if (f == 0)
    {
        f = n - 1;
        DEQueue[f] = data;
    }
    else
    {
        f--;
        DEQueue[f] = data;
    }
}

void enqueueRear(int data)
{
    if ((f == 0 && r == n - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        DEQueue[r] = data;
    }
    else if (r == n - 1)
    {
        r = 0;
        DEQueue[r] = data;
    }
    else
    {
        r++;
        DEQueue[r] = data;
    }
}

void dequeueFront()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r)
    {
        printf("Popped %d\n", DEQueue[f]);
        f = r = -1;
    }
    else if (f == n - 1)
    {
        printf("Popped %d\n", DEQueue[f]);
        f = 0;
    }
    else
    {
        printf("Popped %d\n", DEQueue[f]);
        f++;
    }
}

void dequeueRear()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r)
    {
        printf("Popped %d\n", DEQueue[r]);
        f = r = -1;
    }
    else if (r == 0)
    {
        printf("Popped %d\n", DEQueue[r]);
        r = n - 1;
    }
    else
    {
        printf("Popped %d\n", DEQueue[r]);
        r--;
    }
}

int main()
{
    enqueueRear(2);
    enqueueFront(1);
    enqueueRear(3);
    enqueueRear(4);
    // dequeueFront();
    // dequeueRear();
    printQueue();
    return 0;
}
