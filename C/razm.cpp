#include <stdio.h>

int main()
{
	int n=0;
	scanf ("%d", &n);
	char str[n];
	scanf("%s", str);

	int b = 0;
	int a = 0;
	for (int i = 0; i <= n; i++)
	{

	if (str[i] == 'z')
		{
			b++;
		}
	if (str[i] == 'n')
		{
			a++;
		}
	}


for (int i = 0; i <a; i++)
	printf ("1 ");
for (int i = 0; i <b; i++)
	printf ("0 ");

return 0;
}










