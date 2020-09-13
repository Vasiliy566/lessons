package lesson1;
import java.util.Scanner;

public class prog1 {
	
	static // Ввод: 1 целое число N
	// Вывести : количество високостных лет на отрезке [0; N]
	// *** ВИСОКОСТНЫЙ ГОД ***
	// 1. год делится на 4 и не делится на 100
	// 2. год делится на 400 
	int findYear (int N) {
		int vYears = 0;
		for(int i = 1; i <= N; i ++ ) {
			boolean yearDel4 = ( ( i % 4 ) == 0); 
			boolean yearDel5 = ((i % 100) != 0);
			if ( ( yearDel4 && yearDel5 )  ||  ((i % 400) == 0)   ) {
				vYears ++;
				}
		}
		return (vYears);
	}
	 static int fastSolution(int N) {
		 return N / 4 - N / 100 + N / 400;
	 }
	public static void main(String[] args) {

		for(int N = 1; N < 10000; N ++ ) {
			if (findYear(N) !=  fastSolution(N)) {
				System.out.println(findYear(N) + " <> " + fastSolution(N));
			break;
			}
		}
		
			
	}
	
}
