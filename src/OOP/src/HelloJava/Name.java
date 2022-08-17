package HelloJava;

import java.util.Scanner;

public class Name {
    public String readName() {
        String name;
        Scanner sc = new Scanner(System.in);
        name = sc.nextLine();
        sc.close();
        return name;
    }

    public String getFirstName(String name) {
        String temp = name.trim();
        int p = temp.lastIndexOf(" ");
        String firstName = temp.substring(p + 1);
        return firstName;
    }
}
