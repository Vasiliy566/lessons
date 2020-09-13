import java.util.Scanner;

public class banana {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
int k = in.nextInt();
int n = in.nextInt();
int w = in.nextInt();
int tmp = 0;
for (int i = 1; i <= w ; i++ ) {
	tmp = tmp + i*k; 
}
if ((tmp - n) > 0 ) {
	System.out.println(tmp - n);
}
else {System.out.println(0);
	}
	}

}
