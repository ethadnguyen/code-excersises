#include <stdio.h>
#include <stdlib.h>
#include "arrayList.c"
ElementType maxList(List L)
{
    Position Q;
    ElementType max = 0;
    for (Q = first(L), Q < endList(L); Q = next(Q, L))
    {
        if (retrieve(q, L) > max)
            max = retrieve(q, L);
    }
    return max;
}
int main()
{
}