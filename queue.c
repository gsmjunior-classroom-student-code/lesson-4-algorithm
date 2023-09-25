#include <stdio.h>

#define MAX_SIZE 10000

int queue[MAX_SIZE];

int head = 0;
int tail = 0;

void push(int data)
{
    if (tail >= MAX_SIZE)
    {
        return;
    }
    queue[tail++] = data;
}

int pop()
{
    if (head == tail)
    {
        return -1;
    }
    return queue[head++];
}

int empty()
{
    if (head == tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int size()
{
    return tail - head;
}

int front()
{
    if (empty())
    {
        return -1;
    }
    return queue[head];
}

int back()
{
    if (empty())
    {
        return -1;
    }
    return queue[tail - 1];
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        char cmd[6];
        scanf("%s", cmd);

        if (cmd[0] == 'p' && cmd[1] == 'u')
        {
            int num;
            scanf("%d", &num);
            push(num);
        }
        else if (cmd[0] == 'p' && cmd[1] == 'o')
        {
            printf("%d\n", pop());
        }
        else if (cmd[0] == 's')
        {
            printf("%d\n", size());
        }
        else if (cmd[0] == 'e')
        {
            printf("%d\n", empty());
        }
        else if (cmd[0] == 'f')
        {
            printf("%d\n", front());
        }
        else if (cmd[0] == 'b')
        {
            printf("%d\n", back());
        }
    }
    return 0;
}