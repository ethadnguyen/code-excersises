package HelloJava;

public class Numbertest {
    public static void main(String[] args) {
        Number num = new Number();
        int n = num.read();
        if (num.isPrime(n)) {
            System.out.println(n + " la so nguyen to");
            System.out.println("co dang nhi phan la: " + Integer.toBinaryString(n));
        } else {
            System.out.println(n + " khong la so nguyen to");
            System.out.println("Co dang nhi phan la: " + Integer.toBinaryString(n));
        }

    }
}
