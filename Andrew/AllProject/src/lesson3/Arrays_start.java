package lesson3;

import java.util.Arrays;
import java.util.Random;

public class Arrays_start {
	
	
	
	public static void printArray(int arr[]) {
		for (int i = 0; i < arr.length; ++i) {
			System.out.print(arr[i] + " ");
		}
	}

	public static int[] generateRandArray(int n) {

		Random rnd = new Random();
		int[] arr = new int[n];
		for (int i = 0; i < arr.length; ++i) {
			arr[i] = rnd.nextInt(200) - 100;
		}

		return arr;
	}

	public static boolean isSorted(int arr[]) {
		int[] tmp_arr = arr;
		Arrays.sort(tmp_arr);
		return Arrays.equals(tmp_arr, arr);
	}

	public static void test_bublesort(int[] arr) {
		final long startTime = System.nanoTime();
		
		int op = bublesort(arr);
		System.out.println("correct_status : " + isSorted(arr));
		System.out.println("time : " + (System.nanoTime() - startTime) * 0.000000001);
		System.out.println("operations : " + op);
		//return (System.nanoTime() - startTime);
	}
	public static void test_selectionSort(int[] arr) {
		final long startTime = System.nanoTime();
		
		selectionSort(arr);
		System.out.println("correct_status : " + isSorted(arr));
		System.out.println("time : " + (System.nanoTime() - startTime) * 0.000000001);
		//return (System.nanoTime() - startTime);
	}

	public static int[] sort_template(int[] arr) {

		// do somethink with arr

		return arr;
	}
	
	public static int my_min(int arr[], int start) {
		int min_index = start;
		for ( int i = start; i < arr.length; i ++ ) {	

			if (arr[i] < arr[min_index]) {
				min_index = i;
			}
		}
		
	return min_index;
		
	}
	
	public static int bublesort(int arr[]) {
		int n_operations = 0;
		boolean sorted = false ; 
		while (!sorted) {
			sorted = true;
			for ( int i = 0; i < arr.length - 1; i ++ ) {	
				if (arr[i] > arr [i+1]) {			
					int tmp = arr[i]; 
					arr[i] = arr[i+1];
					arr[i+1] = tmp;
					sorted = false;
				}
			}
			n_operations += arr.length - 1;
		}
		return n_operations;
	}
	public static int bcj(int arr[]){
		int n_operations = 0;
		boolean sorted = false ; 
		while (!sorted) {
			sorted = true;
			for ( int i = 0; i < arr.length - 1; i ++ ) {	
				if (arr[i] < arr [i+1]) {			
					int tmp = arr[i]; 
					arr[i] = arr[i+1];
					arr[i+1] = tmp;
					sorted = false;
				}
			}
			n_operations += arr.length - 1;
		}
		return n_operations;
		
	}
	public static void selectionSort(int arr[]) {
		int a = 0;
		//int b = arr.length;
		while (a < arr.length) {
			int min_i = my_min(arr, a);
			int tmp = arr [min_i];
			arr [ min_i ] = arr[a];
			arr[a] = tmp;	
			a ++;
		}
	
	}

	public static void main(String[] args) {

		int arr[] = generateRandArray(100000);
		int arr2[] = arr;
		
		test_bublesort(arr);
		
		test_selectionSort(arr2);
		
		

	}

}
