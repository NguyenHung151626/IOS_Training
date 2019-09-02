// Sophuc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T> class sophuc {
private:
	T thuc, ao;
public:
	sophuc() {
		thuc = 0.1;
		ao = 0.1;
	}
	sophuc(T th, T ao) {
		thuc = th;
		this->ao = ao;
	}
	void set(T th, T ao) {
		thuc = th;
		this->ao = ao;
	}
	sophuc<T> operator +(const sophuc<T>& a) const {
		return sophuc<T>(thuc + a.thuc, ao + a.ao);
	}
	sophuc<T> operator -(const sophuc<T>& a) const {
		return sophuc<T>(thuc - a.thuc, ao - a.ao);
	}
	sophuc<T> operator *(const sophuc<T>& a) const {
		return sophuc<T>(thuc * a.thuc - ao*a.ao, thuc * a.ao + ao * a.thuc);
	}
	sophuc<T> operator /(const sophuc<T>& a) const {
		T thuc1 = (thuc * a.thuc - ao*a.ao) / (a.thuc*a.thuc + a.ao*a.ao);
		T ao1 = (-thuc * a.ao + ao * a.thuc) / (a.thuc*a.thuc + a.ao*a.ao);
		return sophuc<T>(thuc1, ao1);
	}
	bool operator <(const sophuc<T>& a) const {
		if (thuc < a.thuc) return true;
		else if (thuc > a.thuc) return false;
		else {
			if (ao < a.ao) return true;
			else return false;
		}
	}
	sophuc<T>& operator =(const sophuc<T>& a) {
		thuc = a.thuc;
		ao = a.ao;
		return sophuc(thuc, ao);
	}
	sophuc<T> operator -() const {
		return sophuc(-thuc, -ao);
	}
	friend ostream& operator<< <>(ostream& s, const sophuc<T>& a);
};
template <class T> ostream& operator <<(ostream& s, const sophuc<T>& a) {
	if (a.ao >= 0) s << a.thuc << "+" << a.ao << "i" << endl;
	else s << a.thuc << a.ao << "i" << endl;
	return s;
}
template <class T> sophuc<T> findMin(sophuc<T>* arr, int n) {
	sophuc<T> min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
template <class T> void sortComplex(sophuc<T>* arr, int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		sophuc<T> last = arr[i];
		while (last < arr[j - 1] && j>0) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = last;
	}
}
int main()
{
	sophuc<float> z[10];
	for (int i = 0; i < 10; i++) {
		z[i].set(pow(-1, i + 1)*i, i);
	}
	z[1] = z[2] / z[3];
	for (int i = 0; i < 10; i++) {
		cout << z[i];
	}
	cout << "-----------------------------------" << endl;
	sortComplex(z, 9);
	for (int i = 0; i < 10; i++) {
		cout << z[i];
	}
	cout << "-----------------------------------" << endl;
	cout << "so nho nhat" << findMin(z, 6);
	system("pause");
    return 0;
}

