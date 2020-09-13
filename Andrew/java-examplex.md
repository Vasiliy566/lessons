# Шпоргалка по java
### Чтение из файла
Читаем файл в переменную file
```
File file = new File("./text.txt");
```
Создаем буффер для чтения из файла
```
BufferedReader reader = new BufferedReader(new FileReader(file));
```
Читаем строку из файла
```
String line1 = reader.readLine();
```
Закрываем буффер ( не обязательно, но желательно)
```
br.close();
```
