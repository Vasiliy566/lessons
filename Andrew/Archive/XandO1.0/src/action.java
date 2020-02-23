import java.util.Scanner;

public class action {

	public static void main(String[] args) {
		table main_table = new table(3);
		Scanner scan = new Scanner(System.in);
		while(main_table.checkWinner()) {
			main_table.move(scan.nextInt(), scan.nextInt());
			main_table.show();
		}
	}

}
