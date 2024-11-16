//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Node
//{
//public:
//	T Data;
//	Node* next;
//	Node(T d)
//	{
//		this->Data = d;
//		this->next = NULL;
//	}
//};
//
//template <typename T>
//class Stack
//{
//private:
//	Node<T>* Top;
//
//public:
//	Stack()
//	{
//		this->Top = NULL;
//	}
//
//	void Push(T D)
//	{
//		Node<T>* temp = new Node<T>(D);
//		temp->next = Top;
//		Top = temp;
//	}
//
//	bool isEmpty()
//	{
//		return Top == NULL;
//	}
//
//	T Pop()
//	{
//		if (isEmpty())
//		{
//			cout << "Stack is Empty" << endl;
//			return T();
//
//		}
//		T Value = Top->Data;
//		Node<T>* temp = Top;
//		Top = Top->next;
//		delete temp;
//		return Value;
//	}
//};
//
//template <typename T>
//class StackQueue
//{
//private:
//	Stack<T> stack1;
//	Stack<T> stack2;
//
//public:
//	void enQueue(T d1)
//	{
//		stack1.Push(d1);
//	}
//
//	bool isEmpty()
//	{
//		return stack1.isEmpty() && stack2.isEmpty();
//	}
//
//
//	T deQueue()
//	{
//		if (isEmpty())
//		{
//			cout << "Queue is Empty" << endl;
//			return T();
//		}
//
//		if (stack2.isEmpty())
//		{
//			while (!stack1.isEmpty())
//			{
//				stack2.Push(stack1.Pop());
//			}
//		}
//		return stack2.Pop();
//	}
//
//
//};
//
//int main()
//{
//	StackQueue<int> Obj;
//	Obj.enQueue(1);
//	Obj.enQueue(2);
//	Obj.enQueue(3);
//	
//
//	cout << "Dequeue: " << Obj.deQueue() << endl;
//	cout << "Dequeue: " << Obj.deQueue() << endl;
//	cout << endl;
//	cout << endl;
//
//
//	Obj.enQueue(10);
//	Obj.enQueue(15);
//	Obj.enQueue(20);
//	Obj.enQueue(25);
//
//	while (!Obj.isEmpty())
//	{
//		cout << " DeQueue: " << Obj.deQueue() << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}