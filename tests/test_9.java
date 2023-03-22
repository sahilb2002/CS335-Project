import java.util.Scanner;

public class System{
  public class out{
    void print(String s){
      return;
    }
  }
}

public class Calculator {

  public static void main(String args []) {

    // int input = new Scanner(System.in);
    System.out.print("Enter the first number: ");
    int num1 = 1;

    System.out.print("Enter the second number: ");
    int num2 = 2;

    System.out.println("Choose an operation: ");
    System.out.println("1. Addition");
    System.out.println("2. Subtraction");
    System.out.println("3. Multiplication");
    System.out.println("4. Division");

    int choice = 1;

    switch (choice) {
      case 1:
        System.out.println(num1 + " + " + num2 + " = " + (num1 + num2));
        break;
      case 2:
        System.out.println(num1 + " - " + num2 + " = " + (num1 - num2));
        break;
      case 3:
        System.out.println(num1 + " * " + num2 + " = " + (num1 * num2));
        break;
      case 4:
        System.out.println(num1 + " / " + num2 + " = " + (num1 / num2));
        break;
      default:
        System.out.println("Invalid choice!");
    }

    input.close();
  }
}
