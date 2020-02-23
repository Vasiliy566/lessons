package lesson2;
import java.util.Random;
import java.util.Scanner;

public class random {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double a = scan.nextDouble(); 
		double b = scan.nextDouble();
		Random rnd = new Random();
		
		for(int i = 0; i < 5; i ++ ) {
			double generated = (rnd.nextDouble() * (b-a) ) + a;
			System.out.println(String.format("%.3f" ,  generated));
		}
		scan.close();
	}

}
