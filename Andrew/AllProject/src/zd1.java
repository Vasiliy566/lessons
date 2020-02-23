import java.util.Scanner;

public class zd1 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner d = new Scanner(System.in);
int n = d.nextInt();
int sum;
int s = 0;
for (int i= 0; i < n; i++) {
	sum = 0; 
	for (int j = 0; j < 3; j ++) {
		sum += d.nextInt();
	}
	if (sum >= 2) {
		s++;
	}
	
}
System.out.println(s);
	}

}
