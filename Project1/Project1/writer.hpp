#pragma once
#include <windows.h>

#define CONWRITER

#ifdef UNICODE
#define setAllConsole setAllConsoleW
#define setRectInConsole setRectInConsoleW
#define setLineInConsole setLineInConsoleW
#define setStringInConsole setStringInConsoleW
#define setCharInConsole setCharInConsoleW
#else
#define setAllConsole setAllConsoleA
#define setRectInConsole setRectInConsoleA
#define setLineInConsole setLineInConsoleA
#define setStringInConsole setStringInConsoleA
#define setCharInConsole setCharInConsoleA
#endif

#ifndef CONREADER
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

constexpr char brushedAsciiChar = (char)219;
constexpr char emptyAsciiChar = ' ';
constexpr wchar_t brushedUnicodeChar = (wchar_t)219;
constexpr wchar_t emptyUnicodeChar = (wchar_t)' ';
constexpr DWORD standartAttribute = 7;
constexpr CHAR_INFO brushedChaInfo = { brushedAsciiChar, standartAttribute };
constexpr CHAR_INFO emptyCharInfo = { emptyAsciiChar, standartAttribute };

template <typename T>
T* getFilledBuffer(T fillElement, int bufferSize)
{
	T* result = new T[bufferSize];

	//If sizeof(T) > sizeof(int), memset will not work
	for (int i = 0; i < bufferSize; i++)
	{
		result[i] = fillElement;
	}

	return result;
}


void setAllConsoleCI(CHAR_INFO filledChar = emptyCharInfo)
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	CHAR_INFO* charInfoBuffer = getFilledBuffer(filledChar, consoleSize.X * consoleSize.Y);

	WriteConsoleOutput(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setAllConsoleA(char filledChar = emptyAsciiChar, DWORD filledCharAttribute = standartAttribute)
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	int charsCountInConsole = consoleSize.X * consoleSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i].Attributes = filledCharAttribute;
		charInfoBuffer[i].Char.AsciiChar = filledChar;
	}

	WriteConsoleOutputA(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setAllConsoleW(wchar_t filledChar = emptyUnicodeChar, DWORD filledCharAttribute = standartAttribute)
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	COORD coordBufSize = { consoleSize.X, consoleSize.Y };
	int charsCountInConsole = consoleSize.X * consoleSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i].Attributes = filledCharAttribute;
		charInfoBuffer[i].Char.UnicodeChar = filledChar;
	}

	WriteConsoleOutputW(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}


void setRectInConsoleCI(SMALL_RECT& filledRect, CHAR_INFO filledChar = emptyCharInfo)
{
	COORD filledRectSize = { filledRect.Right - filledRect.Left, filledRect.Bottom - filledRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i] = filledChar;
	}

	WriteConsoleOutput(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &filledRect);
}

void setRectInConsoleA(SMALL_RECT& filledRect, char filledChar = emptyAsciiChar, DWORD filledCharAttribute = standartAttribute)
{
	COORD filledRectSize = { filledRect.Right - filledRect.Left, filledRect.Bottom - filledRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i].Char.AsciiChar = filledChar;
		charInfoBuffer[i].Attributes = filledCharAttribute;
	}

	WriteConsoleOutputA(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &filledRect);
}

void setRectInConsoleW(SMALL_RECT& filledRect, wchar_t filledChar = emptyUnicodeChar, DWORD filledCharAttribute = standartAttribute)
{
	COORD filledRectSize = { filledRect.Right - filledRect.Left, filledRect.Bottom - filledRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i].Char.UnicodeChar = filledChar;
		charInfoBuffer[i].Attributes = filledCharAttribute;
	}

	WriteConsoleOutputW(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &filledRect);
}

void setRectInConsoleCI(SMALL_RECT& printedRect, CHAR_INFO* printedString, int printedStringSize, CHAR_INFO emptyChar = emptyCharInfo)
{
	COORD filledRectSize = { printedRect.Right - printedRect.Left, printedRect.Bottom - printedRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < printedStringSize; i++)
	{
		charInfoBuffer[i] = printedString[i];
	}
	for (int i = printedStringSize; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i] = emptyChar;
	}

	WriteConsoleOutput(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &printedRect);
}

void setRectInConsoleA(SMALL_RECT& printedRect, char* printedString, int printedStringSize, DWORD printedStringAttributes = standartAttribute, CHAR_INFO emptyChar = emptyCharInfo)
{
	COORD filledRectSize = { printedRect.Right - printedRect.Left, printedRect.Bottom - printedRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < printedStringSize; i++)
	{
		charInfoBuffer[i].Char.AsciiChar = printedString[i];
		charInfoBuffer[i].Attributes = printedStringAttributes;
	}
	for (int i = printedStringSize; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i] = emptyChar;
	}

	WriteConsoleOutputA(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &printedRect);
}

