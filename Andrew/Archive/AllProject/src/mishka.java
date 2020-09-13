import java.util.Scanner;

public class mishka {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int tmp = 0;
		for(int i = 0 ; i < n; i++) {
		int x = in.nextInt();
		int y = in.nextInt();
		if (x > y) {
			tmp = tmp + 1; 
		           }
		else if (x !=  y) {
			tmp = tmp - 1;
		     }		
		}
		if (tmp > 0) {
			System.out.println("Mishka");
		}
		if (tmp < 0) {
			System.out.println("Chris");
		}
		if (tmp == 0) {
			System.out.println("Friendship is magic!^^");
		}
}
	}


