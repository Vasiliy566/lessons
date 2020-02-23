#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf ("%d", &n);
	int b = n * n;
	int c = n * n * n;
	int d = n + b + c;
	printf ("%d\n", b);
	printf ("%d\n", c);
	printf ("%d\n", d);

return 0;
}
