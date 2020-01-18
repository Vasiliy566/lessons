#include <stdio.h>

int main()
{
	int n = 0;
	scanf ("%d", &n);
	char str[n];
	scanf ("%s", str);

	int a = 0;
	int b = 0;
	for (int i = 0; i <= n; i++)
	{
		if (str[i] == 'S' and str[i+1] == 'F')
		{
			a++;
		}
		if (str[i] == 'F' and str[i+1] == 'S')
		{
			b++;
		}
	}
	if (a > b)
	{
		printf ("YES");
	}
	else 
	{
		printf ("NO");
	}
	return 0;

}












