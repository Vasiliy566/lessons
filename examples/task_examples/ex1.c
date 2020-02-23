#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf ("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
	scanf ("%d", &arr[i]);
	}
	for(int i = 0; i < n; i ++)
	if ( arr[i] < 5)
		printf("%d ", arr[i]);
	
	return 0;

}