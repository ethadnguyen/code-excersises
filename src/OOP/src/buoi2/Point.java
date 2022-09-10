package buoi2;

import java.lang.Math;
import java.util.Scanner;

public class Point {
    private int x, y;

    public Point() {

    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void readPoint() {
        Scanner sc = new Scanner(System.in);
        this.x = sc.nextInt();
        this.y = sc.nextInt();
    }

    public void showPoint() {
        System.out.printf("(%d,%d)\n", this.x, this.y);
    }

    public void move(int dx, int dy) {
        this.x += dx;
        this.y += dy;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public Point Opposite(Point a) {
        Point d = new Point();
        d.x = -a.x;
        d.y = -a.y;
        return d;
    }

    public double distance() {
        return Math.sqrt(this.x * this.x + this.y * this.y);
    }

    public double distance(Point P) {
        return Math.sqrt((this.x - P.x) * (this.x * P.x) + (this.y - P.y) * (this.y - P.y));
    }

}
