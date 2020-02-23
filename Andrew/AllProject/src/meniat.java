import java.util.Scanner;

public class meniat {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		String input = in.nextLine();
		int k = 0;
		if (input.equals("0")) {
			System.out.print(0);
		} else {
			
			for (int i = 0; i < input.length(); i++) {
				if(input.charAt(i) == '1') {
					k++;
				}
			}

			System.out.print(1);
			for (int i = 0; i < n - k ; i++)

				System.out.print(0);
		}
	}

}
