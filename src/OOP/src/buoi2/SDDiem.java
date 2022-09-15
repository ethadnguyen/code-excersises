package buoi2;

public class SDDiem {
    public static void main(String[] args) {
        Diem A = new Diem(3, 4);
        A.hienThi();
        Diem B = new Diem();
        B.nhapDiem();
        B.hienThi();
        Diem C = new Diem();
        C = C.Dxung(B);
        C.hienThi();
        System.out.println("Distance of B to O is: " + B.khoangCach());
        System.out.println("Ditance of " + A.khoangCach(B));

    }
}
