package HelloJava;

public class Ptb2 {
    public static void gptb1(int a, int b) {
        if (a == 0) {
            if (b == 0) {
                System.out.println("Phuong trinh vo so nghiem");
            } else {
                System.out.println("phuong trinh vo nghiem");
            }
        } else {
            double n = (double) -b / a;
            System.out.println("nghiem cua pt la: " + n);
        }
    }

    public static void gptb1(double a, double b) {
        if (a == 0) {
            if (b == 0) {
                System.out.println("Phuong trinh vo so nghiem");
            } else {
                System.out.println("phuong trinh vo nghiem");
            }
        } else {
            double n = -b / a;
            System.out.println("Nghiem cua pt la: " + n);
        }
    }

    public void gptb2(double a, double b, double c) {
        if (a == 0)
            gptb1(b, c);
        else {
            double delta = Math.pow(b, 2) - 4 * a * c;
            if (delta > 0) {
                delta = Math.sqrt(delta);
                double x1 = (-b + delta) / (2 * a);
                double x2 = (-b - delta) / (2 * a);
                System.out.print("Phuong trinh co 2 nghiem la \nx1=" + x1 + "\nx2= " + x2);
            } else if (delta == 0) {
                double x = (-b / (2 * a));
                System.out.println("phuong trinh co 1 nghiem la \nx= " + x);
            } else {
                System.out.println("Phuong trinh vo nghiem");
            }
        }
    }
}
