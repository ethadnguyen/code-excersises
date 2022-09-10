package buoi2;

import java.util.Scanner;

public class SDPhanSo {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // PhanSo a = new PhanSo(3,7);
        // PhanSo b = new PhanSo(4,9);
        // a.in();
        // b.in();
        // PhanSo x = new PhanSo();
        // PhanSo y = new PhanSo();
        // System.out.println("Nhap phan so x: ");
        // x.nhap();
        // System.out.println("Nhap phan so y: ");
        // y.nhap();
        // PhanSo xNghichDao = new PhanSo(x.giatriNghichDao());
        // System.out.println("Gia tri nghich dao cua x la: ");
        // xNghichDao.in();
        // PhanSo tong = new PhanSo();
        // tong = x.cong(y);
        // System.out.println("Tong cua x va y la: ");
        // tong.in();
        System.out.println("Nhap vao so luong phan so :");
        int n;
        n = sc.nextInt();
        PhanSo a[];
        a = new PhanSo[n];
        for (int i = 0; i < n; i++) {
            a[i] = new PhanSo();
        }
        float sum = 0;
        PhanSo max = new PhanSo(-1, 99999);
        for (int i = 0; i < n; i++) {
            System.out.println("Nhap vao phan so thu " + (i + 1));
            a[i].nhap();
            sum += a[i].giatriThuc();
            if (a[i].giatriThuc() > max.giatriThuc())
                max = a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].giatriThuc() > a[j].giatriThuc()) {
                    PhanSo tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
        System.out.println("Tong cua day phan so la: " + sum);
        System.out.println("Phan so lon nhat la: ");
        max.in();
        System.out.println("Danh sach sau khi da sap xep la: ");
        for (int i = 0; i < n; i++) {
            a[i].in();
        }

    }
}
