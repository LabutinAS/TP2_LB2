#include "Route.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(RKeeper<Route>& routes);
void changeObject(RKeeper<Route>& routes);
void deleteObject(RKeeper<Route>& routes);
void print(RKeeper<Route>& routes);
void searchObjects(RKeeper<Route>& routes);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RKeeper<Route> routes;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(routes);
			break;
		case 2:
			changeObject(routes);
			break;
		case 3:
			deleteObject(routes);
			break;
		case 4:
			print(routes);
			break;
		case 5:
			searchObjects(routes);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ��������, ������� ���������� ��� ��������� � ������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(RKeeper<Route>& routes) {
	Route route;
	//route.inputFromConsole();
	try {
		if (routes.getSize() > 7) throw std::exception("��������� ������������ ����� ��������� (8)\n");
		cin >> route;
		routes += route;
		routes.sort();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void changeObject(RKeeper<Route>& routes) {
	try {
		if (routes.getSize() < 1) throw std::exception("\n������ ��������� ����\n");
		print(routes);
		cout << "\n������� ����� �������� ��� ���������: ";
		routes[safeInput(1, routes.getSize()) - 1].change();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	routes.sort();
}

void deleteObject(RKeeper<Route>& routes) {
	try {
		if (routes.getSize() < 1) throw std::exception("\n������ ��������� ����\n");
		print(routes);
		cout << "\n������� ����� �������� ��� ��������: ";
		routes -= safeInput(1, routes.getSize()) - 1;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	routes.sort();
}

void print(RKeeper<Route>& routes) {
	try {
		if (routes.getSize() < 1) throw std::exception("\n������ ��������� ����\n");
		cout << "\n������ �������\n";
		for (int i = 0; i < routes.getSize(); i++) {
			cout << i + 1 << ". �������\n";
			cout << routes[i]<<std::endl;
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void searchObjects(RKeeper<Route>& routes) {
	try {
		if (routes.getSize() < 1) throw std::exception("\n������ ��������� ����\n");
	
		bool isPrint = false;
		cout << "\n������� �������� ������: ";
		string punkt;
		getline(cin, punkt);
		for (int i = 0; i < routes.getSize(); i++) {
			if (routes[i].getEndPoint() == punkt || routes[i].getStartPoint() == punkt) {
				isPrint = true;
				cout << i + 1 << ". �������\n";
				cout << routes[i];
			}
		}

		if (!isPrint)
			cout << "\n����� ��������� ���\n\n";
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}