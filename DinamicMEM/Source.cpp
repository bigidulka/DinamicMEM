#include<Source.h>

#ifdef DYNAMIC_MEM_1
void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void push_back(int*& arr, int& n, const int value);
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
//template<typename T> void Random(T& value);

void main()
{
	setlocale(0, "");
	int m, n;
	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во столбоц: "; cin >> n;
	int** arr = Allocate<int>(m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);
#ifdef ROW
	cout << "push_row_back" << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "pop_row_back" << endl;
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "push_row_front" << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "pop_row_front" << endl;
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);
#endif //ROW
#ifdef COL
	cout << "push_col_back" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "pop_col_back" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "push_col_front" << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
	cout << "pop_col_front" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
#endif //COL
	int index;
#ifdef ROW_INSERT_AND_ERASE
	cout << "[Insert_Row] Введите индекс: "; cin >> index;
	arr = insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "[ERASE_Row] Введите индекс: "; cin >> index;
	arr = erase_row(arr, m, n, index);
	Print(arr, m, n);
#endif // ROW_INSERT_AND_ERASE
#ifdef COL_INSERT_AND_ERASE
	cout << "[Insert_COl] Введите индекс: "; cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);
	cout << "[erase_COl] Введите индекс: "; cin >> index;
	erase_col(arr, m, n, index);
	Print(arr, m, n);
#endif // COL_INSERT_AND_ERASE
	Clear(arr, m);
}

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
template<typename T> void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}
template<typename T> void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
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

//template<typename T>void Random(T& value)
//{
//	//cout << typeid(value).name() << endl;
//	if (typeid(value) == typeid(float) || typeid(value) == typeid(double))
//		value = double(rand() % 10000) / 100;
//	else if (typeid(value) == typeid(char))
//		value = rand();
//	else
//		value = rand() % 100;
//}

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
#endif // DYNAMIC_MEM_2