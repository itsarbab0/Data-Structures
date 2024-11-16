#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
template<typename T>
class BST
{
	Node<T>* root;
public:
	BST()
	{
		this->root = NULL;
	}
	BST(BST& Obj)
	{
		root = DeepCopy(Obj.root);
	}

};