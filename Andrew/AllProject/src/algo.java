import java.util.Scanner;

public class algo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
int S = in.nextInt();
int tmp = 0;
for (int i= 1; i <= (S/2); i++) {
	if ((S-i) % i == 0) {
		tmp ++; 
	}
}
System.out.println(tmp);

	}

}
