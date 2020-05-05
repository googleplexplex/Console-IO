# Console-Symbols-Getter
### Маленькая библиотека, позволяющая доставать символы в двух кодировках прямо из Windows консоли без создания двухмерного массива и перегрузки ввода/вывода.


##### Основные функции:

`CHAR_INFO* getAll_fromConsole()` - Получение всего написанного в консоли.

`CHAR_INFO* getRect_fromConsole(short x, short y, short xsize, short ysize)` - Получение написанного на позиции **x**, **y** в консоли прямоугольника из символов размера **xsize**, **ysize**.

`CHAR_INFO* gets_fromConsole(short x, short y, short xsize)` - Получение написанной на позиции **x**, **y** в консоли строки размера **xsize**.

`CHAR_INFO getc_fromConsole(short x, short y)` - Получение написанного на позиции **x**, **y** в консоли символа.

Все приведенные выше функции возвращают данные в виде определенной в **Windows.h** структуры **CHAR_INFO**, если необходимо получить не структуру **CHAR_INFO**, а конкретный тип символа/строки, то каждый из вышеперечисленных методов выше имеют аналоги с постфиксами.

**A** - Если необходимо получить символ/строку в кодировке *ASCII* (**char** тип),

**U** - Если необходимо получить символ/строку в кодировке *Unicode* (**wchar_t** тип).

**N** - Если необходимо чтобы переходы на новую строку помечались символом новой строки.

##### Аналоги:

`char* getAll_fromConsoleA()`

`char* getAll_fromConsoleAN()`

`wchar_t* getAll_fromConsoleU()`

`wchar_t* getAll_fromConsoleUN()`

`char* getRect_fromConsoleA(short x, short y, short xsize, short ysize)`

`char* getRect_fromConsoleAN(short x, short y, short xsize, short ysize)`

`wchar_t* getRect_fromConsoleU(short x, short y, short xsize, short ysize)`

`wchar_t* getRect_fromConsoleUN(short x, short y, short xsize, short ysize)`

`char* gets_fromConsoleA(short x, short y, short xsize)`

`wchar_t* gets_fromConsoleU(short x, short y, short xsize)`

`char getc_fromConsoleA(short x, short y)`

`wchar_t getc_fromConsoleU(short x, short y)`


##### Разное:

`HANDLE hStdout` - **HANDLE** консоли, из которой мы и читаем данные в функциях этой библиотеки.

`COORD getConsoleSize()` - Получение размера консоли структурой **COORD**.
