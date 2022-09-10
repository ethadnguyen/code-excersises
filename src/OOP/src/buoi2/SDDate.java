package buoi2;

import java.util.Scanner;

public class SDDate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Date d1 = new Date();
        d1.nhap();
        System.out.println("\nNgay d1: ");
        d1.in();
        System.out.println("\nNhap vao so ngay cong: ");
        int n = sc.nextInt();
        d1 = d1.cong(n);
        System.out.println("\nNgay d1 sau khi da cong: ");
        d1.in();
    }
}
