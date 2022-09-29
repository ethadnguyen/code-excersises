#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Node *locate(char x[], List L)
{
    struct Node *P, *E;
    P = L;
    while (P->Next != NULL)
    {
        if (strcmp(P->Next->Element.ID, x) == 0)
            return P;
        else
            P = P->Next;
    }
    return P;
}
List readList()
{
    int n, i;
    Student s;
    char st[50];
    List L = getList(); // Khởi tạo danh sách rỗng
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf(" "); // skip some characters
        fgets(st, 10, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.ID, st);
        fgets(st, 50, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.Name, st);
        scanf("%f%f%f", &s.R1, &s.R2, &s.R3);
        // Nếu mã sinh viên chưa có thì chèn vào danh sách
    }
    return L;
}
List getFailedList(List L)
{

    struct Node *p = L;
    List kq = getList();
    for (p = L; p->Next != NULL; p = p->Next)
    {
        float x = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3;
        if (x < 4)
        {
            append(p->Next->Element, &kq);
        }
    }
    return kq;
}
int main()
{
    return 0;
}