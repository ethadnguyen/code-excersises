package buoi2;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Date {
    private int ngay, thang, nam;

    public Date() {
        ngay = 8;
        thang = 9;
        nam = 2022;
    }

    public Date(int ngay, int thang, int nam) {
        this.ngay = ngay;
        this.thang = thang;
        this.nam = nam;
    }

    public boolean hople() {
        //
        int max[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
            max[2] = 29;
        return (ngay > 00 && thang > 0 && nam > 0 && thang < 13 && ngay <= max[thang]) ? true : false;

    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        do {

            System.out.println("Nhap ngay: ");
            ngay = sc.nextInt();
            System.out.println("Nhap thang: ");
            thang = sc.nextInt();
            System.out.println("Nhap nam: ");
            nam = sc.nextInt();
            if (!hople())
                System.out.println("Ngay thang khong hop le, xin nhap lai!");
        } while (!hople());
    }

    public Date cong() {
        Date kq = new Date(ngay, thang, nam);
        kq.ngay++;
        if (!kq.hople()) {
            kq.ngay = 1;
            kq.thang++;
            if (!kq.hople()) {
                kq.thang = 1;
                kq.nam++;
            }
        }
        return kq;
    }

    public Date cong(int n) {
        Date kq = new Date(ngay, thang, nam);
        for (int i = 0; i < n; i++) {
            kq = kq.cong();
        }
        return kq;
    }

    public void in() {
        System.out.printf("%02d/%02d/%02d\n", this.ngay, this.thang, this.nam);
    }

}
