#pragma once
template<typename T> T** Allocate(const int m, const int n);
template<typename T> void Clear(T** arr, const int m);
template<typename T> void FillRand(T* arr, const int m, const int n);
template<typename T> void FillRand(T** arr, const int m, const int n);