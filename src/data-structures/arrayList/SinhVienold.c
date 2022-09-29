#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *HoTen;
    float LT, TH;
    char *DiemChu;
} SinhVien;
SinhVien nhapSV()
{
    SinhVien sv;
    char h[50];
    if (fgets(h, 50, stdin) != NULL)
        ;
    fgets(h, 50, stdin);
    int len = strlen(h);
    if (h[len - 1] == '\n')
    {
        h[len - 1] = '\0';
        len--;
    };
    sv.HoTen = strdup(h);
    scanf("%f%f", &sv.LT, &sv.TH);
    return sv;
}
void nhapDS(SinhVien **pL, int n)
{
    int i;
    *pL = (SinhVien *)malloc(n * sizeof(SinhVien));
    for (i = 0; i < n; i++)
    {
        (*pL)[i] = nhapSV();
    }
}
void inSV(SinhVien sv)
{
    float sum = sv.LT + sv.TH;
    if (sum >= 9)
    {
        sv.DiemChu = "A";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 8)
    {
        sv.DiemChu = "B+";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 7)
    {
        sv.DiemChu = "B";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 6)
    {
        sv.DiemChu = "C+";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 5)
    {
        sv.DiemChu = "C";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 4.5)
    {
        sv.DiemChu = "D+";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else if (sum >= 4)
    {
        sv.DiemChu = "D";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
    else
    {
        sv.DiemChu = "F";
        printf("%s %.3f %.3f %s\n", sv.HoTen, sv.LT, sv.TH, sv.DiemChu);
    }
}
void inDS(SinhVien *L, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        inSV(L[i]);
    }
}
int main()
{
    int n;
    SinhVien *list;
    scanf("%d", &n);
    nhapDS(&list, n);
    inDS(list, n);
    free(list);
}
