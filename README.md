# Console-Symbols-Getter
Маленькая библиотека, позволяющая доставать символы в двух кодировках прямо из Windows консоли без создания двухмерного массива и перегрузки ввода/вывода.

Основные функции:
CHAR_INFO* getall_cb() - Получение всего написанного в консоли.
CHAR_INFO* gets_cb(short x, short y, short xsize, short ysize) - Получение написанной на позиции x, y в консоли строки размера xsize, ysize.
CHAR_INFO getc_cb(short x, short y) - Получение написанного на позиции x, y в консоли символа.

Все приведенные выше функции возвращают данные в виде определенной в Windows.h структуры CHAR_INFO, если необходимо получить не структуру CHAR_INFO, а конкретный тип символа/строки, то каждый из вышеперечисленных методов выше имеют аналоги с постфиксами. A - Если необходимо получить символ/строку в кодировке ASCII (char тип), U - Если необходимо получить символ/строку в кодировке Unicode (wchar_t тип).

Аналоги:
char* getall_cbA();
wchar_t* getall_cbU();
char* gets_cbA(short x, short y, short xsize, short ysize);
wchar_t* gets_cbU(short x, short y, short xsize, short ysize);
char getc_cbA(short x, short y);
wchar_t getc_cbU(short x, short y);

Разное:
HANDLE hStdout - HANDLE консоли, из которой мы и читаем данные в функциях этой библиотеки.
COORD getConSize() - Получение размера консоли структурой COORD.
