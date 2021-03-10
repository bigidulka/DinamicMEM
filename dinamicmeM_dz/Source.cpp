#include<iostream>
using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void push_back(int*& arr, int& n, const int value);
void push_front(int*& arr, int& n, const int value);

void main()
{
	setlocale(0, "");
	int n = 5;
	int* arr = new int[n];

	cout << "Исходный массив:\n";
	FillRand(arr, n);
	Print(arr, n);
	cout << "push back:\n";
	push_back(arr, n, 10);
	Print(arr, n);
	push_front(arr, n, 10);
	Print(arr, n);

	delete[] arr;
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
	int* nArr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		nArr[i] = arr[i];
	}
	nArr[n] = value;
	n++;
	delete[] arr;
	arr = nArr;
}
void push_front(int*& arr, int& n, const int value)
{
	for (int i = 0; i < n; i++)
	{
		if (n == 0)
		{
			int* nArr = new int[n + 1];
			for (int i = 0; i < n; i++)
			{
				nArr[i] = arr[i];
			}
			nArr[n] = value;
			n++;
			delete[] arr;
			arr = nArr;
		}
	}
}