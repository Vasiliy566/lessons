/*******************
 printf 
 source: http://www.cplusplus.com/
********************/
#include <stdio.h>
int main() {
	printf ("Символы: %c %c \n", 'a', 65);
	printf ("Числа: %d \n", 1977);
	printf ("Разные форматы: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("Числа с плавающей точкой: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("%s \n", "Строка");
}
