#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class Node
{
public:
	int Data;
	Node* left;
	Node* right;
	Node(int d)
	{
		this->Data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
template<typename T>
class BST
{
private:
	Node<T>* root;

	Node<T>* insert(Node<T>* temp, T Val)
	{
		if (temp == NULL)
		{
			return new Node<T>(Val);
		}

		if (Val < temp->Data)
		{
			temp->left = insert(temp->left, Val);
		}
		else if (Val > temp->Data)
		{
			temp->right = insert(temp->right, Val);
		}

		return temp;
	}
	Node<T>* getMini(Node<T>* temp)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}
	Node<T>* toDelete(Node<T>* temp, T key)
	{
		if (temp == NULL)
		{
			return temp;
		}
		if (key < temp->Data)
		{
			temp->left = toDelete(temp->left, key);
		}
		else if (key > temp->Data)
		{
			temp->right = toDelete(temp->right, key);
		}
		else
		{
			if (temp->left == NULL)
			{
				Node<T>* nodeToDel = temp->right;
				delete temp;
				return nodeToDel;
			}
			else if (temp->right == NULL)
			{
				Node<T>* nodeToDel = temp->left;
				delete temp;
				return nodeToDel;
			}

			Node<T>* Min = getMini(temp->right);
			temp->Data = Min->Data;
			temp->right = toDelete(temp->right, Min->Data);
		}

		return temp;
	}

	int getHeight(Node<T>* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		int left = getHeight(temp->left);
		int right = getHeight(temp->right);

		int ans = max(left, right) + 1;
		return ans;
	}
	int getDepth(Node<T>* temp, T Val, int depth = 0)
	{
		if (temp == NULL)
		{
			return -1;
		}
		if (Val == temp->Data)
		{
			return depth;
		}
		if (Val < temp->Data)
		{
			return getDepth(temp->left, Val, depth + 1);
		}
		else
		{
			return getDepth(temp->right, Val, depth + 1);
		}
	}
	bool isBalanced(Node<T>* temp)
	{
		if (temp == NULL)
		{
			return true;
		}
		bool left = isBalanced(temp->left);
		bool right = isBalanced(temp->right);
		bool diff = abs(getHeight(temp->left) - getHeight(temp->right)) <= 1;

		if (left && right && diff)
		{
			return true;
		}
		return false;
	}
	Node<T>* ArraytoBST(T sortArray[], int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}
		int mid = (start + end) / 2;
		Node<T>* nodeToinsert = new Node<T>(sortArray[mid]);
		nodeToinsert->left = ArraytoBST(sortArray, start, mid - 1);
		nodeToinsert->right = ArraytoBST(sortArray, mid + 1, end);
		return nodeToinsert;
	}
	void PathSum(Node<T>* temp, T CurrSUM, vector<T>& Sum)
	{
		if (temp == NULL)
		{
			return;
		}
		CurrSUM = CurrSUM + temp->Data;
		if (temp->left == NULL && temp->right == NULL)
		{
			Sum.push_back(CurrSUM);
			return;
		}
		PathSum(temp->left, CurrSUM, Sum);
		PathSum(temp->right, CurrSUM, Sum);
	}
public:
	BST()
	{
		this->root = NULL;
	}
	void insert(T Val)
	{
		root = insert(root, Val);
	}
	void erase(T key)
	{
		root = toDelete(root, key);
	}
	int Height()
	{
		return getHeight(root);
	}
	int depth(T key)
	{
		return getDepth(root, key);
	}
	bool Balanced()
	{
		return isBalanced(root);
	}
	void createPerfectTree(T sortData[], int n)
	{
		root = ArraytoBST(sortData, 0, n - 1);
	}
	vector<T>pathSum()
	{
		vector<T>result;
		PathSum(root, 0, result);
		return result;
	}
	Node<T>* getRoot()
	{
		return root;
	}
	

};
int main()
{
	BST<int>Obj;
	int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(Arr) / sizeof(Arr[0]);

	for (int i = 0; i < size; i++)
	{
		Obj.insert(Arr[i]);
	}
	
	Obj.erase(4);
	cout << " Height of BST is: " << Obj.Height() << endl;
	cout << " Depth of key 7 is: " << Obj.depth(7) << endl;
	if (Obj.Balanced())
	{
		cout << " Tree is Balanced " << endl;
	}
	else
	{
		cout << " Tree is Balanaced " << endl;
	}
	Obj.createPerfectTree(Arr, size);



	cout << endl;
	vector<int>pathSum = Obj.pathSum();
	cout << " Path Sum: ";
	for (int sum : pathSum)
	{
		cout << sum << " ";
	}
	cout << endl;
	return 0;
}