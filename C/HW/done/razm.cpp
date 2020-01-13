#include <stdio.h>

int main()
{
int n = 0;
scanf("%d", &n);
int a = 0;
int b = 0;

a = n / 100;
b = n % 100;
if (b == 0)
{
	printf ("%d \n", a);
	return 0;
}
a += b / 20;
b = b % 20;
if (b == 0)
{
	printf ("%d \n", a);
	return 0;
}
a += b / 10;
b = b % 10;
if (b == 0)
{
	printf ("%d \n", a);
	return 0;
}
a += b / 5;
b = b % 5;
if (b == 0)
{
	printf ("%d \n", a);
	return 0;
}
a += b / 1;
b = b % 1;
if (b == 0)
{
	printf ("%d \n", a);
	return 0;
}
return 0;




}










