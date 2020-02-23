#include <stdio.h>
int main()
{
  int n = -1;
  scanf("%d", &n);
  int a[n]; // объявлен массив a из n элементов
 
  // Ввод элементов массива
  for (int i = 0; i<n; i++)
  { 
    printf("a[%d] = ", i);
    scanf("%d", &a[i]); // &a[i] - адрес i-го элемента массива
  }
  // Вывод элементов массива
  for (int i = 0; i<n; i++){
      printf("%d ", a[i]); // пробел в формате печати обязателен
    }
  }
  return 0;
