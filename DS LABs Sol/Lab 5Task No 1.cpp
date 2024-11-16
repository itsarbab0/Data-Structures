//#include<iostream>
//using namespace std;
//template <typename T>
//class Node
//{
//public:
//	T Data;
//	Node*next;
//	Node(T d)
//	{
//		this->Data = d;
//		this->next = NULL;
//	}
//};
//template <typename T>
//class Queue
//{
//private:
//	Node<T>*Front;
//	Node<T>*Rear;
//	int count;
//	int Capacity;
//public:
//	Queue(int Cap)
//	{
//		this->Front = NULL;
//		this->Rear = NULL;
//		this->count = 0;
//		this->Capacity = Cap;
//	}
//	bool isFull()
//	{
//		return count == Capacity;
//	}
//	bool isEmpty()
//	{
//		return count == 0;
//	}
//	int size()
//	{
//		return count;
//	}
//	void Enqueue(T d)
//	{
//		if (isFull())
//		{
//			cout << " Queue is Full " << endl;
//			return;
//		}
//		Node<T>* temp = new Node<T>(d);
//		if (isEmpty())
//		{
//			Front = Rear = temp;
//		}
//		else
//		{
//			Rear->next = temp;
//			Rear = temp;
//		}
//		count++;
//	}
//	void DeQueue()
//	{
//		if (isEmpty())
//		{
//			cout << " Queue is Empty" << endl;
//			return;
//		}
//		Node<T>*temp = Front;
//		Front = Front->next;
//		delete temp;
//		count--;
//	}
//
//	T getFront()
//	{
//		if (isEmpty())
//		{
//			cout << " Queue is Empty" << endl;
//			return T();
//		}
//		return Front->Data;
//	}
//	T getRear()
//	{
//		if (isEmpty())
//		{
//			cout << " Queue is Empty" << endl;
//			return T();
//		}
//		return Rear->Data;
//	}
//	void Display()
//	{
//		Node<T>*temp = Front;
//		while (temp != NULL)
//		{
//			cout << " " << temp->Data << "->";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//
//
//};
//int main()
//{
//	Queue<int> Obj(5);
//	Obj.Enqueue(21);
//	Obj.Enqueue(25);
//	Obj.Enqueue(35);
//	Obj.Enqueue(41);
//	Obj.Enqueue(44);
//	Obj.Display();
//	cout << " Front Node is: " << Obj.getFront() << endl;
//	cout << " The Rear Node is: " << Obj.getRear() << endl;
//	cout << " The Size Of Queue is: " << Obj.size() << endl;
//
//	while (!Obj.isEmpty())
//	{
//		cout << " DeQueue: " << Obj.getFront() << endl;
//		Obj.DeQueue();
//	}
//
//	if (Obj.isEmpty())
//	{
//		cout << " Queue is Empty " << endl;
//	}
//	else
//	{
//		cout << " Queue is not Empty " << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}