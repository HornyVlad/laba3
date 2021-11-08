#include <time.h>
#include <malloc.h>
#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
    int items;
    Node* next;
};

typedef Node* PNode;

PNode* Head;

void InitializHead(int size) 
{
    int i;
    Head = (PNode*)malloc(size * sizeof(PNode));
    for (i = 0; i < size; i++) Head[i] = NULL;
}

PNode CreateNode(int items)
{
    PNode NewNode = (Node*)malloc(sizeof(Node));
    NewNode->items = items;
    NewNode->next = NULL;
    return NewNode;
}

void AddFirst(PNode NewNode, int i)
{
    NewNode->next = Head[i];
    Head[i] = NewNode;
}

void AddAfter(PNode q, PNode NewNode)
{
    NewNode->next = q->next;
    q->next = NewNode;
}

void AddLast(PNode NewNode, int i)
{
    PNode q = Head[i];
    while (q->next) q = q->next;
    AddAfter(q, NewNode);
}

void print(int i)
{
    PNode q = Head[i];
    while (q)
    {
        printf("%d ", q->items);
        q = q->next;
    }
    printf("\n");
}

int main() 
{
    int size, i, j, ran, **a;
    PNode NewNode = NULL;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("”кажите размер массива: ");
    scanf_s("%d", &size);
    a = (int**)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = (int*)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        for (j = 1 + i; j < size; j++)
        {
            a[i][j] = rand() % 2;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[j][i] = a[i][j];
        }
    }
    InitializHead(size);
    for (i = 0; i < size; i++) 
    {
        NewNode = CreateNode(i);
        AddFirst(NewNode, i);
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] == 1)
            {
                NewNode = CreateNode(j);
                AddLast(NewNode, i);
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < size; i++)
    {
        print(i);
    }
}