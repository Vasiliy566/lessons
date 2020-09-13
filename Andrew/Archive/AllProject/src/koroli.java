import java.util.ArrayList;
import java.util.Scanner;

public class koroli {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
 Scanner in = new Scanner(System.in);
 int n = in.nextInt();
 int max = -1;
 int tmp = 0;
 int[] arr = new int[n];
 for(int i = 0; i < n; i++ ) {
	 arr[i] = in.nextInt();
	 
	 if(arr[i] > max) {max = arr[i];}	 
 }
 for (int i = 0; i < n; i++) {
 if (arr[i] < max) {tmp = tmp + (max - arr[i]); }
     }
 System.out.println(tmp);
	}
}
