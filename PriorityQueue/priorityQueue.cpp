// priorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

class PriorityQueue {
public:
	int data;
	int size;
	PriorityQueue();
	bool is_empty();
	int a[];
	int leftChild(int i) {
		if (2 * i <= size) return 2 * i;
		else return 0;
	}
	int rightChild(int i) {
		if (2 * i + 1 <= size) return 2 * i + 1;
		else return 0;
	}
	int parent(int i) {
		if (i == 1) return 0;
		int p = i / 2;
		return p;
	}
	void heapify(int i);
	//void buildHeap();
	void increaseKey(int i, int key);
	void enqueue(int data);
	int dequeue();
	void display();
	int min();

};
PriorityQueue::PriorityQueue() {
	size = 0;
	a[0] = 0;
}
bool PriorityQueue::is_empty() {
	if (size == 0) return true;
	else return false;
}
void PriorityQueue::increaseKey(int i, int key) {
	if (a[i] < key) {
		if (size == 1) a[i] = key;
		else {
			a[i] = key;
			int j = parent(i);
			while (1) {
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
					i = j;
				}
				else break;
			}
		}
	}
}
void PriorityQueue::enqueue(int data) {
	//a[1], a[0] = 0, ko in ra
	int temp = size + 1;
	a[temp] = -100;
	size++;
	increaseKey(temp, data);
}
int PriorityQueue::dequeue() {
	swap(a[1], a[size]);
	int p = a[size];
	size--;
	heapify(1);
	return p;
}
void PriorityQueue::display() {
	for (int i = 0; i <= size; i++) {
		cout << a[i] << " -> ";
	}
}
int PriorityQueue::min() {
	return 0;
}
void PriorityQueue::heapify(int i) {
	if (i <= size / 2) {
		int l = leftChild(i);
		int r = rightChild(i);
		int largest;
		if (l != 0 || r != 0) {
			if (l <= size && (a[l] > a[i])) {
				largest = l;
			}
			else largest = i;
			if ((r <= size) && (r != 0)) {
				if (a[r] > a[largest]) {
					largest = r;
				}
			}
			if (largest != i) {
				swap(a[i], a[largest]);
				heapify(largest);
			}
		}

	}
}
//void PriorityQueue::buildHeap() {
//	for (int i = size / 2; i >= 1; i--) {
//		heapify(i);
//	}
//}
int main()
{
	PriorityQueue priorityQueue;
	priorityQueue.enqueue(16);
	priorityQueue.enqueue(14);
	priorityQueue.enqueue(3);
	priorityQueue.enqueue(10);
	priorityQueue.enqueue(11);
	priorityQueue.enqueue(5);
	priorityQueue.display();
	cout << "\n";
	priorityQueue.increaseKey(3, 15);
	priorityQueue.display();
	//cout << "\n";
	//cout << priorityQueue.dequeue() << endl;
	//priorityQueue.display();
	//cout << "\n";
	//cout << priorityQueue.dequeue() << endl;
	//priorityQueue.display();
	system("pause");
    return 0;
}

