#include <stdlib.h>
#include <stdio.h>
#include "arrayList.c"
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
void readList(List *pL)
{
    int i, n;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertList(x, endList(*pL), pL);
    }
}
float getAvg(List L)
{
    if (L.Last == 0)
    {
        return -10000.0000;
    }
    else
    {
        float S = 0;
        Position Q;
        for (Q = 1; Q < L.Last + 1; Q++)
        {
            S += L.Elements[Q - 1];
        }
        return (float)S / (L.Last);
    }
}
int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("%f\n", getAvg(L));
    return 0;
}