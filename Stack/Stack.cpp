// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Node {
public:
	Node* next;
	int data;
};
class Stack {
private:
	Node* top;
	int size = 0;
public:
	Stack();
	int getSize();
	int is_empty();
	int StackFull();
	void push(int data);
	int pop();
	void display();
	void deleteStack();
};
Stack::Stack() {
	top = NULL;
}
int Stack::getSize() {
	int s = size;
	return s;
}
int Stack::is_empty() {
	return (top == NULL);
}
int Stack::StackFull() {
	Stack* s = new Stack();
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
void Stack::push(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
	size++;
}
int Stack::pop() {
	Node* p = top;
	top = top->next;
	int temp = p->data;
	delete p;
	size--;
	return temp;
}
void Stack::display() {
	Node* p = top;
	if (p == NULL) cout << "empty" << endl;
	while (p) {
		cout << p->data << " -> ";
		p = p->next;
	}
}
void Stack::deleteStack() {
	Node* p = top;
	int i;
	while (p) {
		i = pop();
		p = p->next;
	}
	size = 0;
}
int main()
{
	Stack stack;
	stack.push(10);
	stack.push(9);
	stack.push(8);
	cout << "truoc khi lay ra: " << stack.getSize() << endl;
	stack.display();
	cout << "so lay ra: " << stack.pop() << endl;
	cout << "sau khi lay ra: " << stack.getSize() << endl;
	stack.display();
	stack.deleteStack();
	system("pause");
    return 0;
}

