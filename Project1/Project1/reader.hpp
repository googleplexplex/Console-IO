#pragma once
#include <windows.h>

#define CONREADER

#ifdef UNICODE
	#define getAllFromConsole getAllFromConsoleW
	#define getRectFromConsole getRectFromConsoleW
	#define getStringFromConsole getStringFromConsoleW
	#define getCharFromConsole  getCharFromConsoleW
#else
	#define getAllFromConsole getAllFromConsoleA
	#define getRectFromConsole getRectFromConsoleA
	#define getStringFromConsole getStringFromConsoleA
	#define getCharFromConsole  getCharFromConsoleA
#endif

#ifndef CONWRITER
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

COORD getConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
	short widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	short height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return { widht, height };
}
#endif

CHAR_INFO* getAllFromConsoleCI()
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	CHAR_INFO* charBuffer = new CHAR_INFO[consoleSize.Y * consoleSize.X];
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };

	ReadConsoleOutput(
		hStdout,        	//Screen buffer from which we read
		charBuffer,      	//Buffer to copy to
		coordBufSize,   	//Column / row size
		{ 0, 0 },  			//up left
		&srctReadRect); 	//Screen buffer source rectangle

	return charBuffer;
}
char* getAllFromConsoleA()
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	int charsInConsoleCount = consoleSize.Y * consoleSize.X;
	CHAR_INFO* charBuffer = new CHAR_INFO[charsInConsoleCount];
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	char* result = new char[charsInConsoleCount];

	ReadConsoleOutputA(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < charsInConsoleCount; i++)
	{
		result[i] = charBuffer[i].Char.AsciiChar;
	}

	delete[] charBuffer;
	return result;
}
char* getAllFromConsoleAN()
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	int charsInConsoleCount = consoleSize.Y * consoleSize.X;
	CHAR_INFO* charBuffer = new CHAR_INFO[charsInConsoleCount];
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	char* result = new char[charsInConsoleCount];

	ReadConsoleOutputA(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < consoleSize.Y; i++)
	{
		bool lastIteration = (i == consoleSize.Y - 1);
		for (int j = 0; j < consoleSize.X; j++)
		{
			result[i * consoleSize.X + j + i] = charBuffer[i * consoleSize.X + j].Char.AsciiChar;
		}
		if (!lastIteration)
			result[i * consoleSize.X + consoleSize.X + i] = '\n';
	}
	result[charsInConsoleCount + consoleSize.Y - 1] = NULL;

	delete[] charBuffer;
	return result;
}
wchar_t* getAllFromConsoleW()
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	int charsInConsoleCount = consoleSize.Y * consoleSize.X;
	CHAR_INFO* charBuffer = new CHAR_INFO[charsInConsoleCount];
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	wchar_t* result = new wchar_t[charsInConsoleCount];

	ReadConsoleOutputW(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < charsInConsoleCount; i++)
	{
		result[i] = charBuffer[i].Char.UnicodeChar;
	}

	delete[] charBuffer;
	return result;
}
wchar_t* getAllFromConsoleWN()
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	int charsInConsoleCount = consoleSize.Y * consoleSize.X;
	CHAR_INFO* charBuffer = new CHAR_INFO[charsInConsoleCount];
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	wchar_t* result = new wchar_t[charsInConsoleCount];

	ReadConsoleOutputW(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < consoleSize.Y; i++)
	{
		bool lastIteration = (i == consoleSize.Y - 1);
		for (int j = 0; j < consoleSize.X; j++)
		{
			result[i * consoleSize.X + j + i] = charBuffer[i * consoleSize.X + j].Char.UnicodeChar;
		}
		if (!lastIteration)
			result[i * consoleSize.X + consoleSize.X + i] = '\n';
	}
	result[charsInConsoleCount + consoleSize.Y - 1] = NULL;

	delete[] charBuffer;
	return result;
}

