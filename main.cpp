#include <iostream>
#include "menu.h"
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu programm;

	while (programm.OpenMenu());

	return 0;
}