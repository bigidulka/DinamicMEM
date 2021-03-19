#include"FillRand.h"
#include"Source.h"
template<typename T> void FillRand(T* arr, const int m, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//Random(arr[i]);
	}
}
template<typename T> void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			//Random(arr[i]);
		}
	}
}
template<typename T> T** Allocate(const int m, const int n)
{
	T** arr = new T * [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n]{};
	}
	return arr;
}
template<typename T> void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}