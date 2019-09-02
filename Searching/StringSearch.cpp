// StringSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void naiveSearch(string T, string P) {
	int n = T.length();
	int m = P.length();
	for (int s = 0; s <= n - m;s++) {
		int i = 0;
		while (i<= m -1 && T[s + i] == P[i]) {
			i++;
		}
		if (i == m) {
			cout << s << " -> ";
		}
	}
}
int last(char c, string P) {
	int m = P.length();
	int index = 0;
	for (int j = m - 1; j >= 0; j--) {
		if (c == P[j]) {
			index = j;
			break;
		}
	}
	if (index >= 0) return index;
	else return -1;
}
int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
void boyerMoore(string T, string P) {
	int n = T.length();
	int m = P.length();
	int indexToi = 0;
	int s = 0;
	while(s<=n-m-1) {
		int j = m - 1;
		while (j >= 0 && T[s + j] == P[j]) {
			j--;
		}
		if (j == -1) {
			cout << s << " -> ";
			s++;
		}
		else if (T[s + j] != P[j]) {
			indexToi = j;
			s = s + max(indexToi - last(T[s+j], P), 1);
		}
	}
}
int* PI(string P) {
	int m = P.length();
	int* arr = new int[m];
	arr[0] = -1;
	if (P[1] == P[0]) arr[1] = 0;
	else arr[1] = -1; //  = -1
	for (int q = 2; q <= m - 1; q++) {
		int k = arr[q-1];// = -1
		while (k>=0 && P[k+1] != P[q]) k = arr[k];
		if (P[k + 1] == P[q]) arr[q] = k + 1;
		else arr[q] = -1;
	}
	return arr;
}
void searchKMP(string T, string P) {
	int n = T.length();
	int m = P.length();
	int q = -1;
	for (int s = 0; s <= n - 1; s++) {
		while (q>=0 && T[s] != P[q+1]) {
			q = PI(P)[q];
		}
		if (T[s] == P[q+1]) q++;
		if (q == m - 1) {
			cout << s - m + 1 << " -> ";
			q = PI(P)[q];
		}
	}
}
int main()
{
	string text = "ababababca";
	string pattern = "aba";
	searchKMP(text, pattern);
	system("pause");
    return 0;
}

