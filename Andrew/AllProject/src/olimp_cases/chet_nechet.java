package olimp_cases;

import java.util.Scanner;

public class chet_nechet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
int n = in.nextInt();
int k = in.nextInt();
int tmp = 0;
if (n/2 > k) {
	tmp = (k-1)*2 +1;
}
else {
	k -= n/2;
	tmp = (k-1) * 2;
}
System.out.println(tmp);
}
	}


