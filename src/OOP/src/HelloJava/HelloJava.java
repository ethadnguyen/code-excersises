package HelloJava;

public class HelloJava {
    public static void main(String[] args) {
        InputList List1 = new InputList();
        String a[] = List1.readList();
        double max = List1.maxOfList(a);
        double sum = List1.sumOfList(a);
        System.out.println("Sum of List is: " + sum);
        System.out.println("Max of List is: " + max);
    }
}
