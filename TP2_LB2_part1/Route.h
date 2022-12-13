#pragma once
#include "helper.h"
#include "ROUTEKeeper.h"
#include <ctime>
using namespace std;

class Route
{
private:
	string startPoint, endPoint;
	int number;
public:
	Route();
	Route(string startPoint, string endPoint, int number);
	Route(const Route& route);
	~Route();


	void inputFromConsole();
	//void printToConsole();
	void change();

	string getStartPoint() { return startPoint; }
	void setStartPoint(string startPoint) { this->startPoint = startPoint; }

	string getEndPoint() { return endPoint; }
	void setEndPoint(string endPoint) { this->endPoint = endPoint; }

	int getNumber() { return number; }
	void setNumber(int number) { this->number = number; }

	Route& operator=(const Route& route);
	bool operator>(Route& route);

	friend ostream& operator<<(ostream&, Route&);
	friend istream& operator>>(istream&, Route&);
	
};