//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//class Node
//{
//public:
//	stack<queue<int>>st;
//	Node* next;
//	Node(stack<queue<int>>s)
//	{
//		this->st = s;
//		this->next = NULL;
//	}
//	~Node()
//	{
//		if (next)
//		{
//			next = NULL;
//			delete next;
//		}
//	}
//};
//class LinkedList
//{
//private:
//	Node* Head;
//public:
//	LinkedList()
//	{
//		this->Head = NULL;
//	}
//	void InsertNode()
//	{
//		Node* newNode = new Node(InsertQueinStack());
//		if (Head == NULL)
//		{
//			Head = newNode;
//		}
//		else
//		{
//			Node* temp = Head;
//			while (temp->next != NULL)
//			{
//				temp = temp->next;
//			}
//			temp->next = newNode;
//		}
//	}
//	queue<int> inserinQueue()
//	{
//		queue<int>Que;
//		int n;
//		cout << " Enter how many numbers you want to add in Queue:";
//		cin >> n;
//		
//		for (int i = 0; i < n; i++)
//		{
//			int data;
//			cout << " Enter the Data:";
//			cin >> data;
//			Que.push(data);
//		}
//		return Que;
//	}
//	stack<queue<int>> InsertQueinStack()
//	{
//		stack <queue<int>> St;
//		cout << " Enter the Number of Queues in Stack: ";
//		int n = 0;
//		cin >> n;
//		for (int i = 0; i < n; i++)
//		{
//			queue<int>q(inserinQueue());
//			St.push(q);
//		}
//		return St;
//	} 
//	void Delete(int nodeIndex)
//	{
//		Node* temp = Head;
//		int nodelen = 0;
//		if (Head == NULL)
//		{
//			return;
//		}
//		if (nodeIndex == 1)
//		{
//			Head = Head->next;
//			temp->next = NULL;
//			delete temp;
//			return;
//		}
//		
//		Node* Prev = NULL;
//		while (temp != NULL && nodelen <= nodeIndex - 2)
//		{
//			Prev = temp;
//			temp = temp->next;
//			nodelen++;
//		}
//		Prev->next = temp->next;
//		temp->next = NULL;
//		delete temp;
//		return;
//	}
//	void DeleteStack(int nodeIndex)
//	{
//
//	}
//	void Display()
//	{
//		Node* current = Head;
//		int nodeNumber = 1;
//
//		while (current != nullptr)
//		{
//			cout << "Node " << nodeNumber << " Stack of Queues:" << endl;
//			stack<queue<int>> currentStack = current->st;
//			int i = 0;
//			while (!currentStack.empty()) 
//			{
//				queue<int> currentQueue = currentStack.top();
//				currentStack.pop();
//
//				cout << "Queue " << i + 1 << ":";
//				queue<int> tempQueue = currentQueue;
//				while (!tempQueue.empty())
//				{
//					cout << tempQueue.front() << " ";
//					tempQueue.pop();
//				}
//				cout << endl;
//				i++;
//			}
//			current = current->next;
//			nodeNumber++;
//		}
//	}
//	int getLenght()
//	{
//		int count = 0;
//		Node* temp = Head;
//		while (temp != NULL)
//		{
//			count++;
//			temp = temp->next;
//		}
//		return count;
//	}
//};
//int main()
//{
//	LinkedList Obj;
//	int count = 0;
//	
//	int choice;
//
//	do 
//	{
//		
//		cout << " 1. Insert Node" << endl;
//		cout << " 2. Display" << endl;
//		cout << " 4. Delete Node" << endl;
//		cout << " 5. Delete Stack" << endl;
//		cout << " 3. Exit" << endl;
//		cout << " Enter your choice: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			Obj.InsertNode();
//			count++;
//			break;
//		case 2:
//			Obj.Display();
//			break;
//		case 3:
//			cout << "Exiting program." << endl;
//			break;
//		case 4:
//			count = Obj.getLenght();
//			cout << " Total Nodes are: " << count << endl;
//			cout << " Enter the Node Index to Delete: ";
//			int n;
//			cin >> n;
//			Obj.Delete(n);
//			break;
//		case 5:
//			count = Obj.getLenght();
//			cout << " Total Nodes are: " << count << endl;
//			cout << " Enter the Node Index to Delete Stack: ";
//			cin >> n;
//			break;
//		default:
//			cout << "Invalid choice. Try again." << endl;
//		}
//	} while (choice != 3);
//
//	return 0;
//}
