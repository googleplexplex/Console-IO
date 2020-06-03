#pragma once
#include <windows.h>

#define CONWRITER

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

void setAllConsole(CHAR_INFO filledChar)
{
	COORD consoleSize = getConsoleSize();
	SMALL_RECT srctReadRect = { 0, 0, consoleSize.X - 1, consoleSize.Y - 1 };
	COORD coordBufSize = { consoleSize.X - 1, consoleSize.Y - 1 };

	WriteConsoleOutputW(
		hStdout,        	//Screen buffer from which we read
		&filledChar,      	//Buffer to copy to
		coordBufSize,   		//Column / row size
		{ 0, 0 },  			//up left
		&srctReadRect); 	//Screen buffer source rectangle
}
void setAllConsole(char filledChar)
{
	//...
}
void setAllConsole(wchar_t filledChar)
{
	//...
}

void setRectInConsole(CHAR_INFO filledChar)
{
	//...
}
void setRectInConsole(char filledChar)
{
	//...
}
void setRectInConsole(wchar_t filledChar)
{
	//...
}
void setRectInConsole(CHAR_INFO* filledChar, int size)
{
	//...
}
void setRectInConsole(char* filledChar, int size)
{
	//...
}
void setRectInConsole(wchar_t* filledChar, int size)
{
	//...
}
void setRectInConsole(CHAR_INFO** filledChar, COORD size)
{
	//...
}
void setRectInConsole(char** filledChar, COORD size)
{
	//...
}
void setRectInConsole(wchar_t** filledChar, COORD size)
{
	//...
}

void setStringInConsole(CHAR_INFO filledChar)
{
	//...
}
void setStringInConsole(char filledChar)
{
	//...
}
void setStringInConsole(wchar_t filledChar)
{
	//...
}
void setStringInConsole(CHAR_INFO* filledChar, int size)
{
	//...
}
void setStringInConsole(char* filledChar, int size)
{
	//...
}
void setStringInConsole(wchar_t* filledChar, int size)
{
	//...
}

void setCharInConsole(CHAR_INFO charsetPos)
{
	//...
}
void setCharInConsole(char charsetPos)
{
	//...
}
void setCharInConsole(wchar_t charsetPos)
{
	//...
}