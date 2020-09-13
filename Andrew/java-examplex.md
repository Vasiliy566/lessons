# Шпаргалка по java
### Чтение из файла
Читаем файл в FileReader в переменную fr
```
FileReader fr= new FileReader("file1.txt");
```
Создаем сканнер с входным потоком из файла
```
Scanner scan = new Scanner(fr);
```
Читаем строку из файла
```
String line1 = scan.nextLine()
```
Закрываем буффер ( не обязательно, но желательно)
```
scan.close()
```
### Перевод из одного типа данных в другой 
Перевод String в Integer
```
String line = "123";
int a = Integer.parseInt(line);
// теперь а = 123
```
### Разделение строки с пробелами на части
  Например нужно из строки "1 2 3" получить три числа
```
str = "1 2 3";
String[] splited = str.split("\\s+");
int a = Integer.parseInt(splited[0]);
int b = Integer.parseInt(splited[1]);
int c = Integer.parseInt(splited[2]);
// теперь а = 1, b = 2, c = 3
```
### Сортировка массива ( встроенная в java )
```
int[] a = {5, 4, 1, 2, 3};
Arrays.sort(a);
// теперь a = [1, 2, 3, 4, 5]
```
