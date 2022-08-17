package HelloJava;

import java.util.Scanner;

public class Testptb2 {
    public static void main(String[] args) {
        double a, b, c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        Ptb2 pt = new Ptb2();
        pt.gptb2(a, b, c);
        sc.close();
    }
}
