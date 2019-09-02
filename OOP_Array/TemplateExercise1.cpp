// TemplateExercise1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class Obj, int n> class Array {
private:
	Obj* p;
public:
	Array();
	~Array();
	int getSL() {
		int sl = n;
		return sl;
	};
	friend istream& operator >> <>(istream& s, Array<Obj, n>& arr);
	friend ostream& operator << <>(ostream& s, const Array<Obj, n>& arr);
	Obj& operator [](int i);
	void sortComplex();
};
template <class Obj, int n> Array<Obj, n>::Array() {
	p = new Obj[n];
}
template <class Obj, int n> Array<Obj, n>::~Array() {
	delete[] p;
}
template <class Obj, int n> Obj& Array<Obj, n>::operator [](int i) {
	return p[i];
}
template <class Obj, int n> istream& operator >>(istream& s, Array<Obj, n>& arr) {
	for (int i = 0; i < n; i++) {
		s >> arr.p[i];
	}
	return s;
}
template <class Obj, int n> ostream& operator <<(ostream& s, const Array<Obj, n>& arr) {
	for (int i = 0; i < n; i++) {
		s << arr.p[i] << " \t ";
	}
	return s;
}
template <class Obj, int n> void Array<Obj, n>::sortComplex() {
	for (int i = 1; i < n; i++) {
		int j = i;
		Obj last = p[i];
		while (last < p[j - 1] && j>0) {
			p[j] = p[j - 1];
			j--;
		}
		p[j] = last;
	}
}
int main()
{
	Array<string, 5> arr;
	int n = arr.getSL();
	cout << "nhap " << n << " gia tri" << endl;
	cin >> arr;
	arr.sortComplex();
	cout << "xuat" << endl;
	cout << arr;
	system("pause");
    return 0;
}

