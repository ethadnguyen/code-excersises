#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;
void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}
int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}
int full(Stack S)
{
    return S.Top_idx == 0;
}
ElementType top(Stack S)
{
    if (!emptyStack(S))
    {
        return S.Elements[S.Top_idx];
    }
    else
    {
        printf("Loi! Ngan xep rong!\n");
    }
}
void pop(Stack *pS)
{
    if (!emptyStack(*pS))
    {
        pS->Top_idx = pS->Top_idx + 1;
    }
    else
    {
        printf("Loi! Ngan xep rong!\n");
    }
}
void push(ElementType x, Stack *pS)
{
    if (full(*pS))
    {
        printf("Loi! Ngan xep day!\n");
    }
    else
    {
        pS->Top_idx = pS->Top_idx - 1;
        pS->Elements[pS->Top_idx] = x;
    }
}
void Print_Binary(int n)
{
    Stack S;
    makenullStack(&S);
    while (n != 0)
    {
        push(n % 2, &S);
        n = n / 2;
    }
    while (!emptyStack(S))
    {
        printf("%d", top(S));
        pop(&S);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Print_Binary(n);
    return 0;
}