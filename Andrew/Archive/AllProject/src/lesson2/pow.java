package lesson2;
import java.util.Scanner;

public class pow {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double a = scan.nextDouble(); 
		double b = scan.nextDouble();
		Math.pow(a, b);
		System.out.println(String.format("%.3f", Math.pow(a, b)));
		scan.close();
	}
}
