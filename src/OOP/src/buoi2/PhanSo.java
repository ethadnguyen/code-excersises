package buoi2;

import java.util.Scanner;

public class PhanSo {
    private int tu, mau;

    public PhanSo() {
        tu = 1;
        mau = 1;
    }

    public PhanSo(int tu, int mau) {
        this.tu = tu;
        this.mau = mau;
    }

    public PhanSo(PhanSo a) {
        tu = a.tu;
        mau = a.mau;
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap tu so: ");
        tu = sc.nextInt();
        do {
            System.out.println("Nhap mau so: ");
            mau = sc.nextInt();
            if (mau == 0) {
                System.out.println("Mau so sai, xin nhap lai");
            }
        } while (mau == 0);
    }

    public void in() {
        if (mau != 1) {
            if (tu != 0) {
                System.out.printf("%d/%d\n", tu, mau);
            } else {
                System.out.println("0");
            }
        } else {
            System.out.println(tu);
        }
    }

    public void nghichDao() {
        if (tu == 0) {
            System.out.println("Phan so khong the nghich dao");
        } else {
            int tmp = tu;
            tu = mau;
            mau = tmp;
        }
    }

    public PhanSo giatriNghichDao() {
        PhanSo p = new PhanSo();
        p.tu = tu;
        p.mau = mau;
        p.nghichDao();
        return p;
    }

    public float giatriThuc() {
        return (float) tu / mau;
    }

    public boolean lonHon(PhanSo a) {
        if ((float) tu / mau > a.giatriThuc())
            return true;

        else
            return false;

    }

    public PhanSo cong(PhanSo a) {
        PhanSo tong = new PhanSo();
        tong.tu = tu * a.mau + mau * a.tu;
        tong.mau = mau * a.mau;
        return tong;
    }

    public PhanSo tru(PhanSo a) {
        PhanSo hieu = new PhanSo();
        hieu.tu = tu * a.mau - mau * a.tu;
        hieu.mau = mau * a.mau;
        return hieu;
    }

    public PhanSo nhan(PhanSo a) {
        PhanSo tich = new PhanSo();
        tich.tu = tu * a.tu;
        tich.mau = mau * a.mau;
        return tich;
    }

    public PhanSo chia(PhanSo a) {
        PhanSo thuong = new PhanSo();
        thuong.tu = tu * a.mau;
        thuong.mau = mau * a.tu;
        return thuong;
    }

    public PhanSo cong(int n) {
        PhanSo tong = new PhanSo();
        tong.tu = tu + n * mau;
        tong.mau = mau;
        return tong;
    }

    public PhanSo tru(int n) {
        PhanSo hieu = new PhanSo();
        hieu.tu = tu - n * mau;
        hieu.mau = mau;
        return hieu;
    }

    public PhanSo nhan(int n) {
        PhanSo tich = new PhanSo();
        tich.tu = tu * n;
        tich.mau = mau;
        return tich;
    }

    public PhanSo chia(int n) {
        PhanSo thuong = new PhanSo();
        thuong.tu = tu;
        thuong.mau = mau * n;
        return thuong;
    }
}
