#include <iostream>
#ifdef UNICODE
	#undef UNICODE
#endif
#include "reader.hpp"
#include "writer.hpp"
using namespace std;

int main(void)
{
	setStringInConsoleA({ 1, 1 }, (char*)"Hello, world!");

	return 0;
}