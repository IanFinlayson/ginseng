import java.util.Scanner;

class Test {
    public void stuff() {
        System.out.println("Hello there!");
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = in.next();
        System.out.println("Hello " + name);
    }
}
