import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

/*
10
-6 8 -3 -4 -5 -6 1 5 8 -8 
8 8 -8 -6 -6 5 -5 -4 -3 1 
 * */
public class sort1 {
	// если a > b, return true, else return false
	public static boolean eval(int a_, int b_) {
		if ((a_ < 0) && (b_ > 0) && (Math.abs(a_) == Math.abs(b_))) {
			return false;
		}
		int asum = 0;
		int bsum = 0;
		int a = Math.abs(a_);
		int b = Math.abs(b_);

		while (a != 0) {
			asum += a % 10;
			a /= 10;
		}
		while (b != 0) {
			bsum += b % 10;
			b /= 10;
		}
		if (asum < bsum)
			return true;
		else
			return false;

	}

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			 arr[i] = in.nextInt();
			
		}
		
		
		// -----------------------------------------
		boolean is_sorted = false;
		while (is_sorted == false) {
			is_sorted = true;
			for (int i = 0; i < n - 1; i++) {
			 if (eval(arr[i], arr[i+1])) {
				 is_sorted = false;
				 int tmp = arr[i];
				 arr[i] = arr[i+1];
				 arr[i+1] = tmp;
			 }
			}
		}
		// -----------------------------------------
		for (int j = 0; j < n; j++) {
			System.out.print(arr[j] + " ");
		}

	}

}
