import java.util.Scanner;

public class ururur {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
int k = in.nextInt();
double tmp = 0;
double c;
for (int i = 0; i < k; i++ ) {
	int p = in.nextInt();
	tmp += p;
}
c = (tmp / k);

System.out.printf("%.4f" , c);
	}

}
