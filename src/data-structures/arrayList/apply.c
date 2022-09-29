#include "arrayList.c"
#include <stdlib.h>
#include <stdio.h>
int member(ElementType x, List L)
{
    Position Q;
    for (Q = 1; Q < L.Last + 1; Q++)
    {
        if (retrieve(Q, L) == x)
            return 1;
    }
    return 0;
}
void readList(List *pL)
{
    int i, n;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!member(x, *pL))
        {
            insertList(x, endList(*pL), pL);
        }
    }
}

void insertSet(ElementType x, List *pL)
{
    insertList(x, endList(*pL), pL);
}
// void difference(List L1, List L2, List *pL)
// {
//     makenullList(pL);
//     Position Q;
//     for (Q = 1; Q < L1.Last + 1; Q++)
//     {
//         if (!member(L1.Elements[Q - 1], L2))
//             insertSet(L1.Elements[Q - 1], pL);
//     }
// }
void similar(List L1, List L2, List *pL)
{
    makenullList(pL);
    Position Q;
    for (Q = 1; Q < L1.Last + 1; Q++)
    {
        if (member(L1.Elements[Q - 1], L2))
            insertSet(L1.Elements[Q - 1], pL);
    }
}
void printList(List L)
{
    Position p = first(L);
    while (p != endList(L))
    {
        printf("%d ", retrieve(p, L));
        p = next(p, L);
    }
    printf("\n");
}
int main()
{
    List L1, L2, L;
    readList(&L1);
    readList(&L2);
    similar(L1, L2, &L);
    printList(L1);
    printList(L2);
    printList(L);
    return 0;
}