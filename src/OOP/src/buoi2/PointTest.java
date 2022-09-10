package buoi2;

public class PointTest {

    public static void main(String[] args) {
        Point A = new Point(3, 4);
        A.showPoint();
        Point B = new Point();
        B.readPoint();
        B.showPoint();
        Point C = new Point(-B.getX(), -B.getY());
        C.showPoint();
        System.out.println("Distance of B to O is: " + B.distance());
        System.out.println("Ditance of " + A.distance(B));

    }

}
