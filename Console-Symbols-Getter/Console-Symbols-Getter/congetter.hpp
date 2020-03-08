#pragma once
#include <windows.h>

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

COORD getConSize() //Определение размера окна консоли
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
	short widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	short height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return { widht, height };
}

CHAR_INFO* getall_cb()
{
	// Все необходимое
	COORD consoleSize = getConSize();
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[consoleSize.Y * consoleSize.X];
	COORD coordBufSize;

	// Установим прямоугольник источника.
	srctReadRect.Top = 0;    // верхний левый: строчка 0, колонка 0
	srctReadRect.Left = 0;
	srctReadRect.Bottom = consoleSize.Y - 1; // нижний правый: строчка всего буфера Y - 1, колонка всего буфера X - 1
	srctReadRect.Right = consoleSize.X - 1;

	// Размер временного буфера равен размеру консоли.
	coordBufSize.Y = consoleSize.Y;
	coordBufSize.X = consoleSize.X;

	// Скопируем блок из экранного буфера во временный буфер.
	ReadConsoleOutput(
		hStdout,        	// экранный буфер, из которого читаем
		chiBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки chiBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в chiBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return chiBuffer;
}
char* getall_cbA()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getall_cb();
	COORD conSize = getConSize();
	size_t allConCharsCount = conSize.Y * conSize.X;
	char* ret_a = new char[allConCharsCount];

	//Обработка
	for (int i = 0; i < allConCharsCount; i++)
	{
		ret_a[i] = ret_ci[i].Char.AsciiChar;
	}

	return ret_a;
}
wchar_t* getall_cbU()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getall_cb();
	COORD conSize = getConSize();
	size_t allConCharsCount = conSize.Y * conSize.X;
	wchar_t* ret_u = new wchar_t[allConCharsCount];

	//Обработка
	for (int i = 0; i < allConCharsCount; i++)
	{
		ret_u[i] = ret_ci[i].Char.UnicodeChar;
	}

	return ret_u;
}

CHAR_INFO* gets_cb(short x, short y, short xsize, short ysize)
{
	//Всё необходимое
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[ysize * xsize];
	COORD coordBufSize;

	// Установим прямоугольник источника.
	srctReadRect.Top = y;    // верхний левый: строчка 0, колонка 0
	srctReadRect.Left = x;
	srctReadRect.Bottom = y + ysize - 1; // нижний правый: строчка всего буфера Y - 1, колонка всего буфера X - 1
	srctReadRect.Right = x + xsize - 1;

	// Размер временного буфера равен размеру консоли.
	coordBufSize.Y = ysize;
	coordBufSize.X = xsize;

	// Скопируем блок из экранного буфера во временный буфер.
	ReadConsoleOutput(
		hStdout,        	// экранный буфер, из которого читаем
		chiBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки chiBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в chiBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return chiBuffer;
}
char* gets_cbA(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = gets_cb(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	char* ret = new char[allRectCharsCount];

	//Обработка
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret[i] = ret_ci[i].Char.AsciiChar;
	}

	return ret;
}
wchar_t* gets_cbU(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = gets_cb(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	wchar_t* ret = new wchar_t[allRectCharsCount];

	//Обработка
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret[i] = ret_ci[i].Char.UnicodeChar;
	}

	return ret;
}

CHAR_INFO getc_cb(short x, short y)
{
	//Все необходимое
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[1];
	COORD coordBufSize;

	// Установим прямоугольник источника.
	srctReadRect.Top = y;    // верхний левый: строчка 0, колонка 0
	srctReadRect.Left = x;
	srctReadRect.Bottom = y + 1; // нижний правый: строчка всего буфера Y - 1, колонка всего буфера X - 1
	srctReadRect.Right = x + 1;

	// Размер временного буфера равен размеру консоли.
	coordBufSize.Y = x + 1;
	coordBufSize.X = y + 1;

	// Скопируем блок из экранного буфера во временный буфер.
	ReadConsoleOutput(
		hStdout,        	// экранный буфер, из которого читаем
		chiBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки chiBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в chiBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return chiBuffer[0];
}
char getc_cbA(short x, short y)
{
	//Просто возвращаем полученый элемент, но возвращаемого типа
	CHAR_INFO ret = getc_cb(x, y);
	return ret.Char.AsciiChar;
}
wchar_t getc_cbU(short x, short y)
{
	//Просто возвращаем полученый элемент, но возвращаемого типа
	CHAR_INFO ret = getc_cb(x, y);
	return ret.Char.UnicodeChar;
}