// DoubleLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Node {
public:
	Node* next;
	Node* prev;
	int data;
	Node();
};
Node::Node() {
	next = prev = NULL;
}
class LinkedList {
private:
	Node* head;
	Node* tail;
	int size = 0;
public:
	LinkedList();
	int getSize();
	void printList();
	void insertFront(int data);
	void insertBack(int data);
	int deleteFront();
	int deleteBack();
	bool is_empty();
	void deleteList();
};
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
}
int LinkedList::getSize(){
	int sl = size;
	return sl;
}
void LinkedList::printList() {
	Node* temp = head;
	cout << "\n\nDisplay in forward order\n";
	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << " NULL";
}
void LinkedList::insertFront(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	newNode->prev = NULL;
	if (head == NULL) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		head = newNode;
	}
	size++;
}
void LinkedList::insertBack(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->prev = tail;
	newNode->next = NULL;
	if (tail == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}
int LinkedList::deleteFront() {
	Node* p = head;
	int temp;
	if (head == NULL) cout << "khong co phan tu de xoa" << endl;
	head = head->next;
	head->prev = NULL;
	temp = p->data;
	delete p;
	size--;
	return temp;
}
int LinkedList::deleteBack() {
	Node* p = tail;
	int temp;
	if (tail == NULL) cout << "khong co phan tu de xoa" << endl;
	tail = tail->prev;
	tail->next = NULL;
	temp = p->data;
	delete p;
	size--;
	return temp;
}
bool LinkedList::is_empty() {
	if (head == NULL) return true;
	else return false;
}
void LinkedList::deleteList() {
	Node* p = head;
	cout << "Ban da xoa list, muon su dung them xin moi tao moi";
	while (p->next) {
		LinkedList::deleteFront();
		p = p->next;
	}
}
int main() {
	LinkedList linklist;
	linklist.insertFront(7);
	linklist.insertBack(8);
	linklist.insertBack(9);
	linklist.insertBack(9);
	linklist.insertBack(9);
	linklist.insertBack(9);
	linklist.insertBack(9);
	linklist.insertBack(9);
	linklist.deleteList();
	/*cout << "so vua xoa truoc DS: " << linklist.deleteFront() << endl;
	cout << "so vua xoa sau DS: " << linklist.deleteBack() << endl;
	cout << "\n\n";*/
	cout << "Empty? " << linklist.is_empty() << endl;
	cout << "so phan tu:" << linklist.getSize() << endl;
	linklist.printList();
	system("pause");
	return 0;
}
