#pragma once
#include <windows.h>

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

COORD getConSize() //����������� ������� ���� �������
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
	short widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	short height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return { widht, height };
}

CHAR_INFO* getall_cb()
{
	// ��� �����������
	COORD consoleSize = getConSize();
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[consoleSize.Y * consoleSize.X];
	COORD coordBufSize;

	// ��������� ������������� ���������.
	srctReadRect.Top = 0;    // ������� �����: ������� 0, ������� 0
	srctReadRect.Left = 0;
	srctReadRect.Bottom = consoleSize.Y - 1; // ������ ������: ������� ����� ������ Y - 1, ������� ����� ������ X - 1
	srctReadRect.Right = consoleSize.X - 1;

	// ������ ���������� ������ ����� ������� �������.
	coordBufSize.Y = consoleSize.Y;
	coordBufSize.X = consoleSize.X;

	// ��������� ���� �� ��������� ������ �� ��������� �����.
	ReadConsoleOutput(
		hStdout,        	// �������� �����, �� �������� ������
		chiBuffer,      	// �����, � ������� ��������
		coordBufSize,   	// ������ �������/������ chiBuffer
		{ 0, 0 },  	// ������� ����� ������ ���������� � chiBuffer
		&srctReadRect); 	// ������������ ������������� ��������� ������

	return chiBuffer;
}
char* getall_cbA()
{
	//��� ����������� ��� ���������
	CHAR_INFO* ret_ci = getall_cb();
	COORD conSize = getConSize();
	size_t allConCharsCount = conSize.Y * conSize.X;
	char* ret_a = new char[allConCharsCount];

	//���������
	for (int i = 0; i < allConCharsCount; i++)
	{
		ret_a[i] = ret_ci[i].Char.AsciiChar;
	}

	return ret_a;
}
wchar_t* getall_cbU()
{
	//��� ����������� ��� ���������
	CHAR_INFO* ret_ci = getall_cb();
	COORD conSize = getConSize();
	size_t allConCharsCount = conSize.Y * conSize.X;
	wchar_t* ret_u = new wchar_t[allConCharsCount];

	//���������
	for (int i = 0; i < allConCharsCount; i++)
	{
		ret_u[i] = ret_ci[i].Char.UnicodeChar;
	}

	return ret_u;
}

CHAR_INFO* gets_cb(short x, short y, short xsize, short ysize)
{
	//�� �����������
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[ysize * xsize];
	COORD coordBufSize;

	// ��������� ������������� ���������.
	srctReadRect.Top = y;    // ������� �����: ������� 0, ������� 0
	srctReadRect.Left = x;
	srctReadRect.Bottom = y + ysize - 1; // ������ ������: ������� ����� ������ Y - 1, ������� ����� ������ X - 1
	srctReadRect.Right = x + xsize - 1;

	// ������ ���������� ������ ����� ������� �������.
	coordBufSize.Y = ysize;
	coordBufSize.X = xsize;

	// ��������� ���� �� ��������� ������ �� ��������� �����.
	ReadConsoleOutput(
		hStdout,        	// �������� �����, �� �������� ������
		chiBuffer,      	// �����, � ������� ��������
		coordBufSize,   	// ������ �������/������ chiBuffer
		{ 0, 0 },  	// ������� ����� ������ ���������� � chiBuffer
		&srctReadRect); 	// ������������ ������������� ��������� ������

	return chiBuffer;
}
char* gets_cbA(short x, short y, short xsize, short ysize)
{
	//��� ����������� ��� ���������
	CHAR_INFO* ret_ci = gets_cb(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	char* ret = new char[allRectCharsCount];

	//���������
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret[i] = ret_ci[i].Char.AsciiChar;
	}

	return ret;
}
wchar_t* gets_cbU(short x, short y, short xsize, short ysize)
{
	//��� ����������� ��� ���������
	CHAR_INFO* ret_ci = gets_cb(x, y, xsize, ysize);
	int allRectCharsCount = ysize * xsize;
	wchar_t* ret = new wchar_t[allRectCharsCount];

	//���������
	for (int i = 0; i < allRectCharsCount; i++)
	{
		ret[i] = ret_ci[i].Char.UnicodeChar;
	}

	return ret;
}

CHAR_INFO getc_cb(short x, short y)
{
	//��� �����������
	SMALL_RECT srctReadRect;
	CHAR_INFO* chiBuffer = new CHAR_INFO[1];
	COORD coordBufSize;

	// ��������� ������������� ���������.
	srctReadRect.Top = y;    // ������� �����: ������� 0, ������� 0
	srctReadRect.Left = x;
	srctReadRect.Bottom = y + 1; // ������ ������: ������� ����� ������ Y - 1, ������� ����� ������ X - 1
	srctReadRect.Right = x + 1;

	// ������ ���������� ������ ����� ������� �������.
	coordBufSize.Y = x + 1;
	coordBufSize.X = y + 1;

	// ��������� ���� �� ��������� ������ �� ��������� �����.
	ReadConsoleOutput(
		hStdout,        	// �������� �����, �� �������� ������
		chiBuffer,      	// �����, � ������� ��������
		coordBufSize,   	// ������ �������/������ chiBuffer
		{ 0, 0 },  	// ������� ����� ������ ���������� � chiBuffer
		&srctReadRect); 	// ������������ ������������� ��������� ������

	return chiBuffer[0];
}
char getc_cbA(short x, short y)
{
	//������ ���������� ��������� �������, �� ������������� ����
	CHAR_INFO ret = getc_cb(x, y);
	return ret.Char.AsciiChar;
}
wchar_t getc_cbU(short x, short y)
{
	//������ ���������� ��������� �������, �� ������������� ����
	CHAR_INFO ret = getc_cb(x, y);
	return ret.Char.UnicodeChar;
}