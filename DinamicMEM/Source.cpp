﻿#include<iostream>
using namespace std; 

//#define DYNAMIC_MEM_1
#define DYNAMIC_MEM_2
#define tab "\t"
#define DZ
#define PUSH_ROW
//#define PUSH_COL

#ifdef DYNAMIC_MEM_1
void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void push_back(int*& arr, int &n, const int value);
void push_front(int*& arr, int& n, const int value);
void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void Insert(int*& arr, int& n, int index, int value);
void Erase(int*& arr, int& n, int index);

void main()
{
	setlocale(0, "");
	int n; cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	//Основной
	FillRand(arr, n);
	Print(arr, n);
	//Push back
	int value; cout << "[push_back] Введите число: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);
	//pop back
	cout << "[pop_back]" << endl;
	pop_back(arr, n);
	Print(arr, n);
	//Push front
	cout << "[push_front] Введите число: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);
	//pop back
	cout << "[pop_front]" << endl;
	pop_front(arr, n);
	Print(arr, n);
	//Insert
	int index;
	cout << "[Insert] Введите индекс: "; cin >> index;
	cout << "[Insert] Введите число: "; cin >> value;
	Insert(arr, n, index, value);
	Print(arr, n);
	//Erase
	cout << "[Erase] Введите индекс: "; cin >> index;
	Erase(arr, n, index);
	Print(arr, n);
}
void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;	
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
} 
void push_back(int*& arr, int& n, const int value)
{
	int* newArray = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		newArray[i] = arr[i];
	}
	delete[] arr;
	newArray[n] = value;
	arr = newArray;
	n++;
}
void push_front(int*& arr, int& n, const int value)
{
	int* newArray = new int[n + 1];
	newArray[0] = value;
	for (int i = 0; i < n; i++)
	{
		newArray[i + 1] = arr[i];
	}
	delete[] arr;
	arr = newArray;
	n++;
}
void pop_back(int*& arr, int& n)
{
	int* newArray = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		newArray[i] = arr[i];
	}
	delete[] arr;
	arr = newArray;
	n--;
}
void pop_front(int*& arr, int& n)
{
	int* newArray = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		newArray[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newArray;
	n--;
}
void Insert(int*& arr, int& n, int index, int value)
{
	if (index >= 0 && index <= n)
	{
		int* newArray = new int[n + 1];
		newArray[index] = value;
		for (int i = 0; i < index; i++)
		{
			newArray[i] = arr[i];
		}
		for (int i = index; i < n; i++)
		{
			newArray[i + 1] = arr[i];
		}
		delete[] arr;
		arr = newArray;
		n++;
	}
}
void Erase(int*& arr, int& n, int index)
{
	if (index >= 0 && index < n)
	{
		int* newArray = new int[n - 1];
		for (int i = 0; i < index; i++)
		{
			newArray[i] = arr[i];
		}
		for (int i = index; i < n; i++)
		{
			newArray[i] = arr[i + 1];
		}
		delete[] arr;
		arr = newArray;
		n--;
	}
}
#endif // DYNAMIC_MEM_1

#ifdef DYNAMIC_MEM_2

int** Allocate(const int m, const int n);
void Clear(int** arr, const int m);

void FillRand(int* arr, const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int* arr, const int n);
void Print(int** arr, const int m, const int n);
int** push_row_back(int** arr, int& m, const int n);
int** push_row_front(int** arr, int& m, const int n);
void push_col_back(int** arr, const int m, int& n);
//void push_col_front(int** arr, const int m, int& n);

void main()
{
	setlocale(0, "");
	int m, n;
	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во столбоц: "; cin >> n;
	int** arr = Allocate(m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);

#ifdef PUSH_ROW
	cout << "push_row_back" << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "push_row_front" << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
#endif //PUSH_ROW
#ifdef PUSH_COL
	cout << "push_col_back" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "push_col_front" << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
#endif // PUSH_COL
	Clear(arr, m);
}

void FillRand(int* arr, const int m, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
			cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
int** push_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
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
int** push_row_front(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++) buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = new int[n] {};
	m++;
	return buffer;
}
void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//void push_col_front(int** arr, const int m, int& n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		int* buffer = new int[n + 1]{};
//		for (int j = 0; j < n; j++) buffer[j] = arr[i][j];
//		delete[] arr[i];
//		arr[0] = buffer;
//	}
//	n++;
//}
int** Allocate(const int m, const int n)
{
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
void Clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
#endif // DYNAMIC_MEM_2

