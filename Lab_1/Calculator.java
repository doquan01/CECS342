import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();

        String temp = input.replaceAll("'", "");
        String[] temp1 = temp.split(" ");

        int sol = 0;

        if(temp1[1].equals("+")){
            sol = Integer.parseInt(temp1[0]) + Integer.parseInt(temp1[2]);
            System.out.println(temp + " = " + sol);
        }
        else if(temp1[1].equals("-")){
            sol = Integer.parseInt(temp1[0]) - Integer.parseInt(temp1[2]);
            System.out.println(temp + " = " + sol);
        }
        else if(temp1[1].equals("*")){
            sol = Integer.parseInt(temp1[0]) * Integer.parseInt(temp1[2]);
            System.out.println(temp + " = " + sol);
        }
        else if(temp1[1].equals("/")){
            sol = Integer.parseInt(temp1[0]) / Integer.parseInt(temp1[2]);
            System.out.println(temp + " = " + sol);
        }
    }
}
