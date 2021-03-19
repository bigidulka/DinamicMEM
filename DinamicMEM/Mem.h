#pragma once
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
