#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterWord(const char& ch) {
	return !isalpha(ch) && !isdigit(ch);
}

bool chekWord(const string& word) {
	if (word.size() != 2)
		return false;
	for (char ch : word)
		if (!isdigit(ch))
			return false;
	return true;
}

bool checkString(const string& s) {
	string ans;
	bool isWord = false;
	int startWord = -1, endWord = -1;
	for (int i = 0; i < s.size() + 1; i++) {
		try {
			if (isSplitterWord(s[i])) throw 3;
			if (!isWord) {
				isWord = true;
				startWord = i;
			}
		}
		catch(int a)
		{
			if (isWord && chekWord(s.substr(startWord, i - startWord)))
				return false;
			isWord = false;
		}
		
	}
	return true;
}

void task(ifstream& input) {
	string tmpS;
	bool isWrite = false;
	while (getline(input, tmpS))
		if (checkString(tmpS)) {
			cout << tmpS << endl;
			isWrite = true;
		}
	if (!isWrite)
		cout << "Таких строк не найдено" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n";
	task(input);
	input.close();
}