// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class Obj> class Stack {
public:
	class Node {
	public:
		Node* next;
		Obj data;
	};
private:
	Node* top;
	int size = 0;
public:
	Stack();
	int getSize();
	int is_empty();
	int StackFull();
	void push(Obj data);
	Obj pop();
	void display();
	void deleteStack();
};
template <class Obj> 
Stack<Obj>::Stack() {
	top = NULL;
}
template <class Obj>
int Stack<Obj>::getSize() {
	int s = size;
	return s;
}
template <class Obj>
int Stack<Obj>::is_empty() {
	return (top == NULL);
}
template <class Obj>
int Stack<Obj>::StackFull() {
	Stack<Obj>* s = new Stack<Obj>();
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
void Stack<Obj>::push(Obj data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
	size++;
}
template <class Obj>
Obj Stack<Obj>::pop() {
	Node* p = top;
	top = top->next;
	Obj temp = p->data;
	delete p;
	size--;
	return temp;
}
template <class Obj>
void Stack<Obj>::display() {
	Node* p = top;
	if (p == NULL) cout << "empty" << endl;
	while (p) {
		cout << p->data << " -> ";
		p = p->next;
	}
}
template <class Obj>
void Stack<Obj>::deleteStack() {
	Node* p = top;
	Obj i;
	while (p) {
		i = pop();
		p = p->next;
	}
	size = 0;
}
int main()
{
	Stack<string> stack;
	stack.push("10");
	stack.push("9");
	stack.push("8");
	cout << "truoc khi lay ra: " << stack.getSize() << endl;
	stack.display();
	cout << "so lay ra: " << stack.pop() << endl;
	cout << "sau khi lay ra: " << stack.getSize() << endl;
	stack.display();
	system("pause");
	return 0;
}


