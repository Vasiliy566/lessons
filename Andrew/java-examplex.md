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
