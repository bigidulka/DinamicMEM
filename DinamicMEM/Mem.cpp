#include"Mem.h"
#include"Source.h"

template<typename T> T** push_row_back(T** arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];
	//копируем адреса существующих строк
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	/*for (int i = 0; i < m+1; i++)
	{
		buffer[i] = new int[n] {};
	}*/
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		buffer[i][j] = arr[i][j];
	//	}
	//}
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//удаляем исходный массив указателей
	delete[] arr;
	//создаем последнюю строку массива
	buffer[m] = new int[n] {};
	m++;
	return buffer;
}
template<typename T> T** pop_row_back(T** arr, int& m, const int n)
{
	T** buffer = new T * [m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	m--;
	return buffer;
}
template<typename T> T** push_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < m; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[n] {};
	m++;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T * [m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	m--;
	return buffer;
}
template<typename T> void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T> void pop_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
template<typename T> void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)  buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T> void pop_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}

template<typename T> T** insert_row(T** arr, int& m, const int n, int index)
{
	if (index >= 0 && index <= n)
	{
		T** buffer = new T * [m + 1];
		buffer[index] = new int [n] {};
		for (int i = 0; i < index; i++) buffer[i] = arr[i];
		for (int i = index; i < m; i++) buffer[i + 1] = arr[i];
		delete[] arr;
		m++;
		return buffer;
	}
}
template<typename T> T** erase_row(T** arr, int& m, const int n, int index)
{
	if (index >= 0 && index < m)
	{
		T** buffer = new T * [--m];
		for (int i = 0; i < index; i++) buffer[i] = arr[i];
		for (int i = index; i < m; i++) buffer[i] = arr[i + 1];
		delete[] arr;
		return buffer;
	}
}
template<typename T> void insert_col(T** arr, const int m, int& n, int index)
{
	if (index >= 0 && index <= n)
	{
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n + 1]{};
			for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
			for (int j = index; j < n; j++) buffer[j + 1] = arr[i][j];
			delete[] arr[i];
			arr[i] = buffer;
		}
		n++;
	}
}
template<typename T> void erase_col(T** arr, const int m, int& n, int index)
{
	if (index >= 0 && index < n)
	{
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n - 1]{};
			for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
			for (int j = index; j < n; j++) buffer[j] = arr[i][j + 1];
			delete[] arr[i];
			arr[i] = buffer;
		}
		n--;
	}
}