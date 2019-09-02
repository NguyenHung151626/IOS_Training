// search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class TreeNode {
public:
	int value;
	TreeNode *left;
	TreeNode *right;
};
class BinarySearchTree {
public:
	friend class TreeNode;
	BinarySearchTree();
	void insert(int key);
	TreeNode* search(int key);
	TreeNode* findMin();
	TreeNode* findMax();
	TreeNode* successor(int key);
	TreeNode* predcessor(int key);
	void display();
	void deleteNode(int key);
	
private:
	TreeNode *root;
	void insert(int key, TreeNode* root);
	TreeNode* search(int key, TreeNode* root);
	TreeNode* findMin(TreeNode* root);
	TreeNode* findMax(TreeNode* root);
	TreeNode* parent(TreeNode* node);
	TreeNode* deleteNode(int key, TreeNode* root);
	void inOrderDisplay(TreeNode* root);

	
};
BinarySearchTree::BinarySearchTree() {
	root = NULL;
}
void BinarySearchTree::insert(int key) {
	if (root == NULL) {
		TreeNode* newNode = new TreeNode();
		newNode->value = key;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
	}
	else {
		insert(key, root);
	}
}
void BinarySearchTree::insert(int key, TreeNode* rootSub) {
	if (key < rootSub->value) {
		if (rootSub->left == NULL) {
			TreeNode* newNode = new TreeNode();
			newNode->value = key;
			newNode->left = NULL;
			newNode->right = NULL;
			rootSub->left = newNode;
		}
		else {
			insert(key, rootSub->left);
		}
	}
	else {
		if (rootSub->right == NULL) {
			TreeNode* newNode = new TreeNode();
			newNode->value = key;
			newNode->left = NULL;
			newNode->right = NULL;
			rootSub->right = newNode;
		}
		else {
			insert(key, rootSub->right);
		}
	}
}
TreeNode* BinarySearchTree::search(int key, TreeNode* rootSub) {
	if (rootSub == NULL) return NULL;
	else {
		if (key == rootSub->value) return rootSub;
		else {
			TreeNode* temp = rootSub;
			if (key < temp->value) {
				temp = temp->left;
				return search(key, temp);
			}
			else {
				temp = temp->right;
				return search(key, temp);
			}
		}
	}
}
TreeNode* BinarySearchTree::search(int key) {
	return search(key, root);
}
TreeNode* BinarySearchTree::findMin(TreeNode* rootSub) {
	TreeNode* temp = rootSub;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
TreeNode* BinarySearchTree::findMin() {
	TreeNode* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
TreeNode* BinarySearchTree::findMax(TreeNode* rootSub) {
	TreeNode* temp = rootSub;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}
TreeNode* BinarySearchTree::findMax() {
	TreeNode* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}
TreeNode* BinarySearchTree::parent(TreeNode* node) {
	if (node == root) return NULL;
	else {
		TreeNode* temp = root;
		TreeNode* p = new TreeNode();
		while (node->value != temp->value) {
			p = temp;
			if (node->value < temp->value) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return p;
	}
}
TreeNode* BinarySearchTree::successor(int key) {
	TreeNode* temp = search(key);
	if (key == findMax()->value) return findMax();
	if (temp->right != NULL) {
		return findMin(temp->right);
	}
	else {
		//parent dau tien co con trai
		//tim ve nut cha
		//check con trai
			//neu co: kiem tra con phai co phai no hay ko
			//neu ko: lap thay cha, thay ca no
		TreeNode* p = parent(temp);
		TreeNode* p1 = new TreeNode();
		if (p == root) {
			if (p->value > temp->value) return p;
			else return temp;
		}
		else {
			while (temp != root && temp == p->right)
			{
				temp = p;
				p = parent(p);
				if (p == root) {
					p = temp;
				}
			}
			return p;
		}
	}
}
TreeNode* BinarySearchTree::predcessor(int key) {
	//lon nhat trong cac so < key
	TreeNode* temp = search(key);
	//neu la so nho nhat ko co predcessor tra ve key
	if (key == findMin()->value) return findMin();
	if (temp->left != NULL) {
		return findMax(temp->left);
	}
	// ko co con trai
	else {
		//parent dau tien co con phai la to tien cua no hoac no
		TreeNode* p = parent(temp);
		if (p == root) {
			if (p->value > temp->value) return p;
			else return temp;
		}
		else {
			while (temp != root && temp == p->left)
			{
				temp = p;
				p = parent(p);
				if (p == root) {
					p = temp;
				}
			}
			return p;
		}
	}
}
TreeNode* BinarySearchTree::deleteNode(int key, TreeNode* root)
{
	if (root == NULL)
		return root;
	else if (key < root->value)
		root->left = deleteNode(key, root->left);
	else if (key > root->value)
		root->right = deleteNode(key, root->right);
	//tim dc => root
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			TreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			TreeNode* min = findMin(root->right);
			root->value = min->value;
			root->right = deleteNode(min->value, root->right);
		}
	}
	return root;
}
void BinarySearchTree::deleteNode(int key) {
	root = deleteNode(key, root);
}
void BinarySearchTree::display() {
	inOrderDisplay(root);
}
void BinarySearchTree::inOrderDisplay(TreeNode* root) {
	if (root != NULL) {
		inOrderDisplay(root->left);
		cout << root->value << " -> ";
		inOrderDisplay(root->right);
	}
}

int main()
{
	BinarySearchTree binarySearchTree;
	/*binarySearchTree.insert(10);*/
	//binarySearchTree.insert(1);
	//binarySearchTree.insert(2);
	//binarySearchTree.insert(20);
	//binarySearchTree.insert(-9);
	//binarySearchTree.insert(7);
	//binarySearchTree.insert(16);
	//binarySearchTree.insert(15);
	//binarySearchTree.insert(24);
	//binarySearchTree.insert(23);
	//binarySearchTree.insert(27);
	//binarySearchTree.insert(-11);
	//binarySearchTree.insert(-8);
	binarySearchTree.insert(50);
	binarySearchTree.insert(30);
	binarySearchTree.insert(55);
	binarySearchTree.insert(25);
	binarySearchTree.insert(35);
	binarySearchTree.insert(31);
	binarySearchTree.insert(37);
	binarySearchTree.insert(10);
	binarySearchTree.insert(20);
	binarySearchTree.insert(23);
	binarySearchTree.insert(19);
	binarySearchTree.display();
	cout << "\n";
	//binarySearchTree.deleteNode(-9);
	//binarySearchTree.display();
	cout << "\n";
	//cout << (binarySearchTree.search(1))->left->value << endl;
	cout << "successor: " << binarySearchTree.successor(23)->value << endl;
	cout << "predcessor: " << binarySearchTree.predcessor(50)->value << endl;
	system("pause");
    return 0;
}

