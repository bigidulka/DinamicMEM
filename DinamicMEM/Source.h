#pragma once
#include<iostream>
#include <ctime>

using namespace std;

//#define DYNAMIC_MEM_1
#define DYNAMIC_MEM_2

#define ROW
#define COL
#define ROW_INSERT_AND_ERASE
#define COL_INSERT_AND_ERASE
template<typename T> T** Allocate(const int m, const int n);
template<typename T> void Clear(T** arr, const int m);
template<typename T> void FillRand(T* arr, const int m, const int n);
template<typename T> void FillRand(T** arr, const int m, const int n);
template<typename T> T** push_row_back(T** arr, int& m, const int n);
template<typename T> T** push_row_front(T** arr, int& m, const int n);
template<typename T> void push_col_back(T** arr, const int m, int& n);
template<typename T> void push_col_front(T** arr, const int m, int& n);
template<typename T> T** pop_row_back(T** arr, int& m, const int n);
template<typename T> T** pop_row_front(T** arr, int& m, const int n);
template<typename T> void pop_col_back(T** arr, const int m, int& n);
template<typename T> void pop_col_front(T** arr, const int m, int& n);
template<typename T> T** insert_row(T** arr, int& m, const int n, int index);
template<typename T> void insert_col(T** arr, const int m, int& n, int index);
template<typename T> T** erase_row(T** arr, int& m, const int n, int index);
template<typename T> void erase_col(T** arr, const int m, int& n, int index);
template<typename T> void Print(T* arr, const int n);
template<typename T> void Print(T** arr, const int m, const int n);