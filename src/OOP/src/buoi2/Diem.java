package buoi2;

import java.util.Scanner;

public class Diem {
    private int x, y;

    public Diem() {

    }

    public Diem(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void nhapDiem() {
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();
    }

    public void hienThi() {
        System.out.printf("(%d,%d)\n", this.x, this.y);
    }

    public void doiDiem(int dx, int dy) {
        x += dx;
        y += dy;
    }

    public int giaTriX() {
        return x;
    }

    public int giaTriY() {
        return y;
    }

    public Diem Dxung(Diem a) {
        Diem d = new Diem();
        d.x = -a.x;
        d.y = -a.y;
        return d;
    }

    public double khoangCach() {
        return Math.sqrt(this.x * this.x + this.y * this.y);
    }

    public double khoangCach(Diem P) {
        return Math.sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
    }
}
