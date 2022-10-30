#include <stdio.h>
#include <stdlib.h>
#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == N - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        top1++;
        s1[top1] = data;
    }
}

void push2(int data)
{
    if (top2 == N - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        top2++;
        s2[top2] = data;
    }
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int data)
{
    push1(data);
    count++;
}

void dequeue()
{
    int a;
    if (top1 == -1 && top2 == -2)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        printf("Popped %d\n", pop2());
        count--;
        for (int i = 0; i < count; i++)
        {
            a = pop2();
            push1(a);
        }
    }
}

int main()
{
    enqueue(5);
    enqueue(1);
    enqueue(2);
    dequeue();
    return 0;
    
}
