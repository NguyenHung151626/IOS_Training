// HeapBuild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int leftChild(int* a, int i, int n) {
	if (2 * i <= n) return 2 * i;
	else return 0;
}
int rightChild(int* a, int i, int n) {
	if (2 * i + 1 <= n) return 2 * i + 1;
	else return 0;
}
int parent(int* a, int i, int n) {
	if (i == 1) return 0;
	int p = i / 2;
	return p;
}
void heapify(int* a, int i, int n) {
	if (i <= n / 2) {
		int l = leftChild(a, i, n);
		int r = rightChild(a, i, n);
		int largest;
		if (l != 0 || r != 0) {
			if (l <= n && (a[l] > a[i])) {
				largest = l;
			}
			else largest = i;
			if ((r <= n) && (r!=0)) {
				if (a[r] > a[largest]) {
					largest = r;
				}
			}
			if (largest != i) {
				swap(a[i], a[largest]);
				heapify(a, largest, n);
			}
		}
	}
}
void buildHeap(int* a, int n) {
	n++;
	int* L = new int[n+1];
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = a[i - 1];
	}
	for (int i = n / 2; i >= 1; i--) {
		heapify(L, i, n);
	}
	for (int i = 1; i <= n; i++) {
		 a[i - 1] = L[i];
	}
}

void heapSort(int* a, int n) {
	int min = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[min]) min = i;
	}
	swap(a[min], a[0]);
	int index = 1;
	int size = n;
	while (size > 0) {
		buildHeap(a, size);
		swap(a[1], a[size]);
		size--;
	}
}
int maximum(int* a, int n) {
	int min = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[min]) min = i;
	}
	swap(a[min], a[0]);
	buildHeap(a, n);
	return a[1];
}
int extractMax(int* a, int n) {
	int min = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[min]) min = i;
	}
	swap(a[min], a[0]);
	buildHeap(a, n);
	int temp = a[1];
	n--;
	buildHeap(a, n);
	return temp;
}
void increaseKey(int* a, int i, int n, int key) {
	buildHeap(a, n);
	i--;//mang
	if (a[i] < key) {
		a[i] = key;
		i++;
		n++;//10
		//a 0 -> 9, L 1 ->10
		int* L = new int[n+1];//0->9, n = 10
		L[0] = 0;
		for (int temp = 1; temp <= n; temp++) { //11, 1->10
			L[temp] = a[temp - 1];
		}
		n--;
		while (i>1) {
			int j = parent(L, i, n);
			if (L[i] > L[j]) swap(L[i] , L[j]);
			i = j;
		}
		n++;
		for (int temp = 1; temp <= n; temp++) { //11, 1->10
			a[temp - 1] = L[temp];
		}
	}	
}
int main()
{
	//mang 11 coi 10 phan tu
	int arr[10] = { 8, 1, 2, 4, 7, 3, 9, 14, 10, 16};
	buildHeap(arr, 9);
	cout << "sap xep bang heap: " << endl;
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << " -> ";
	}
	increaseKey(arr, 10, 9, 15);
	cout << "Thay khoa o nut thu 10 bang 15 " << endl;
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << " -> ";
	}
	system("pause");
	return 0;
}

