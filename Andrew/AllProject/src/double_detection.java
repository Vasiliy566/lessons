import java.util.Scanner;

public class double_detection {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = in.nextInt();
		}
		// цикл удаления повторов
		
		for (int i = 0; i < n; i++) {
			int tmp = arr[i];
			for (int j = i + 1; j < n; j++) {
				if (tmp == arr[j]) {
					arr[i] = -1;
					
				}
			}
		}
		int m = 0;
		for(int i = 0; i < n; i ++) {
			if (arr[i] == -1)
					m ++;
		}
		System.out.println(n - m);
		for (int i = 0; i < n; i++) {
			if (arr[i] != -1) {
				System.out.print(arr[i] + " ");
			}
		}
	}

}
