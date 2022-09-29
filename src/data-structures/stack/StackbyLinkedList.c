#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

void makenullList(List *pL)
{
    (*pL) = (struct Node *)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}
int emptyList(List L)
{
    return (L->Next == NULL);
}
ElementType retrieve(Position p, List L)
{
    if (p->Next != NULL)
        return p->Next->Element;
}
void insertList(ElementType x, Position p, List *pL)
{
    Position T;
    T = (struct Node *)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = p->Next;
    p->Next = T;
}
void deleteList(Position p, List *pL)
{
    Position T;
    if (p->Next != NULL)
    {
        T = p->Next;
        p->Next = T->Next;
        free(T);
    }
}
Position first(List L)
{
    return L;
}
Position endList(List L)
{
    Position p;
    p = L;
    while (p->Next != NULL)
        p = p->Next;
    return p;
}
Position next(Position p, List L)
{
    return p->Next;
}
Position previous(Position p, List L)
{
    Position Q = L;
    while (Q->Next != p)
    {
        Q = Q->Next;
    }
    return Q;
}
Position locate(ElementType x, List L)
{
    Position P, E;
    P = first(L);
    E = endList(L);
    while (P != E)
    {
        if (retrieve(P, L) == x)
            return P;
        else
            P = next(P, L);
    }
    return P;
}
void printList(List L)
{
    Position P, E;
    P = first(L);
    E = endList(L);
    while (P != E)
    {
        printf("%d ", retrieve(P, L));
        P = next(P, L);
    }
    printf("\n");
}
void readList(List *pL)
{
    int i, n;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        insertList(x, endList(*pL), pL);
    }
}
void append(ElementType x, List *pL)
{
    insertList(x, endList(*pL), pL);
}

typedef List Stack;
void makenullStack(Stack *pS)
{
    makenullList(pS);
}
int emptyStack(Stack S)
{
    return emptyList(S);
}
ElementType top(Stack S)
{
    return retrieve(first(S), S);
}
void pop(Stack *pS)
{
    deleteList(first(*pS), pS);
}
void push(ElementType x, Stack *pS)
{
    insertList(x, first(*pS), pS);
}
int main()
{

    return 0;
}