package HelloJava;

import java.util.Scanner;

public class TwoSum {
    public int read() {
        Scanner sc = new Scanner(System.in);
        String s;
        int n;
        System.out.print("\nNhap vao 1 so nguyen: ");
        s = sc.nextLine();
        do {

            try {
                n = Integer.parseInt(s);
            } catch (NumberFormatException e) {
                n = Integer.MAX_VALUE;
                System.out.print("Ban nhap sai dinh dang!");
            }
        } while (n == Integer.MAX_VALUE);
        sc.close();
        return n;
    }

    public int sum(int a, int b) {
        return a + b;
    }
}
