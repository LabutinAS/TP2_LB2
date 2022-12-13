#pragma once
#include <string>

template <class T>
class RKeeper
{
private:
	int size;
	T* data;

public:
	RKeeper() : size(0), data(nullptr) {}
	RKeeper(const RKeeper<T>& myArray);
	~RKeeper() { clear(); }

	void clear();
	void sort();
	const int getSize() { return size; }
	T& operator[](int);
	RKeeper<T>& operator+=(const T& obj);
	RKeeper<T>& operator-=(const int index);
	RKeeper<T>& operator=(const RKeeper<T>& myArray);
};

template <class T>
RKeeper<T>::RKeeper(const RKeeper<T>& myArray) {
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
}

template <class T>
T& RKeeper<T>::operator[](int index)
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	return data[index];
}

template<class T>
RKeeper<T>& RKeeper<T>::operator+=(const T& obj) {
	T* tmp = data;
		size++;
		data = new T[size];
		for (int i = 0; i < size - 1; i++)
			data[i] = tmp[i];
		data[size - 1] = obj;	
	return *this;
}

template<class T>
RKeeper<T>& RKeeper<T>::operator-=(const int index) {
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	T* tmp = new T[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--;
	data = tmp;
	return *this;
}

template <class T>
RKeeper<T>& RKeeper<T>::operator=(const RKeeper<T>& myArray)
{
	if (this == &myArray)
		return *this;
	delete[] data;
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
	return *this;
}

template <class T>
void RKeeper<T>::sort() {
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
			if (data[j] > data[j + 1])
				std::swap(data[j], data[j + 1]);
}

template <class T>
void RKeeper<T>::clear() {
	delete[] data;
	data = nullptr;
	size = 0;
}
