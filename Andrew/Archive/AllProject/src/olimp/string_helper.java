package olimp;


import java.util.Arrays;
import java.util.Scanner;

public class string_helper {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String data = scan.nextLine();
		int a = 0;
		int b = 0;
		String c;
		int stringSize = data.length();
		for (int i = 0; i < stringSize; i++) {
			if (Character.isLowerCase(data.charAt(i))) {
				a ++;
			}
			else {
				b++;
			}
		}
 if (a >= b) { 
	 c = data.toLowerCase();
	 System.out.println(c);
 }
 if (a < b) { 
	 c = data.toUpperCase();
	 System.out.println(c);
	}

	}}
