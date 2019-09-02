// BinaryTree.cpp : Defines the entry point for the console application.
//
//bai toan sap xep chi su dung phep so sanh
#include "stdafx.h"
#include <iostream>
using namespace std;
class Node {
public:
	int value;
	Node *left;
	Node *right;
};
class BinaryTreeSort {
public:
	friend class Node;
	BinaryTreeSort();
	void insert(int key);
	void insert(int key, Node *leaf);
	void InOrderDisplay();
	void InOrderDisplay(Node* rootSub);
	void destroy_tree();
private:
	Node *root;
};
BinaryTreeSort::BinaryTreeSort() {
	root = NULL;
}
void BinaryTreeSort::insert(int key) {
	if (root == NULL) {
		root = new Node();
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
	else BinaryTreeSort::insert(key, root);
}
void BinaryTreeSort::insert(int key, Node *leaf) {
	if (key < leaf->value) {
		if (leaf->left == NULL) {
			Node* newNode = new Node();
			newNode->value = key;
			newNode->left = NULL;
			newNode->right = NULL;
			leaf->left = newNode;
		}
		else insert(key, leaf->left);
	}
	else {
		if (leaf->right == NULL) {
			Node* newNode = new Node();
			newNode->value = key;
			newNode->left = NULL;
			newNode->right = NULL;
			leaf->right = newNode;
		}
		else insert(key, leaf->right);
	}
}
void BinaryTreeSort::InOrderDisplay() {
	if (root != NULL) {
		BinaryTreeSort::InOrderDisplay(root);
	}
	else cout << "Cay rong " << endl;
}
void BinaryTreeSort::InOrderDisplay(Node* rootSub) {
	if (rootSub != NULL) {
		InOrderDisplay(rootSub->left);
		cout << rootSub->value << " -> ";
		InOrderDisplay(rootSub->right);
	}
	else cout << " ";
}
void BinaryTreeSort::destroy_tree() {
	Node* p = root;
	root = NULL;
	delete p;
}
int main()
{
	BinaryTreeSort DaySo;
	DaySo.insert(10);
	DaySo.insert(1);
	DaySo.insert(2);
	DaySo.insert(33);
	DaySo.insert(13);
	DaySo.insert(2);
	DaySo.insert(5);
	DaySo.insert(3);
	DaySo.insert(3);
	DaySo.insert(5);
	DaySo.InOrderDisplay();
	DaySo.destroy_tree();
	cout << "after";
	DaySo.InOrderDisplay();
	system("pause");
    return 0;
}

