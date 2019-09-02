// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class Obj> class queue {
public:
	class Node {
	public:
		Obj data;
		Node* next;
	};
private:
	Node* first;
	Node* last;
	int size = 0;
public:
	int getSize();
	queue();
	int is_empty();
	int isFull();
	void display();
	void enqueue(Obj data);
	Obj dequeue();
};
template <class Obj>
queue<Obj>::queue() {
	first = last = NULL;
}
template <class Obj>
int queue<Obj>::getSize() {
	int s = size;
	return s;
}
template <class Obj>
int queue<Obj>::is_empty() {
	if (first == NULL) return true;
	else return false;
}
template <class Obj>
int queue<Obj>::isFull() {
	queue<Obj>* s = new queue<Obj>();
	if (s == NULL) {
		cout << "Full Memory" << endl;
		delete s;
		return 1;
	}
	else {
		delete s;
		return 0;
	}
}
template <class Obj>
void queue<Obj>::enqueue(Obj data) {
	Node* newNode = new Node();
	newNode->data = data;
	if (last == NULL) {
		first = last = newNode;
	}
	else {
		last->next = newNode;
		last = newNode;
	}
	size++;
}
template <class Obj>
Obj queue<Obj>::dequeue() {
	Node* p = first;
	Obj a = p->data;
	first = first->next;
	size--;
	delete p;
	return a;
}
template <class Obj>
void queue<Obj>::display() {
	Node* p = first;
	if (p == NULL) cout << "empty" << endl;
	while (p) {
		cout << p->data << " -> ";
		p = p->next;
	}
}
int main()
{
	queue<string> a;
	a.enqueue("10");
	a.enqueue("9");
	a.enqueue("a");
	cout << "so phan tu: " << a.getSize() << endl;
	a.display();
	cout << "so dequeue ra: " << a.dequeue() << endl;
	cout << "so phan tu: " << a.getSize() << endl;
	a.display();
	system("pause");
    return 0;
}

