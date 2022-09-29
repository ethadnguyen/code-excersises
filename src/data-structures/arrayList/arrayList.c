#include <stdio.h>
#include <stdlib.h>
#define MaxLength 300
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;
void makenullList(List *pL)
{
    pL->Last = 0;
}
int emptyList(List L)
{
    return L.Last == 0;
}
int fullList(List L)
{
    return L.Last == MaxLength;
}
Position first(List L)
{
    return 1;
}
Position endList(List L)
{
    return L.Last + 1;
}
Position next(Position p, List L)
{
    return p + 1;
}
Position previous(Position p, List L)
{
    return p - 1;
}
void insertList(ElementType x, Position p, List *pL)
{
    if (pL->Last == MaxLength)
    {
        printf("Danh sach day");
    }
    else if (p < 1 || p > (pL->Last + 1))
    {
        printf("Vi tri khong hop le");
    }
    else
    {
        Position Q;
        for (Q = pL->Last; Q >= p; Q--)
        {
            pL->Elements[Q] = pL->Elements[Q - 1];
        }
        pL->Elements[p - 1] = x;
        pL->Last++;
    }
}
void deleteList(Position p, List *pL)
{
    if (emptyList(*pL))
    {
        printf("Danh sach rong\n");
    }
    else if (p < 1 || p > (pL->Last + 1))
    {
        printf("Vi tri khong hop le\n");
    }
    else
    {
        Position Q;
        for (Q = p; Q < pL->Last; Q++)
        {
            pL->Elements[Q - 1] = pL->Elements[Q];
        }
        pL->Last--;
    }
}
ElementType retrieve(Position p, List L)
{
    return L.Elements[p - 1];
}
Position locate(ElementType x, List L)
{
    Position p;
    p = first(L);
    while (p != endList(L))
    {
        if (retrieve(p, L) == x)
        {
            return p;
        }
        else
            p = next(p, L);
    }
    return p;
}
// int locate(int x, List L)
// {
//     Position p;
//     p = 1;
//     while (p != L.Last + 1)
//     {
//         if (L.Elements[p - 1] == x)
//         {
//             return p;
//         }
//         else
//             p = p + 1;
//     }
//     return p;
// }
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
void readList(int n, List *pL)
{
    int i;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertList(x, endList(*pL), pL);
    }
}
void erase(ElementType x, List *pL)
{
    deleteList(locate(x, *pL), pL);
}
void copyEvenNumbers(List L1, List *pL2)
{
    makenullList(pL2);
    Position Q;
    for (Q = 1; Q < L1.Last + 1; Q++)
    {
        if (retrieve(Q, L1) % 2 == 0)
        {
            insertList(retrieve(Q, L1), pL2->Last + 1, pL2);
        }
    }
}
// int member(ElementType x, List L)
// {
//     Position Q;
//     for (Q = 1; Q < L.Last + 1; Q++)
//     {
//         if (retrieve(Q, L) == x)
//             return 1;
//     }
//     return 0;
// }
// int member(int x, List L)
// {
//     Position Q;
//     for (Q = 1; Q < L.Last + 1; Q++)
//     {
//         if (L.Elements[Q - 1] == x)
//             return 1;
//     }
//     return 0;
// }
// void insertSet(ElementType x, List *pL)
// {
// insertList(x, endList(*pL), pL);
// }
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
void removeAll(ElementType x, List *pL)
{
    Position p = locate(x, *pL);
    while (p >= 1 && p < pL->Last + 1)
    {
        deleteList(p, pL);
        p = locate(x, *pL);
    }
}
// float getAvg(List L)
// {
//     if (L.Last == 0)
//     {
//         return -10000.0000;
//     }
//     else
//     {
//         float S = 0;
//         Position Q;
//         for (Q = 1; Q < L.Last + 1; Q++)
//         {
//             S += L.Elements[Q - 1];
//         }
//         return (float)S / (L.Last);
//     }
// }
// int main()
// {
//     List L;
//     int i;
//     Position p;
//     L.Last = 0;
//     for (i = 0; i < 5; i++)
//         L.Elements[i] = 2 * i;
//     L.Last = 5;
//     p = locate(10, L);
//     // if (p<L.Last+1)
//     //     printf("Found at %d",p);
//     // else
//     printf("Not found p = %d", p);
//     return 0;
// }