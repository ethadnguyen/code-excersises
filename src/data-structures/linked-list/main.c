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
int member(ElementType x, List L)
{
    Position p;
    p = L;
    while (p->Next != NULL)
    {
        if (p->Next->Element == x)
            return 1;
        p = p->Next;
    }
    return 0;
}
List difference(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p;
    p = L1;
    while (p->Next != NULL)
    {
        if (member(p->Next->Element, L2) == 0)
        {
            append(p->Next->Element, &L);
        }
        p = p->Next;
    }
    return L;
}
void copyEvenNumbers(List L1, List *pL2)
{
    makenullList(pL2);
    Position p;
    p = L1;
    while (p->Next != NULL)
    {
        if (p->Next->Element % 2 == 0)
            append(p->Next->Element, pL2);
        p = p->Next;
    }
}
List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p, q;
    p = L1;
    q = L2;
    while (p->Next != NULL)
    {
        append(p->Next->Element, &L);
        p = p->Next;
    }
    while (q->Next != NULL)
    {
        if (member(q->Next->Element, L1) == 0)
        {
            append(q->Next->Element, &L);
        }
        q = q->Next;
    }
    return L;
}
float getAvg(List L)
{
    float sum = 0;
    Position p;
    p = L;
    int cnt = 0;
    if (p->Next == NULL)
        return -10000.0f;
    while (p->Next != NULL)
    {
        sum += p->Next->Element;
        p = p->Next;
        cnt++;
    }
    return (float)sum / cnt;
}
void addFirst(ElementType x, List *pL)
{
    insertList(x, first(*pL), pL);
}
void sort(List *pL)
{
    Position p, q;
    for (p = *pL; p->Next != NULL; p = p->Next)
    {
        for (q = p->Next; q->Next != NULL; q = q->Next)
        {
            if (p->Next->Element > q->Next->Element)
            {
                ElementType t = p->Next->Element;
                p->Next->Element = q->Next->Element;
                q->Next->Element = t;
            }
        }
    }
}
void removeAll(ElementType x, List *pL)
{
    Position p = locate(x, *pL);
    while (p->Next != NULL)
    {
        deleteList(p, pL);
        p = locate(x, *pL);
    }
}
void printOddNumbers(List L)
{
    Position p;
    p = L;
    while (p->Next != NULL)
    {
        if (p->Next->Element % 2 != 0)
        {
            printf("%d ", p->Next->Element);
        }
        p = p->Next;
    }
}
void erase(ElementType x, List *pL)
{
    Position p = locate(x, *pL);
    if (p->Next != NULL)
    {
        deleteList(p, pL);
    }
    else
    {
        printf("Not found %d\n", x);
    }
}
List intersection(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p;
    p = L1;
    while (p->Next != NULL)
    {
        if (member(p->Next->Element, L2))
        {
            append(p->Next->Element, &L);
        }
        p = p->Next;
    }
    return L;
}
int main()
{
    List L1, L2, L;
    int i;

    Position p;
    makenullList(&L1);
    makenullList(&L2);
    for (i = 1; i <= 3; i++)
        append(i, &L1);
    for (i = -1; i <= 2; i++)
        append(i, &L2);
    L = intersection(L1, L2);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}