CHAR_INFO* getRectFromConsoleCI(SMALL_RECT& srctReadRect)
{
	COORD coordBufSize = { srctReadRect.Right - srctReadRect.Left, srctReadRect.Bottom - srctReadRect.Top };
	CHAR_INFO* charBuffer = new CHAR_INFO[coordBufSize.X * coordBufSize.Y];

	ReadConsoleOutput(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	return charBuffer;
}
char* getRectFromConsoleA(SMALL_RECT& srctReadRect)
{
	COORD coordBufSize = { srctReadRect.Right - srctReadRect.Left, srctReadRect.Bottom - srctReadRect.Top };
	int allRectCharsCount = coordBufSize.X * coordBufSize.Y;
	CHAR_INFO* charInfoBuffer = new CHAR_INFO[allRectCharsCount];
	char* result = new char[allRectCharsCount + 1];

	ReadConsoleOutputA(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < allRectCharsCount + 1; i++)
	{
		result[i] = charInfoBuffer[i].Char.AsciiChar;
	}
	result[allRectCharsCount] = NULL;

	delete[] charInfoBuffer;
	return result;
}
char* getRectFromConsoleAN(SMALL_RECT& srctReadRect)
{
	COORD coordBufSize = { srctReadRect.Right - srctReadRect.Left, srctReadRect.Bottom - srctReadRect.Top };
	int allRectCharsCount = coordBufSize.X * coordBufSize.Y;
	CHAR_INFO* charInfoBuffer = new CHAR_INFO[allRectCharsCount];
	char* result = new char[allRectCharsCount + 1];

	ReadConsoleOutputA(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < coordBufSize.Y; i++)
	{
		bool lastIteration = (i == coordBufSize.Y - 1);
		for (int j = 0; j < coordBufSize.X; j++)
		{
			result[i * coordBufSize.X + j + i] = charInfoBuffer[i * coordBufSize.X + j].Char.AsciiChar;
		}
		if (!lastIteration)
			result[i * coordBufSize.X + coordBufSize.X + i] = '\n';
	}
	result[allRectCharsCount + coordBufSize.Y - 1] = NULL;

	delete[] charInfoBuffer;
	return result;
}
wchar_t* getRectFromConsoleW(SMALL_RECT& srctReadRect)
{
	COORD coordBufSize = { srctReadRect.Right - srctReadRect.Left, srctReadRect.Bottom - srctReadRect.Top };
	int allRectCharsCount = coordBufSize.X * coordBufSize.Y;
	CHAR_INFO* charInfoBuffer = new CHAR_INFO[allRectCharsCount];
	wchar_t* result = new wchar_t[allRectCharsCount + 1];

	ReadConsoleOutputW(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < allRectCharsCount + 1; i++)
	{
		result[i] = charInfoBuffer[i].Char.UnicodeChar;
	}
	result[allRectCharsCount] = NULL;

	delete[] charInfoBuffer;
	return result;
}
wchar_t* getRectFromConsoleWN(SMALL_RECT& srctReadRect)
{
	COORD coordBufSize = { srctReadRect.Right - srctReadRect.Left, srctReadRect.Bottom - srctReadRect.Top };
	int allRectCharsCount = coordBufSize.X * coordBufSize.Y;
	CHAR_INFO* charInfoBuffer = new CHAR_INFO[allRectCharsCount];
	wchar_t* result = new wchar_t[allRectCharsCount + 1];

	ReadConsoleOutputW(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	for (int i = 0; i < coordBufSize.Y; i++)
	{
		bool lastIteration = (i == coordBufSize.Y - 1);
		for (int j = 0; j < coordBufSize.X; j++)
		{
			result[i * coordBufSize.X + j + i] = charInfoBuffer[i * coordBufSize.X + j].Char.UnicodeChar;
		}
		if (!lastIteration)
			result[i * coordBufSize.X + coordBufSize.X + i] = '\n';
	}
	result[allRectCharsCount + coordBufSize.Y - 1] = NULL;

	delete[] charInfoBuffer;
	return result;
}

CHAR_INFO* getStringFromConsoleCI(COORD stringPos, int size)
{
	SMALL_RECT srctReadRect = { stringPos.X, stringPos.Y, stringPos.X + size + 1, stringPos.Y + 1 };
	CHAR_INFO* charBuffer = new CHAR_INFO[size];
	COORD coordBufSize = { size, 1 };

	ReadConsoleOutput(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);

	return charBuffer;
}
char* getStringFromConsoleA(COORD stringPos, int size, DWORD* out = NULL)
{
	LPSTR result = new char[size];
	ReadConsoleOutputCharacterA(hStdout, result, size, stringPos, out);

	return result;
}
wchar_t* getStringFromConsoleW(COORD stringPos, int size, DWORD* out = NULL)
{
	LPWSTR result = new wchar_t[size];
	ReadConsoleOutputCharacterW(hStdout, result, size, stringPos, out);

	return result;
}
WORD* getAttributesFromConsole(COORD gettedPos, int size, DWORD* out = NULL)
{
	WORD* result = new WORD[size];
	ReadConsoleOutputAttribute(hStdout, result, size, gettedPos, out);

	return result;
}

CHAR_INFO getCharFromConsoleCI(COORD charsetPos)
{
	SMALL_RECT srctReadRect = { charsetPos.X, charsetPos.Y, charsetPos.X + 1, charsetPos.Y + 1 };
	CHAR_INFO result;
	COORD coordBufSize = { 1, 1 };

	ReadConsoleOutput(hStdout, &result, coordBufSize, { 0, 0 }, &srctReadRect);

	return result;
}
char getCharFromConsoleA(COORD charsetPos, DWORD* out = NULL)
{
	char result;
	ReadConsoleOutputCharacterA(hStdout, &result, 1, charsetPos, out);

	return result;
}
wchar_t getCharFromConsoleW(COORD charsetPos, DWORD* out = NULL)
{
	wchar_t result;
	ReadConsoleOutputCharacterW(hStdout, &result, 1, charsetPos, out);

	return result;
}
WORD getAttributesFromConsole(COORD gettedPos, DWORD* out = NULL)
{
	WORD result;
	ReadConsoleOutputAttribute(hStdout, &result, 1, gettedPos, out);

	return result;
}