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



## **Writer.hpp**

*Импортирует **windows.h***

*Создает макрос **CONWRITER***

*Вводит следующие константы:*

char brushedAsciiChar - Полностью закрашенный ASCII символ

char emptyAsciiChar - Пустой ASCII символ

wchar_t brushedUnicodeChar - Полностью закрашенный символ в кодировке Юникод

wchar_t emptyUnicodeChar - Пустой символ в кодировке Юникод

WORD standartAttribute - Стандартный атрибут текста Windows консоли

CHAR_INFO brushedChaInfo - Полностью закрашенный символ

CHAR_INFO emptyCharInfo - Пустой символ

Макросы ниже вызывают одноименные функции с приставкой **W**, если макрос **UNICODE** определён, иначе они будут вызывать одноименные функции с приставкой **A**.

-`setAllConsole`

-`setRectInConsole`

-`setLineInConsole`

-`setStringInConsole`

-`setCharInConsole`


`void setAllConsoleCI(CHAR_INFO filledChar = emptyCharInfo)` - Заполняет всю консоль символом **filledChar**

`void setAllConsoleA(char filledChar = emptyAsciiChar, WORD filledCharAttribute = standartAttribute)` - Заполняет всю консоль символом **filledChar**, имеющим аттрибут **filledCharAttribute**

`void setAllConsoleW(wchar_t filledChar = emptyUnicodeChar, WORD filledCharAttribute = standartAttribute)` - Заполняет всю консоль символом **filledChar**, имеющим аттрибут **filledCharAttribute**


`void setRectInConsoleCI(SMALL_RECT& filledRect, CHAR_INFO filledChar = emptyCharInfo)` - Заполняет прямоугольную зону **filledRect** консоли символом **filledChar**

`void setRectInConsoleA(SMALL_RECT& filledRect, char filledChar = emptyAsciiChar, WORD filledCharAttribute = standartAttribute)` - Заполняет прямоугольную зону **filledRect** консоли символом **filledChar**, имеющим аттрибут **filledCharAttribute**

`void setRectInConsoleW(SMALL_RECT& filledRect, wchar_t filledChar = emptyUnicodeChar, WORD filledCharAttribute = standartAttribute)` - Заполняет прямоугольную зону **filledRect** консоли символом **filledChar**, имеющим аттрибут **filledCharAttribute**

`void setRectInConsoleCI(SMALL_RECT& printedRect, CHAR_INFO* printedString, int printedStringSize, CHAR_INFO emptyChar = emptyCharInfo)` - Заполняет прямоугольную зону **printedRect** консоли строкой **printedString**, имеющей размер **printedStringSize** и символ заполнения **emptyChar**

`void setRectInConsoleA(SMALL_RECT& printedRect, char* printedString, int printedStringSize, WORD printedStringAttributes = standartAttribute, CHAR_INFO emptyChar = emptyCharInfo)` - Заполняет прямоугольную зону **printedRect** консоли строкой **printedString** с атрибутом **printedStringAttributes**, имеющей размер **printedStringSize** и символ заполнения **emptyChar**

`void setRectInConsoleW(SMALL_RECT& printedRect, wchar_t* printedString, int printedStringSize, WORD printedStringAttributes = standartAttribute, CHAR_INFO emptyChar = emptyCharInfo)` - Заполняет прямоугольную зону **printedRect** консоли строкой **printedString** с атрибутом **printedStringAttributes**, имеющей размер **printedStringSize** и символ заполнения **emptyChar**


`void setLineInConsoleCI(COORD linePos, CHAR_INFO lineChar, short lineSize)` - Заполняет строку консоли, располагающуюся в **linePos** линией символов **lineChar** размером **lineSize**

`void setLineInConsoleA(COORD linePos, char lineChar, short lineSize, WORD lineCharAttribute = standartAttribute)` - Заполняет строку консоли, располагающуюся в **linePos** линией символов **lineChar** с атрибутами **lineCharAttribute** размером **lineSize**

`void setLineInConsoleW(COORD linePos, wchar_t lineChar, short lineSize, WORD lineCharAttribute = standartAttribute)` - Заполняет строку консоли, располагающуюся в **linePos** линией символов **lineChar** с атрибутами **lineCharAttribute** размером **lineSize**


`void setStringInConsoleCI(COORD stringPos, CHAR_INFO* filledChar, short stringSize)` - Отображает в консоли по позиции **stringPos** строку **filledChar** размером **stringSize**

`void setStringInConsoleA(COORD stringPos, char* filledChar, short stringSize, WORD filledCharAttribute = standartAttribute)` - Отображает в консоли по позиции **stringPos** строку **filledChar** с аттрибутом **filledCharAttribute** и размером **stringSize**

`void setStringInConsoleA(COORD stringPos, char* filledChar, WORD filledCharAttribute = standartAttribute)` - Отображает в консоли по позиции **stringPos** строку **filledChar** (Размер **filledChar** вычисляется функцией **strlen**)

`void setStringInConsoleW(COORD stringPos, wchar_t* filledChar, short stringSize, WORD filledCharAttribute = standartAttribute)` - Отображает в консоли по позиции **stringPos** строку **filledChar** с аттрибутом **filledCharAttribute** и размером **stringSize**

`void setStringInConsoleW(COORD stringPos, wchar_t* filledChar, WORD filledCharAttribute = standartAttribute)` - Отображает в консоли по позиции **stringPos** строку **filledChar** (Размер **filledChar** вычисляется функцией **wcslen**)


`void setCharInConsoleCI(COORD settedCharPos, CHAR_INFO settedChar = emptyCharInfo)` - Отображает в консоли символ **settedChar** по позиции **settedCharPos**

`void setCharInConsoleA(COORD settedCharPos, char settedChar = emptyAsciiChar, WORD settedCharAttribute = standartAttribute)` - Отображает в консоли символ **settedChar** с атрибутом **settedCharAttribute** по позиции **settedCharPos**

`void setCharInConsoleW(COORD settedCharPos, wchar_t settedChar = emptyUnicodeChar, WORD settedCharAttribute = standartAttribute)` - Отображает в консоли символ **settedChar** с атрибутом **settedCharAttribute** по позиции **settedCharPos**



## **Разное:**

`HANDLE hStdout` - **HANDLE** консоли, из которой мы и читаем данные в функциях этой библиотеки

`COORD getConsoleSize()` - Получение размера консоли структурой **COORD**

`T* getFilledBuffer(T fillElement, int bufferSize)` - Возвращает буфер размера **bufferSize** и типа **T**, заполненный элементом **fillElement**
