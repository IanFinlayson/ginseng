import java.util.Scanner;

class Test {
    public static int fact(int x) {
        if (x == 0) {
            return 1;
        } else {
            return x * fact(x - 1);
        }
    
    }

    public static void main(String [] args) {
        System.out.println("Hello World!");
        for (int i = 1; i <= 10; i++) {
            System.out.println(i + "! = " + fact(i));
        }
        Scanner in = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = in.next();
        System.out.println("Hello " + name);
    }
}
