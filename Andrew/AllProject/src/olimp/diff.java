package olimp;

import java.util.Scanner;

public class diff {
	static boolean solver(int[] diff) {
		int tmp = 0 ;
		int j = 0;
		for ( j = 0; j < diff.length; j++) {
			if (diff[j] !=0 ) {
				tmp = diff[j];
				break;
			}
		}
			int k = 0;
		for ( k = j; k < diff.length; k++) {
			if (diff[k] != tmp ) {
				if (diff[k] != 0) {
					return false;
				}
				break;
			}			
		}
		for (int r = k; r < diff.length; r++) {
			if (diff[r] != 0) {
				return false;
		}
		}
		
		return true;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n1 = in.nextInt();
		int n2 = in.nextInt();
		int[] a = new int[n2];
		int[] diff = new int[n2];
		for (int i = 0; i < n2; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n2; i++) {
			diff[i] = a[i] - in.nextInt();
		}
		System.out.println(solver(diff));
  
	}

}
