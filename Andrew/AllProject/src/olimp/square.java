package olimp;


import java.util.Arrays;
import java.util.Scanner;



public class square {
	
	static int solve (int[] arr) {
		Arrays.sort(arr);
		for(int i=0; i<arr.length/2; i++){
			  int temp = arr[i];
			  arr[i] = arr[arr.length -i -1];
			  arr[arr.length -i -1] = temp;
			}
		int max = 0; 
		for(int i = 0; i < arr.length; i ++) {
			if( Math.min(i + 1, arr[i]) > max    ) {
				max = Math.min(i + 1, arr[i]);
			} else {
				break;
			}
		}
		
		return max ;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int r = in.nextInt();
			int[] arr = new int[r];
			for(int j = 0; j < r; j ++) 
				arr[j] = in.nextInt();
			System.out.println(solve(arr));
		}

	}

}
