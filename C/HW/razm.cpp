#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n, k, i;
	scanf ("%d", &n);
	int a = 0;
	for (i=0; i < n; i++)
	{
		scanf ("%d", &k);
		if ( k != 0)
		{
			a = 1;
		}
	}
	if ( a == 0)
	{
		printf ("EASY");
	}
	else 
	{
		printf ("HARD");

	}
	return 0;

}





