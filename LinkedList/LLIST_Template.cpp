// LLIST_Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class T> class LLIST {
public:
	struct Node {
		Node* next;
		T data;
	};
	int getSize();
	LLIST();
	void printLLIST();
	void llInsertHead(T data);
	void llInsertTail(T data);
	void llDeleteHead();
	void llDeleteTail();
	void llDeleteAll();
	void llInsertAfter(int index, T data);
	Node* find(int index);
private:
	Node* head;
	int size = 0;
};
template <class T> LLIST<T>::LLIST() {
	head = NULL;
}
template <class T> int LLIST<T>::getSize() {
	int s = size;
	return s;
}
template <class T> void LLIST<T>::printLLIST() {
	Node* p = head;
	while (p) {
		cout << p->data << " : ";
		p = p->next;
	}
}
template <class T> void LLIST<T>::llInsertHead(T data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	size++;
}
template <class T> void LLIST<T>::llInsertTail(T data) {
	Node* newNode = new Node();
	newNode->data = data;
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
	}
	else {
		Node* p = head;
		while (p->next) {
			p = p->next;
		}
		p->next = newNode;
		newNode->next = NULL;
	}
	size++;
}
template <class T> void LLIST<T>::llDeleteHead() {
	if (head != NULL) {
		Node* p = head;
		head = head->next;
		delete p;
	}
	size--;
}
template <class T> void LLIST<T>::llDeleteTail() {
	if (head != NULL) {
		Node* temp;
		for (temp = head; temp->next->next != NULL; temp = temp->next);
		Node* p = temp->next;
		temp->next = NULL;
		delete p;
	}
	size--;
}
template <class T> void LLIST<T>::llDeleteAll() {
	Node* p = head;
	head = NULL;
	delete p;
	size = 0;
}
template <class T> typename LLIST<T>::Node* LLIST<T>::find(int index) {
	Node *cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur;
}
template <class T> void LLIST<T>::llInsertAfter(int index, T data) {
	if (index < 0) {
		cout << "Negative index!!" << endl;
		return;
	}
	if (index > size) {
		cout << "Extension is not supported!!" << endl;
		return;
	}
	else {
		Node* newNode = new Node();
		newNode->data = data;
		Node* p = find(index);
		newNode->next = p->next;
		p->next = newNode;
	}
}
int main()
{
	LLIST<string> l;
	l.llInsertHead("a");
	l.llInsertTail("b");
	l.llInsertTail("c");
	l.llInsertTail("d");
	l.llInsertTail("e");
	l.llInsertAfter(0, "ccc");
	l.printLLIST();
	cout << "\n";
	cout << l.getSize() << endl;
	system("pause");
	return 0;
}



