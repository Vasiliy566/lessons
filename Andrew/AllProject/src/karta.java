import java.util.Scanner;

public class karta {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
String input = in.nextLine();
char x = input.charAt(0);
char y = input.charAt(1);
int tmp = 0;
String input1 = in.nextLine();
for (int i = 0; i <= 13; i +=3) {	
	char x1 = input1.charAt(i);
	char y1 = input1.charAt(i+1);
	if (x1 == x || y1 == y ) {
		 tmp++;
	}
	}
if (tmp != 0 ) {
	System.out.println("YES");
	}
else {
	System.out.println("NO");
}
}
	}


