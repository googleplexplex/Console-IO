#pragma once
#include <windows.h>

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

COORD getConsoleSize() //Определение размера окна консоли
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
	short widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	short height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return { widht, height };
}

CHAR_INFO* getAll_fromConsole()
{
	// Все необходимое
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect;
	CHAR_INFO* charBuffer = new CHAR_INFO[consoleSize.Y * consoleSize.X];
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
		charBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки charBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в charBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return charBuffer;
}
char* getAll_fromConsoleA()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getAll_fromConsole();
	COORD consoleSize = getConsoleSize();
	size_t allConsleCharsCount = consoleSize.Y * consoleSize.X;
	char* ret_a = new char[allConsleCharsCount];

	//Обработка
	for (int i = 0; i < allConsleCharsCount; i++)
	{
		ret_a[i] = ret_ci[i].Char.AsciiChar;
	}

	return ret_a;
}
char* getAll_fromConsoleAN()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getAll_fromConsole();
	COORD consoleSize = getConsoleSize();
	size_t allConsleCharsCount = consoleSize.Y * consoleSize.X;
	char* ret_a = new char[allConsleCharsCount + consoleSize.Y];

	//Обработка
	for (int i = 0; i < consoleSize.Y; i++)
	{
		bool lastIteration = (i == consoleSize.Y - 1);
		for (int j = 0; j < consoleSize.X; j++)
		{
			ret_a[i * consoleSize.X + j + i] = ret_ci[i * consoleSize.X + j].Char.AsciiChar;
		}
		if (!lastIteration)
			ret_a[i * consoleSize.X + consoleSize.X + i] = '\n';
	}
	ret_a[allConsleCharsCount + consoleSize.Y - 1] = NULL;

	return ret_a;
}
wchar_t* getAll_fromConsoleU()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getAll_fromConsole();
	COORD consoleSize = getConsoleSize();
	size_t allConsleCharsCount = consoleSize.Y * consoleSize.X;
	wchar_t* ret_u = new wchar_t[allConsleCharsCount];

	//Обработка
	for (int i = 0; i < allConsleCharsCount; i++)
	{
		ret_u[i] = ret_ci[i].Char.UnicodeChar;
	}

	return ret_u;
}
wchar_t* getAll_fromConsoleUN()
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getAll_fromConsole();
	COORD consoleSize = getConsoleSize();
	size_t allConsleCharsCount = consoleSize.Y * consoleSize.X;
	wchar_t* ret_u = new wchar_t[allConsleCharsCount];

	//Обработка
	for (int i = 0; i < consoleSize.Y; i++)
	{
		bool lastIteration = (i == consoleSize.Y - 1);
		for (int j = 0; j < consoleSize.X; j++)
		{
			ret_u[i * consoleSize.X + j + i] = ret_ci[i * consoleSize.X + j].Char.UnicodeChar;
		}
		if (!lastIteration)
			ret_u[i * consoleSize.X + consoleSize.X + i] = '\n';
	}
	ret_u[allConsleCharsCount + consoleSize.Y - 1] = NULL;

	return ret_u;
}

