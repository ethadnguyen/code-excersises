#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double he_so;
    int bac;
} DonThuc;
struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;
DaThuc khoitao()
{
    DaThuc e;
    e->Next == NULL;
    return e;
}
void insertList(DonThuc x, Position p, DaThuc *pD)
{
    Position T;
    T = (struct Node *)malloc(sizeof(struct Node));
    T->e = x;
    T->Next = p->Next;
    p->Next = T;
}
void chenDonThuc(DonThuc x, DaThuc *pD)
{
    DaThuc p;
    for (p = *pD; p->Next != NULL; p = p->Next)
    {
        if (x.bac == p->Next->e.bac)
        {
            p->Next->e.he_so += x.he_so;
            break;
        }
        else if (x.bac > p->Next->e.bac)
        {
            DaThuc T;
            T = (struct Node *)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = p->Next;
            p->Next = T;
            break;
        }
    }
    if (p->Next == NULL)
    {
        DaThuc T;
        T = (struct Node *)malloc(sizeof(struct Node));
        T->e = x;
        T->Next = p->Next;
        p->Next = T;
    }
}
void inDaThuc(DaThuc d)
{
    Position p = d;
    while (p->Next != NULL)
    {
        if (p == d)
        {
            printf("%.3lfX^%d ", p->Next->e.he_so, p->Next->e.bac);
        }
        else
        {
            printf("+ %.3lfX^%d ", p->Next->e.he_so, p->Next->e.bac);
        }
        p = p->Next;
    }
}
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc poly;
    poly = khoitao();
    Position p;
    Position q;
    DonThuc kq;
    for (p = D1; p->Next != NULL; p = p->Next)
    {
        for (q = D2; q->Next != NULL; q = q->Next)
        {
            kq.he_so = p->Next->e.he_so * q->Next->e.he_so;
            kq.bac = p->Next->e.bac + q->Next->e.bac;
            chenDonThuc(kq, poly);
        }
    }

    return poly;
}
int main()
{
    DaThuc d = khoitao();
    struct Node *p = d;
    DonThuc s1 = {6.2, 4};
    DonThuc s2 = {4.2, 0};
    DonThuc s3 = {2, 4};
    DonThuc s4 = {1, 9};
    chenDonThuc(s1, &d);
    chenDonThuc(s2, &d);
    chenDonThuc(s3, &d);
    chenDonThuc(s4, &d);
    while (p->Next != NULL)
    {
        DonThuc e = p->Next->e;
        printf("%.3fX^%d ", e.he_so, e.bac);
        p = p->Next;
    }
    return 0;
}