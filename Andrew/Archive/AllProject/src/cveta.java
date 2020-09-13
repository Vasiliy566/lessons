import java.util.Scanner;

public class cveta {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner in = new Scanner(System.in);
int n = Integer.parseInt( in.nextLine() );
String k = in.nextLine();

int[] arr = new int[n];
int tmp= 0 ;
for(int i = 0; i < n; i ++) {
	if (k.charAt(i) == 'R')
		arr[i] = 0;
	else if (k.charAt(i) == 'G')
		arr[i] = 1;
	else if (k.charAt(i) == 'B')
		arr[i] = 2;
}
for (int i = 0; i < n - 1; i ++) {
	if (arr[i] == arr[i+1])  
		tmp =  tmp + 1; 
}
System.out.println(tmp);

	}

}