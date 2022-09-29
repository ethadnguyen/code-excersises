#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef struct
{
    struct SinhVien A[40];
    int n;

} DanhSach;
int tim(char x[], DanhSach L)
{
    int p;
    p = 1;
    while (p != L.n + 1)
    {
        if (strcmp(L.A[p - 1].MSSV, x) == 0)
        {
            return p;
        }
        else
            p = p + 1;
    }
    return p;
}
void xoaTai(int p, DanhSach *pL)
{
    if (pL->n == 0)
    {
        printf("Danh sach rong\n");
    }
    else if (p < 1 || p > (pL->n + 1))
    {
        printf("Vi tri khong hop le\n");
    }
    else
    {
        int Q;
        for (Q = p; Q < pL->n; Q++)
        {
            pL->A[Q - 1] = pL->A[Q];
        }
        pL->n--;
    }
}
void xoaSinhVien(char x[], DanhSach *pL)
{
    int p = tim(x, *pL);
    xoaTai(p, pL);
}
void chentai(struct SinhVien x, int p, DanhSach *pL)
{
    if (pL->n == 40)
    {
        printf("Danh sach day");
    }
    else if (p < 1 || p > (pL->n + 1))
    {
        printf("Vi tri khong hop le");
    }
    else
    {
        int Q;
        for (Q = pL->n; Q >= p; Q--)
        {
            pL->A[Q] = pL->A[Q - 1];
        }
        pL->A[p - 1] = x;
        pL->n++;
    }
}
void chenCuoi(struct SinhVien x, DanhSach *pL)
{
    chentai(x, pL->n + 1, pL);
}
int tontai(char x[], DanhSach L)
{
    if (strcmp(x, L.A[tim(x, L)].MSSV) == 0)
        return 1;
    return 0;
}
void dsRong(DanhSach *pL)
{
    pL->n = 0;
}
DanhSach nhap()
{
    int i, s;
    DanhSach L;
    scanf("%d ", &s);
    dsRong(&L);
    struct SinhVien sv;
    for (i = 0; i < s; i++)
    {
        char mssv[10];
        char hoten[50];
        fgets(mssv, 10, stdin);
        int len1 = strlen(mssv);
        if (mssv[len1 - 1] == '\n')
        {
            mssv[len1 - 1] = '\0';
            // len1--;
        };
        fgets(hoten, 50, stdin);
        int len2 = strlen(hoten);
        if (hoten[len2 - 1] == '\n')
        {
            hoten[len2 - 1] = '\0';
            // len2--;
        };
        strcpy(sv.MSSV, mssv);
        strcpy(sv.HoTen, hoten);
        scanf("%f%f%f ", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);
        if (tim(sv.MSSV, L) == L.n + 1)
            chenCuoi(sv, &L);
    }
    return L;
}
void hienthiDS(DanhSach L)
{
    int i;
    for (i = 1; i < L.n + 1; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
    }
}
void hienthiDat(DanhSach L)
{
    int i;
    float tong = 0;
    for (i = 1; i < L.n + 1; i++)
    {
        tong = (L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2);
        if (tong >= 4)
        {
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
        }
    }
    // printf("\n");
}
int main()
{
    DanhSach L;
    int i;
    L = nhap();
    char mssv[10];
    fgets(mssv, 10, stdin);
    if (mssv[strlen(mssv) - 1] == '\n')
        mssv[strlen(mssv) - 1] = '\0';
    hienthiDS(L);
    for (i = 1; i < L.n + 1; i++)
    {
        if (tim(mssv, L) == L.n + 1)
        {
            printf("Khong tim thay sinh vien %s", mssv);
            break;
        }
        else
        {
            printf("Tim thay sinh vien %s. ", mssv);
            printf("Thong tin sinh vien:\n");
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
            xoaSinhVien(L.A[i - 1].MSSV, &L);
        }
    }
    // printf("Sinh vien DAT\n");
    // hienthiDat(L);
}