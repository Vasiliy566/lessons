#include <stdio.h>
#include <stdlib.h>
int compare_int(const void* a, const void *b){
	const int *a1 = a;
	const int *a2 = b;
	return *a1 - *a2;
}
int compare_int_revers(const void* a, const void *b){
	const int *a1 = a;
	const int *a2 = b;
	return *a2 - *a1 ;
}
int main()
{
	int n = 0;
	scanf ("%d",&n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &arr[i]);
	}

	int size = sizeof arr / sizeof *arr;
	qsort(arr, size, sizeof(int), compare_int);

	for (int i = 0; i < size; i++)
		printf ("%d", arr[i]);

	printf ("\n");
		qsort(arr, size, sizeof(int), compare_int_revers);

	for (int i = 0; i < size; i++)
		printf ("%d", arr[i]);

	printf ("\n");

	return 0;

}