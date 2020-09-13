import java.util.Scanner;

public class localMax {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		int tmp = 0;
		int i = 0;
		int a = 0;

		// блок инициализации
		int pred = in.nextInt();
		if (pred == 0) {
			System.out.println(0);
			
		} else {
			int now = in.nextInt();
			if (now == 0) {
				System.out.println(0);
			} else {
				int next = in.nextInt();
				if (next == 0) {
					System.out.println(0);
				} else {
					do {

						if (now > pred && now > next)
							i++;
						
						pred = now;
						now = next;
						next = in.nextInt();
						

					} while (next != 0);
					
					System.out.println(i);
				}
			}
		}
	}
}
