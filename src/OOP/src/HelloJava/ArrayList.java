package HelloJava;

import java.util.Scanner;

public class ArrayList {
    int a[];

    public int[] readList() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            if (sc.hasNextInt()) {
                a[i] = sc.nextInt();
            }
        }
        sc.close();
        return a;
    }

    public int countX(int x) {
        int cnt = 0;
        for (int e : a) {
            if (e == x)
                cnt++;
        }
        return cnt;
    }

    public void sort(int l, int r) {

        QuickSort qS = new QuickSort();
        qS.sort(a, l, r);
    }

    public void printArray() {
        for (int e : a) {
            System.out.print(e + " ");
        }
    }

    public static void main(String[] args) {
        ArrayList arr = new ArrayList();
        Scanner sc = new Scanner(System.in);
        int a[] = arr.readList();
        arr.printArray();
        int r = a.length - 1;
        arr.sort(0, r);
        arr.printArray();
        int x = sc.nextInt();
        System.out.println("So lan xuat hien cua x la: " + arr.countX(x));
        sc.close();
    }
}
