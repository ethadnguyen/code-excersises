package HelloJava;

import java.util.Scanner;

public class InputList {
    public String[] readList() {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        sc.nextLine();
        String a[] = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLine();
        }
        sc.close();
        return a;
    }

    public double maxOfList(String a[]) {
        double max = Double.MIN_VALUE;
        double n;
        for (String e : a) {
            try {
                n = Double.parseDouble(e);
            } catch (NumberFormatException ex) {
                n = 0;
            }
            if (n > max) {
                max = n;
            }
        }
        return max;

    }

    public double sumOfList(String a[]) {

        double sum = 0, n;
        for (String e : a) {
            try {
                n = Double.parseDouble(e);
            } catch (NumberFormatException ex) {
                n = 0;
                sum += n;
            }
            sum += n;
        }
        return sum;
    }
}
