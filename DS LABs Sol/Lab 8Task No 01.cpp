//#include <iostream>
//#include<queue>
//using namespace std;
//
//class Node
//{
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int d)
//    {
//        data = d;
//        left = NULL;
//        right = NULL;
//    }
//};
//class BinaryTree
//{
//public:
//    Node* root;
//
//    BinaryTree()
//    {
//        this->root = NULL;
//    }
//
//    void inorder(Node* node) 
//    {
//        if (node != NULL)
//        {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//
// 
//    void preorder(Node* node) 
//    {
//        if (node != NULL) 
//        {
//            cout << node->data << " ";
//            preorder(node->left);
//            preorder(node->right);
//        }
//    }
//
// 
//    void postorder(Node* node)
//    {
//        if (node != NULL) 
//        {
//            postorder(node->left);
//            postorder(node->right);
//            cout << node->data << " ";
//        }
//    }
//    void LevelOrderTraversal(Node* temp)
//	{
//		if (temp == NULL)
//		{
//			return;
//		}
//		queue<Node*> q;
//		q.push(temp);
//		q.push(NULL);
//		while (!q.empty())
//		{
//			Node* cons = q.front();
//			q.pop();
//
//			if (cons == NULL)
//			{
//				cout << endl;
//				if (!q.empty())
//				{
//					q.push(NULL);
//				}
//			}
//			else
//			{
//				cout << cons->data << " ";
//				if (cons->left)
//				{
//					q.push(cons->left);
//				}
//				if (cons->right)
//				{
//					q.push(cons->right);
//				}
//			}
//		}
//	}
//   
//    bool searchNode(Node* node, int key) 
//    {
//        if (node == NULL) 
//        {
//            return false;
//        }
//
//        if (node->data == key) 
//        {
//            return true;
//        }
//
//        return searchNode(node->left, key) || searchNode(node->right, key);
//    }
//
//    void deleteNode(Node* node, int key) 
//    {
//        if (node == NULL)
//        {
//            return;
//        }
//
//        if (node->left != NULL && node->left->data == key) 
//        {
//            deleteDeepest(node->left);
//            return;
//        }
//        if (node->right != NULL && node->right->data == key) 
//        {
//            deleteDeepest(node->right);
//            return;
//        }
//
//        deleteNode(node->left, key);
//        deleteNode(node->right, key);
//    }
//
//    void deleteDeepest(Node* node) 
//    {
//        Node* temp = node;
//        Node* parent = NULL;
//        while (temp->right != NULL)
//        {
//            parent = temp;
//            temp = temp->right;
//        }
//
//        node->data = temp->data;
//
//        if (parent == NULL)
//        {
//            node = temp->left;
//        }
//        else 
//        {
//            parent->right = temp->left;
//            parent->right = NULL;
//        }
//
//        
//        delete temp;
//    }
//};
//
//int main() 
//{
//    BinaryTree tree;
//    tree.root = new Node(6);
//    tree.root->left = new Node(3);
//    tree.root->right = new Node(5);
//    tree.root->left->left = new Node(7);
//    tree.root->left->right = new Node(8);
//    tree.root->right->left = new Node(1);
//    tree.root->right->right = new Node(3);
//
//    cout << "Inorder traversal: ";
//    tree.inorder(tree.root);
//    cout << endl;
//
//    cout << "Preorder traversal: ";
//    tree.preorder(tree.root);
//    cout << endl;
//
//    cout << "Postorder traversal: ";
//    tree.postorder(tree.root);
//    cout << endl;
//    cout << " Level Order Traversal: " << endl;
//    tree.LevelOrderTraversal(tree.root);
//
//    int key = 5;
//    if (tree.searchNode(tree.root, key)) 
//    {
//        cout << "Found " << key << " in the tree." << endl;
//    }
//    else
//    {
//        cout << key << " not found in the tree." << endl;
//    }
//
//    key = 8;
//    tree.deleteNode(tree.root, key);
//
//    cout << "After deleting " << key << ": " << endl;
//    tree.LevelOrderTraversal(tree.root);
//    cout << endl;
//
//    return 0;
//}
