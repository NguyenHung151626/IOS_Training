// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int* a, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n-j; i++) {
			if (a[i-1] > a[i]) swap(a[i-1], a[i]);
		}
	}
}
void selectionSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}
void merge(int* a, int p, int q, int r) {
	int* L = new int[r];
	int index = p, i = p, j = q + 1;
	while (!((i > q) || (j > r))) {
		if (a[i] <= a[j]) {
			L[index] = a[i];
			index++;
			i++;
		}
		else {
			L[index] = a[j];
			index++;
			j++;
		}
	}
	if (i == (q + 1)) {
		int tempJ = j;
		for (int temp = index; temp <= r; temp++) {
			L[temp] = a[tempJ];
			tempJ++;
		}
	}
	if (j == (r + 1)) {
		int tempI = i;
		for (int temp = index; temp <= r; temp++) {
			L[temp] = a[tempI];
			tempI++;
		}
	}
	for (int temp = p; temp <= r; temp++) {
		a[temp] = L[temp];
	}
}
void mergeSort(int* a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
int partition(int* a, int p, int r) {
	int q = (p+r) / 2;
	int chot = a[q];
	int index = p;
	int* L = new int[r];
	//mang phai lam tu L[0] de tranh tran bo nho dc cap phat
	for (int i = p; i <= r - p; i++) {
		if (a[i] < chot) {
			L[index-p] = a[i];
			index++;
		}
	}
	int j = index;
	L[j-p] = chot;
	index++;
	for (int i = p; i <= r - p; i++) {
		if (i != q) {
			if (a[i] >= chot) {
				L[index-p] = a[i];
				index++;
			}
		}
	}
	for (int i = p; i <index; i++) {
		a[i] = L[i-p];
	}
	return j;
}

void quickSort(int* a, int p, int r) {
	if (p < r) {
		int pivot = partition(a, p, r);
		if (p < pivot - 1) quickSort(a, p, pivot - 1);
		if (pivot + 1 < r) quickSort(a, pivot + 1, r);
	}
}
int main()
{
	int a[14] = {-10, 3, 2, 7, 6, 88, 11, 23, -3, -11, 1222, 22, -9, -11};
	mergeSort(a, 0, 13);
	cout << "sau khi sx: " << endl;
	for (int i = 0; i < 14; i++) {
		cout << a[i] << "  ";
	}
	system("pause");
    return 0;
}