void setRectInConsoleW(SMALL_RECT& printedRect, wchar_t* printedString, int printedStringSize, DWORD printedStringAttributes = standartAttribute, CHAR_INFO emptyChar = emptyCharInfo)
{
	COORD filledRectSize = { printedRect.Right - printedRect.Left, printedRect.Bottom - printedRect.Top };
	int charsCountInConsole = filledRectSize.X * filledRectSize.Y;

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[charsCountInConsole];
	for (int i = 0; i < printedStringSize; i++)
	{
		charInfoBuffer[i].Char.UnicodeChar = printedString[i];
		charInfoBuffer[i].Attributes = printedStringAttributes;
	}
	for (int i = printedStringSize; i < charsCountInConsole; i++)
	{
		charInfoBuffer[i] = emptyChar;
	}

	WriteConsoleOutputW(hStdout, charInfoBuffer, filledRectSize, { 0, 0 }, &printedRect);
}


void setLineInConsoleCI(COORD linePos, CHAR_INFO lineChar, int lineSize)
{
	SMALL_RECT srctReadRect = { linePos.X, linePos.Y, linePos.X + lineSize, linePos.Y + 1 };
	COORD coordBufSize = { lineSize, 1 };
	CHAR_INFO* charInfoBuffer = getFilledBuffer(lineChar, lineSize);

	WriteConsoleOutput(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setLineInConsoleA(COORD linePos, char lineChar, int lineSize, DWORD lineCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { linePos.X, linePos.Y, linePos.X + lineSize, linePos.Y + 1 };
	COORD coordBufSize = { lineSize, 1 };

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[lineSize];
	for (int i = 0; i < lineSize; i++)
	{
		charInfoBuffer[i].Char.AsciiChar = lineChar;
		charInfoBuffer[i].Attributes = lineCharAttribute;
	}

	WriteConsoleOutputA(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setLineInConsoleW(COORD linePos, wchar_t lineChar, int lineSize, DWORD lineCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { linePos.X, linePos.Y, linePos.X + lineSize, linePos.Y + 1 };
	COORD coordBufSize = { lineSize, 1 };

	CHAR_INFO* charInfoBuffer = new CHAR_INFO[lineSize];
	for (int i = 0; i < lineSize; i++)
	{
		charInfoBuffer[i].Char.UnicodeChar = lineChar;
		charInfoBuffer[i].Attributes = lineCharAttribute;
	}

	WriteConsoleOutputW(hStdout, charInfoBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}


void setStringInConsoleCI(COORD stringPos, CHAR_INFO* filledChar, int stringSize)
{
	SMALL_RECT srctReadRect = { stringPos.X, stringPos.Y, stringPos.X + stringSize, stringPos.Y + 1 };
	COORD coordBufSize = { stringSize, 1 };

	WriteConsoleOutput(hStdout, filledChar, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setStringInConsoleA(COORD stringPos, char* filledChar, int stringSize, DWORD filledCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { stringPos.X, stringPos.Y, stringPos.X + stringSize, stringPos.Y + 1 };
	COORD coordBufSize = { stringSize, 1 };

	CHAR_INFO* charBuffer = new CHAR_INFO[stringSize];
	for (int i = 0; i < stringSize; i++)
	{
		charBuffer[i].Char.AsciiChar = filledChar[i];
		charBuffer[i].Attributes = filledCharAttribute;
	}

	WriteConsoleOutputA(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setStringInConsoleW(COORD stringPos, wchar_t* filledChar, int stringSize, DWORD filledCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { stringPos.X, stringPos.Y, stringPos.X + stringSize, stringPos.Y + 1 };
	COORD coordBufSize = { stringSize, 1 };

	CHAR_INFO* charBuffer = new CHAR_INFO[stringSize];
	for (int i = 0; i < stringSize; i++)
	{
		charBuffer[i].Char.UnicodeChar = filledChar[i];
		charBuffer[i].Attributes = filledCharAttribute;
	}

	WriteConsoleOutputW(hStdout, charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}


void setCharInConsoleCI(COORD settedCharPos, CHAR_INFO settedChar)
{
	SMALL_RECT srctReadRect = { settedCharPos.X, settedCharPos.Y, settedCharPos.X + 1, settedCharPos.Y + 1 };
	COORD coordBufSize = { 1, 1 };

	WriteConsoleOutput(hStdout, &settedChar, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setCharInConsoleA(COORD settedCharPos, char settedChar, DWORD settedCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { settedCharPos.X, settedCharPos.Y, settedCharPos.X + 1, settedCharPos.Y + 1 };
	COORD coordBufSize = { 1, 1 };

	CHAR_INFO charBuffer = { settedChar, settedCharAttribute };

	WriteConsoleOutputA(hStdout, &charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}

void setCharInConsoleW(COORD settedCharPos, wchar_t settedChar, DWORD settedCharAttribute = standartAttribute)
{
	SMALL_RECT srctReadRect = { settedCharPos.X, settedCharPos.Y, settedCharPos.X + 1, settedCharPos.Y + 1 };
	COORD coordBufSize = { 1, 1 };

	CHAR_INFO charBuffer = { settedChar, settedCharAttribute };

	WriteConsoleOutputW(hStdout, &charBuffer, coordBufSize, { 0, 0 }, &srctReadRect);
}