#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include "menu.h"

#define cls system("cls")
#define pause system("pause")

bool okInitializingFloat = 0, okInitializingChar = 0;

using namespace std;

bool menu::OpenMenu()
{
	char exitMenu = 0;
	
	RendererMenu(0);

	cin >> exitMenu;

	switch (exitMenu)
	{
	case'1':Initialization(); break;
	
	case'2':
	{
		if (okInitializingFloat * okInitializingChar == 1)
		{
			OutputOfAllStack();
		}
	}break;

	case'3':
	{
		if (okInitializingFloat * okInitializingChar == 1)
		{
			InvertingStack();
			Sleep(2000);
		}
	}break;
	
	default:break;
	}

	return (exitMenu == '4') ? 0 : 1;
}

void menu::Initialization()
{
	char chooseInitialization = 0;
	
	while (chooseInitialization != '1' && chooseInitialization != '2')
	{
		RendererMenu(1);
		cin >> chooseInitialization;
	}

	switch (chooseInitialization)
	{
	case'1':InitializationFloat(); break;
	default:InitializationChar(); break;
	}

}

void menu::RendererMenu(uint16_t CharacterOutputSelection)
{
	cls;

	if (CharacterOutputSelection == 0)
	{
		cout << "|============================================================================|\n";
		cout << "|                                Главное меню                                |\n";
		cout << "|============================================================================|\n\n";
		cout << "1. Инициализация массивов\n2. Вывод массивов\n3. Перестановка элементов массивов в обратном порядке\n4. Выход\n-------\nВыбор пункта меню: ";
	}

	if (CharacterOutputSelection == 1)
	{
		cout << "|============================================================================|\n";
		cout << "|                                Инициализация                               |\n";
		cout << "|============================================================================|\n\n";
		cout << "1. Инициализация массива float\n2. Инициализация массива char\n-------\nВыбор пункта меню: ";
	}

	if (CharacterOutputSelection == 2)
	{
		cout << "|============================================================================|\n";
		cout << "|                          Массивы были перестроены                          |\n";
		cout << "|============================================================================|\n\n";
		return;
	}

	if (CharacterOutputSelection == 3)
	{
		cout << "|============================================================================|\n";
		cout << "|                           Инициализация float                              |\n";
		cout << "|============================================================================|\n\n";
		cout << "1. Добавление элемента\n2. Удаление элемента\n3. Завершение инициализации\n-------\nВыбор пункта меню: ";
	}

	if (CharacterOutputSelection == 4)
	{
		cout << "|============================================================================|\n";
		cout << "|                           Инициализация char                               |\n";
		cout << "|============================================================================|\n\n";
		cout << "1. Добавление элемента\n2. Удаление элемента\n3. Завершение инициализации\n-------\nВыбор пункта меню: ";
	}

	if (CharacterOutputSelection == 5)
	{
		cout << "|============================================================================|\n";
		cout << "|                           Завершение программы                             |\n";
		cout << "|============================================================================|\n\n";
		Sleep(1000);
	}
	
}

void menu::InitializationFloat()
{
	char initializationMenu = 0;
	string strData;
	float data = 0.;

	while (initializationMenu != '3')
	{
		RendererMenu(3);
		cin >> initializationMenu;		
		cls;

		switch (initializationMenu)
		{
		case'1':
		{
			cout << "Ввод числа: ";
			cin >> strData;
			CheckingCorrectInputFloat(strData);
			// Converting from string to float
			data = stof(strData);
			floatArray.push(data);
		}break;

		case'2':
		{
			try
			{
				cout << "Число " << floatArray.top() << " удалено из стэка\n";
				floatArray.pop();
			}
			catch (const exception& ex)
			{
				cout << ex.what() << '\n';
			}
			pause;
		}break;
		}
	}

	okInitializingFloat = 1;

	if (floatArray.empty())
	{
		okInitializingFloat = 0;
	}
}

void menu::InitializationChar()
{
	char initializationMenu = 0;
	char data = '0';

	while (initializationMenu != '3')
	{
		RendererMenu(4);
		cin >> initializationMenu;

		cls;

		switch (initializationMenu)
		{
		case'1':
		{
			cout << "Ввод символа: ";
			cin >> data;
			charList.push(data);
		}break;

		case'2':
		{
			try
			{
				cout << "Символ " << charList.top() << " удален из стэка\n";
				charList.pop();
			}
			catch (const exception& ex)
			{
				cout << ex.what() << '\n';
			}
			pause;
		}break;
		}
	}

	okInitializingChar = 1;

	if (charList.empty())
	{
		okInitializingChar = 0;
	}
}

void menu::OutputOfAllStack()
{
	Stack<float> tempFloat;
	Stack<char, List> tempChar;
	
	cls;

	cout << "Массив float: ";
	while(!floatArray.empty())
	{
		try
		{
			cout << floatArray.top() << " ";
			tempFloat.push(floatArray.top());
			floatArray.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}

	cout << "\nМассив char: ";
	while(!charList.empty())
	{
		try
		{
			cout << charList.top();
			tempChar.push(charList.top());
			charList.pop();
		}

		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}


	while (!tempFloat.empty())
	{
		try
		{
			floatArray.push(tempFloat.top());
			tempFloat.pop();
		}

		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}

	while (!tempChar.empty())
	{
		try
		{
			charList.push(tempChar.top());
			tempChar.pop();
		}

		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}


	cout << "\n";
	pause;
}

void menu::InvertingStack()
{
	Stack<float> tempFloat;
	Stack<char, List> tempChar;
 
	while (!floatArray.empty())
	{
		try
		{
			tempFloat.push(floatArray.top());
			floatArray.pop();
		}

		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}

	while (!charList.empty())
	{
		try
		{
			tempChar.push(charList.top());
			charList.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}

	floatArray = move(tempFloat);
	charList = move(tempChar);

	RendererMenu(2);
}

void menu::CheckingCorrectInputFloat(string& str)
{
	bool okPoint = 0, okNumber = 0;
	size_t j, i = 0;
	string s = ".0987654321";
	string s1 = "";

	for (i; i < str.length(); ++i)
	{
		okNumber = 0;

		for (j = 0; j < 11; ++j)
		{
			if (str[i] == s[j])
			{
				okNumber = 1;
				if (!okPoint || (str[i] != '.') || (str[i] != ','))
				{
					if (str[i] == ',')
					{
						str[i] = '.';
					}

					s1 = s1 + str[i];
				}

				if ((str[i] == '.' || str[i] == ',') && !okPoint)
				{
					okPoint = 1;
				}
			}
		}
		if (!okNumber)
		{
			str = "0.";
			return;
		}
	}
	str = s1;
}

menu::~menu()
{
	RendererMenu(5);
}