CHAR_INFO* getRect_fromConsole(short x, short y, short xsize, short ysize)
{
	//Всё необходимое
	SMALL_RECT srctReadRect;
	CHAR_INFO* charBuffer = new CHAR_INFO[ysize * xsize];
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
		charBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки charBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в charBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return charBuffer;
}
char* getRect_fromConsoleA(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getRect_fromConsole(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	char* ret_a = new char[allRectCharsCount + 1];

	//Обработка
	for (int i = 0; i < allRectCharsCount + 1; i++)
	{
		ret_a[i] = ret_ci[i].Char.AsciiChar;
	}
	ret_a[allRectCharsCount] = NULL;

	return ret_a;
}
char* getRect_fromConsoleAN(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getRect_fromConsole(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	char* ret_a = new char[allRectCharsCount + ysize];

	//Обработка
	for (int i = 0; i < ysize; i++)
	{
		bool lastIteration = (i == ysize - 1);
		for (int j = 0; j < xsize; j++)
		{
			ret_a[i * xsize + j + i] = ret_ci[i * xsize + j].Char.AsciiChar;
		}
		if (!lastIteration)
			ret_a[i * xsize + xsize + i] = '\n';
	}
	ret_a[allRectCharsCount + ysize - 1] = NULL;

	return ret_a;
}
wchar_t* getRect_fromConsoleU(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getRect_fromConsole(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	wchar_t* ret_u = new wchar_t[allRectCharsCount + 1];

	//Обработка
	for (int i = 0; i < allRectCharsCount + 1; i++)
	{
		ret_u[i] = ret_ci[i].Char.UnicodeChar;
	}
	ret_u[allRectCharsCount] = NULL;

	return ret_u;
}
wchar_t* getRect_fromConsoleUN(short x, short y, short xsize, short ysize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = getRect_fromConsole(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	wchar_t* ret_u = new wchar_t[allRectCharsCount + ysize];

	//Обработка
	for (int i = 0; i < ysize; i++)
	{
		bool lastIteration = (i == ysize - 1);
		for (int j = 0; j < xsize; j++)
		{
			ret_u[i * xsize + j + i] = ret_ci[i * xsize + j].Char.UnicodeChar;
		}
		if (!lastIteration)
			ret_u[i * xsize + xsize + i] = '\n';
	}
	ret_u[allRectCharsCount + ysize - 1] = NULL;

	return ret_u;
}

CHAR_INFO* gets_fromConsole(short x, short y, short xsize)
{
	//Всё необходимое
	SMALL_RECT srctReadRect;
	CHAR_INFO* charBuffer = new CHAR_INFO[xsize];
	COORD coordBufSize;

	// Установим прямоугольник источника.
	srctReadRect.Top = y;    // верхний левый: строчка 0, колонка 0
	srctReadRect.Left = x;
	srctReadRect.Bottom = y + 1; // нижний правый: строчка всего буфера Y - 1, колонка всего буфера X - 1
	srctReadRect.Right = x + xsize - 1;

	// Размер временного буфера равен размеру консоли.
	coordBufSize.Y = 1;
	coordBufSize.X = xsize;

	// Скопируем блок из экранного буфера во временный буфер.
	ReadConsoleOutput(
		hStdout,        	// экранный буфер, из которого читаем
		charBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки charBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в charBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return charBuffer;
}
char* gets_fromConsoleA(short x, short y, short xsize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = gets_fromConsole(x, y, xsize);
	int allRectCharsCount = xsize;
	char* ret_a = new char[allRectCharsCount + 1];

	//Обработка
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret_a[i] = ret_ci[i].Char.AsciiChar;
	}
	ret_a[allRectCharsCount] = NULL;

	return ret_a;
}
wchar_t* gets_fromConsoleU(short x, short y, short xsize)
{
	//Все необходимое для обработки
	CHAR_INFO* ret_ci = gets_fromConsole(x, y, xsize);
	int allRectCharsCount = xsize;
	wchar_t* ret_u = new wchar_t[allRectCharsCount + 1];

	//Обработка
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret_u[i] = ret_ci[i].Char.UnicodeChar;
	}
	ret_u[allRectCharsCount] = NULL;

	return ret_u;
}

CHAR_INFO getc_fromConsole(short x, short y)
{
	//Все необходимое
	SMALL_RECT srctReadRect;
	CHAR_INFO* charBuffer = new CHAR_INFO[1];
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
		charBuffer,      	// буфер, в который копируем
		coordBufSize,   	// размер колонки/строки charBuffer
		{ 0, 0 },  	// верхняя левая ячейка назначения в charBuffer
		&srctReadRect); 	// источниковый прямоугольник экранного буфера

	return charBuffer[0];
}
char getc_fromConsoleA(short x, short y)
{
	//Просто возвращаем полученый элемент, но возвращаемого типа
	return getc_fromConsole(x, y).Char.AsciiChar;
}
wchar_t getc_fromConsoleU(short x, short y)
{
	//Просто возвращаем полученый элемент, но возвращаемого типа
	return getc_fromConsole(x, y).Char.UnicodeChar;
}