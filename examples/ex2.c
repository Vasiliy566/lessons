#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int n = 0;
	int b = 0;
	scanf("%d", &n);
	scanf("%d", &b);
	int a[n];
	int ar[b];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < b; j++)
	{
		scanf("%d", &ar[j]);
	}
	for (int i = 0; i < n; i++)
	{
		
		for(int j = 0; j < n; j ++)
		if ( a[i] == ar[j])
		{
			printf("%d", a[i]);
			break;
		}
	}
	
	
	return 0;

}