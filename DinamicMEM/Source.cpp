#include<iostream>
using namespace std; 

#define DYNAMIC_MEM_1
#define DYNAMIC_MEM_2

#ifdef DYNAMIC_MEM_1
void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void push_back(int*& arr, int &n, const int value);

void main()
{
	setlocale(0, "");
	int n = 5; 
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	push_back(arr, n, 10);
	Print(arr, n);

	/*int brr[5];
	FillRand(brr, 5);
	Print(brr, 5);*/

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
	int* newArray = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[n] = value;
	n++;
	delete[] arr;
	arr = newArray;
}
#endif // DYNAMIC_MEM_1

#ifdef DYNAMIC_MEM_2
void main()
{
	setlocale(0, "");
	
}
#endif // DYNAMIC_MEM_2
