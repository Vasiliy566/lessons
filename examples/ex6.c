#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	int c = 0;
	scanf ("%d", &n);
	scanf ("%d", &c);
	int a[n];
	int ar[c];
	for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
	for (int j = 0; j < c; j++)
		{
			scanf("%d", &ar[j]);
		}
	for (int i = 0; i < n; i++){
		int flag = 0;
		for( int j = 0; j < c; j ++)
			if ( a[i] == ar[j])
			{
				flag = 1;
			}
		if( flag == 0)
			printf("%d ", a[i]);
	}
	return 0;
}