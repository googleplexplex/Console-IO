# WinConsole IO
### Обёртка низкоуровневых функций WinAPI для ускорения действий ввода/вывода


## **Reader.hpp**

*Импортирует **windows.h***

*Создает макрос **CONREADER***

Макросы ниже вызывают одноименные функции с приставкой **W**, если макрос **UNICODE** определён, иначе они будут вызывать одноименные функции с приставкой **A**.

-`getAllFromConsole`

-`getRectFromConsole`

-`getStringFromConsole`

-`getCharFromConsole`



`CHAR_INFO* getAllFromConsoleCI()` - возвращает буфер типа **CHAR_INFO**, содержащий все символы в консоли

`char* getAllFromConsoleA()` - возвращает буфер типа **char**, содержащий все символы в консоли

`char* getAllFromConsoleAN()` - возвращает буфер типа **char**, содержащий все символы в консоли, где новые строки разделены символом новой строки

`wchar_t* getAllFromConsoleW()` - возвращает буфер типа **wchar_t**, содержащий все символы в консоли

`wchar_t* getAllFromConsoleWN()` - возвращает буфер типа **wchar_t**, содержащий все символы в консоли, где новые строки разделены символом новой строки


`CHAR_INFO* getRectFromConsoleCI(SMALL_RECT& srctReadRect)` - возвращает буфер типа **CHAR_INFO**, содержащий все символы в консоли, которые находятся в области **srctReadRect**

`char* getRectFromConsoleA(SMALL_RECT& srctReadRect)` - возвращает буфер типа **char**, содержащий все символы консоли, которые находятся в области **srctReadRect**

`char* getRectFromConsoleAN(SMALL_RECT& srctReadRect)` - возвращает буфер типа **char**, содержащий все символы консоли, которые находятся в области **srctReadRect**, где новые строки разделены символом новой строки

`wchar_t* getRectFromConsoleW(SMALL_RECT& srctReadRect)` - возвращает буфер типа **wchar_t**, содержащий все символы консоли, которые находятся в области **srctReadRect**

`wchar_t* getRectFromConsoleWN(SMALL_RECT& srctReadRect)` - возвращает буфер типа **wchar_t**, содержащий все символы консоли, которые находятся в области **srctReadRect**, где новые строки разделены символом новой строки


`CHAR_INFO* getStringFromConsoleCI(COORD stringPos, short size)` - возвращает строку типа **CHAR_INFO** размера **size**, отображенную в консоли по позиции **stringPos**

`char* getStringFromConsoleA(COORD stringPos, short size, DWORD* out = NULL)` - возвращает строку типа char размера **size**, отображенную в консоли по позиции **stringPos**, где **out** означает количество символов, которые удалось считать

`wchar_t* getStringFromConsoleW(COORD stringPos, short size, DWORD* out = NULL)` - возвращает строку типа **wchar_t** размера **size**, отображенную в консоли по позиции **stringPos**, где **out** означает количество символов, которые удалось считать

`WORD* getAttributesFromConsole(COORD gettedPos, short size, DWORD* out = NULL)` - возвращает буфер атрибутов размера **size**, которые имеют символы в консоли по позиции **stringPos**, где **out** означает количество атрибутов, которые удалось считать


`CHAR_INFO getCharFromConsoleCI(COORD charsetPos)` - возвращает символ типа **CHAR_INFO**, отображенный в консоли по позиции **charsetPos**

`char getCharFromConsoleA(COORD charsetPos, DWORD* out = NULL)` - возвращает символ типа **char**, отображенный в консоли по позиции **charsetPos**, где **out** означает удалось ли выполнить эту операцию

`wchar_t getCharFromConsoleW(COORD charsetPos, DWORD* out = NULL)` - возвращает символ типа **wchar_t**, отображенный в консоли по позиции **charsetPos**, где **out** означает удалось ли выполнить эту операцию

`WORD getAttributesFromConsole(COORD gettedPos, DWORD* out = NULL)` - возвращает атрибут символа, отображенного в консоли по позиции **charsetPos**, где **out** означает удалось ли выполнить эту операцию



## **Разное:**

`HANDLE hStdout` - **HANDLE** консоли, из которой мы и читаем данные в функциях этой библиотеки.

`COORD getConsoleSize()` - Получение размера консоли структурой **COORD**.
