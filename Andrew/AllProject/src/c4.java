import java.util.Scanner;

public class c4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
 Scanner in = new Scanner(System.in);
 int n = in.nextInt();
 int tmp = 0;
 in.nextLine();
 for(int i = 0; i<n; i++) {
	
	String s = in.nextLine(); 

	 switch (s.charAt(0)) {
		 case 'c': { 
			 tmp += 6;
		break;	 
		 }
		 case 't': { 
			 tmp += 4;
		break;	 
	 }
		 case 'o': { 
			 tmp += 8;
		break;	 
 }
		 case 'd': { 
			 tmp += 12;
		break;	 
	}
		 case 'I': { 
			 tmp += 20;
		break;	 	 
}
}
}
 System.out.println(tmp);
	
	}}
