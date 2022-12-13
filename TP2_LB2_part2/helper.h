#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		cin >> method;
		if (cin.fail() || method < minInput || method > maxInput)
		{
			cin.clear();
			cout << "Неверный ввод.\nПовторите снова: ";
		}
		else
		{
			cin.ignore(32767, '\n');
			cin.clear();
			return method;
		}
		cin.ignore(32767, '\n');
	}
}

bool processInputNameOfInputFile(string& filename);

