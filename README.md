# Подготовительная программа по программированию на С/С++

## Домашнее задание №3
Реализация библиотеки для работы с матрицами.

В файле **_project/include/matrix.h_** представлен интерфейс реализуемой библиотеки.

### Интерфейс создания и уничтожения

* `struct Matrix` - основная структура библиотеки.
* `Matrix* create_matrix_from_file(const char* path_file)` - создание матрицы из файла. Принимает путь к файлу с матрицей.
Формат представления матрицы в файле:
```
<количество строк> <количество столбцов>
<перечисление всех элементов матрицы>
```
Пример:
```
2 3
1.1  2.3 4.5
-0.7 3.8 150.071
```

* `Matrix* create_matrix(int rows, int cols)` - создать пустую матрицу размера `<rows>*<cols>`.
* `void free_matrix(Matrix* matrix)` - освободить ресурсы, занимаемые матрицей.

### Базовые функции

* `int get_rows(const Matrix* matrix, size_t* rows)` - получить количество строк.
* `int get_cols(const Matrix* matrix, size_t* cols)` - получить количество столбцов.
* `int get_elem(const Matrix* matrix, int row, int col, double* val)` - получить значение элемента на позиции `[<row>, <col>]`
* `int set_elem(Matrix* matrix, int row, int col, double val)` - установить значение `val` элементу на позиции `[<row>, <col>]`

### Базовые математические операции

* `Matrix* mul_scalar(const Matrix* matrix, double val)` - скалярное умножение матрицы на действительное значение.
* `Matrix* transp(const Matrix* matrix)` - транспонирование матрицы.
* `Matrix* sum(const Matrix* l, const Matrix* r)` - сложение матриц.
* `Matrix* sub(const Matrix* l, const Matrix* r)` - вычитание матриц.
* `Matrix* mul(const Matrix* l, const Matrix* r)` - умножение матриц.

Определение математических операций над матрицами можно посмотреть на [вики](https://ru.wikipedia.org/wiki/%D0%9C%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0_(%D0%BC%D0%B0%D1%82%D0%B5%D0%BC%D0%B0%D1%82%D0%B8%D0%BA%D0%B0)).

### Дополнительные математические операции

* `int det(const Matrix* matrix, double* val)` - определитель матрицы ([вики](https://ru.wikipedia.org/wiki/%D0%9E%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B8%D1%82%D0%B5%D0%BB%D1%8C)).
* `Matrix* adj(const Matrix* matrix)` - присоединенная матрица ([вики](https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%8E%D0%B7%D0%BD%D0%B0%D1%8F_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0)).
* `Matrix* inv(const Matrix* matrix)` - обратная матрица ([вики](https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0)).

## Общая информация

* Функции интерфейса, возвращающие указатель, должны вернуть валидный указатель на `struct Matrix` в случае успеха и NULL -
в остальных случаях.
* Функции интерфейса, возвращающие `int`, должны вернуть `0` и, если требуется, записать результат в выходную переменную
в случае успеха; вернуть **ненулевое** значение в остальных случаях.

Критерии к оцениванию.
Максимально можно получить до 2 баллов.
1 балл, если:
- реализованы все базовые функции интерфейса, все соответствующие автоматические проверки на CI проходят;
- матрица реализована корректно (не через вектор векторов);
- во всех функциях проверяется корректность входных контрактов;
- нет копипасты (в частности, функции sum/sub реализованы через вспомогательную функцию, которая принимает указатель на функцию над парой элементов);
- сравнение вещественных чисел реализовано верно;
- используется единый стиль кодирования во всей программе, все переменные названы корректно;
- функциональный интерфейс библиотеки не изменён, все вспомогательные функции, не входящие в интерфейс, скрыты (внутреннее связывание);
- не используется cast для функций выделения памяти (malloc и аналогичные);
- нет магических констант (в частности, множество не связанных друг с другом define-ов - это тоже набор магических констант);
- все функции (например, scanf или реализованные самостоятельно) не используются, как процедуры.

2 балла - если реализовано всё, что требуется для получения "1 балла" с учётом ещё и дополнительных математических операций и всех проверок на CI, и:
- не используются операторы неструктурной передачи управления (break/continue/return внутри цикла и т.п.);
- вспомогательная память выделяется эффективно (в частности, заранее и не на каждой итерации цикла);
- возведение (-1) в степень реализовано эффективно.
