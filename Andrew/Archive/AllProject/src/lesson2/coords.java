package lesson2;
import java.util.Scanner;

public class coords {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double Ax, Ay, Bx, By;
		Ax = scan.nextDouble();
		Ay = scan.nextDouble();
		
		Bx = scan.nextDouble();
		By = scan.nextDouble();
		double res = Math.sqrt( Math.pow((Bx-Ax), 2) +  Math.pow( (Ay-By), 2));
		System.out.println(String.format("%.3f" ,  res));
	}

}
