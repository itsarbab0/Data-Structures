////#include<iostream>
////using namespace std;
////template<typename T>
////class Node
////{
////public:
////	T Data;
////	Node* next;
////	Node* prev;
////	Node(T D)
////	{
////		this->Data = D;
////		this->next = NULL;
////		this->prev = NULL;
////	}
////};
////template<typename T>
////class DoubleLL
////{
////private:
////	Node<T>* Head;
////	Node<T>* Tail;
////public:
////	DoubleLL()
////	{
////		this->Head = NULL;
////		this->Tail = NULL;
////	}
////	//////// Task No 01
////	void InsertAtHEAD(T D)
////	{
////		Node<T>* temp = new Node<T>(D);
////		if (Head == NULL)
////		{
////			Head = Tail = temp;
////		}
////		else
////		{
////			temp->next = Head->next;
////			Head->prev = temp;
////
////			Head = temp;
////
////		}
////
////	}
////	void InsertAtTail(T D)
////	{
////		Node<T>* temp = new Node<T>(D);
////		temp->next = NULL; 
////
////		if (Tail == NULL)
////		{
////			Head = Tail = temp;
////		}
////		else
////		{
////			Tail->next = temp;
////			temp->prev = Tail;
////			Tail = temp;
////		}
////	}
////
////	void Print()
////	{
////		Node<T>* temp = Head;
////		while (temp != NULL)
////		{
////			cout<< temp->Data << "->";
////			temp = temp->next;
////		}
////		cout << endl;
////
////	}
////
////	void deleteAtHead()
////	{
////		if (Head == NULL)
////		{
////			return;
////		}
////		else if (Head == Tail)
////		{
////			delete Head;
////			Head = Tail = NULL;
////		}
////		else
////		{
////			Node<T>* temp = Head;
////			Head = Head->next;
////			Head->prev = NULL;
////			delete temp;
////		}
////	}
////	void deleteAtTail()
////	{
////		if (Head == NULL)
////		{			
////			return;
////		}
////		else if (Head == Tail)
////		{			
////			delete Head;
////			Head = Tail = NULL;
////		}
////		else
////		{
////			Node<T>* temp = Tail;
////			Tail = Tail->prev;
////			Tail->next = NULL;
////			delete temp;
////		}
////	}
////	~DoubleLL()
////	{
////		
////		Node<T>* Curr = Head;
////		while (Curr != NULL)
////		{
////			Node<T>* temp = Curr;
////			Curr = Curr->next;
////			delete temp;
////		}
////		Head = Tail = NULL;
////	}
////	//////// Task No 02
////	void insertSorted(T D)
////	{
////		Node<T>* temp = new Node<T>(D);
////
////		if (Head == NULL)
////		{
////			Head = Tail = temp;
////		}
////		else if (D < Head->Data)
////		{
////			
////			temp->next = Head;
////			Head->prev = temp;
////			Head = temp;
////		}
////		else
////		{
////			Node<T>* Curr = Head;
////			Node<T>* Prev = NULL;
////
////			while (Curr != NULL && Curr->Data < D)
////			{
////				Prev = Curr;
////				Curr = Curr->next;
////			}
////
////			
////			temp->next = Curr;
////			temp->prev = Prev;
////			Prev->next = temp;
////
////			if (Curr != NULL)
////			{
////				Curr->prev = temp;
////			}
////			else
////			{
////				Tail = temp;
////			}
////		}
////	}
////
////	//////// Task No 03
////	void DeleteDups()
////	{
////		if (Head == NULL)
////		{
////			return;
////		}
////
////		Node<T>* Curr = Head;
////
////		while (Curr != NULL)
////		{
////			
////			if (Curr->next != NULL && Curr->Data == Curr->next->Data)
////			{
////				Node<T>* Dup = Curr->next;
////				Curr->next = Dup->next;
////
////				if (Dup == Tail)
////				{
////					
////					Tail = Curr;
////				}
////
////				delete Dup;
////			}
////			else
////			{
////				Curr = Curr->next;
////			}
////		}
////	}
////
////	//////// Task No 5
////	int Get_N_Node()
////	{
////		int count = 0;
////		Node<T>* temp = Head;
////		if (temp == NULL)
////		{
////			cout << " No Node is Available " << endl;
////			return -1;
////		}
////		else
////		{
////			while (temp != NULL)
////			{
////				temp = temp->next;
////				count++;
////			}
////		}
////		return count;
////	}
////
////	//////// Task No 06
////	void Partition(T n)
////	{
////		if (Head == NULL)
////		{
////			return;
////		}
////
////		DoubleLL<T> Less; 
////		DoubleLL<T> GrtOrEq; 
////
////		Node<T>* Curr = Head;
////
////		while (Curr != NULL)
////		{
////			Node<T>* temp = Curr->next;
////
////			if (Curr->Data < n)
////			{
////				
////				if (Curr == Head)
////				{
////					Head = Curr->next;
////					Curr->next = NULL;
////				}
////				else
////				{
////					Curr->prev->next = Curr->next;
////					if (Curr->next != NULL)
////					{
////						Curr->next->prev = Curr->prev;
////					}
////					else
////					{
////						
////						Tail = Curr->prev;
////					}
////					Curr->next = NULL;
////				}
////
////				Less.InsertAtTail(Curr->Data);
////				delete Curr;
////			}
////			else
////			{
////				
////				if (Curr == Head)
////				{
////					Head = Curr->next;
////					Curr->next = NULL;
////				}
////				else
////				{
////					Curr->prev->next = Curr->next;
////					if (Curr->next != NULL)
////					{
////						Curr->next->prev = Curr->prev;
////					}
////					else
////					{
////						
////						Tail = Curr->prev;
////					}
////					Curr->next = NULL;
////				}
////
////				GrtOrEq.InsertAtTail(Curr->Data);
////				delete Curr;
////			}
////
////			Curr = temp;
////		}
////	
////		Less.Tail->next = Head;
////		if (Head != NULL)
////		{
////			Head->prev = Less.Tail;
////		}
////		Head = Less.Head;
////
////		Tail = GrtOrEq.Tail;
////	}
////
////
////
////};
////int main()
////{
////
////	DoubleLL<int> Obj;
////	cout << " Enter the Number of Nodes you want to Add: ";
////	int Num;
////	cin >> Num;
////	int Data;
////	for (int i = 0; i < Num; i++)
////	{
////		cout << " Enter the Data for Node " << i + 1 << ": ";
////		cin >> Data;
////		Obj.InsertAtTail(Data);
////	}
////
////	cout << "Original List: " << endl;
////	Obj.Print();
////
////	
////	Obj.insertSorted(4);
////	cout << "After insertSorted(4): " << endl;
////	Obj.Print();
////
////	Obj.DeleteDups();
////	cout << "After DeleteDups(): " << endl;
////	Obj.Print();
////
////	
////
////	int NodeCount = Obj.Get_N_Node();
////	cout << "Node count: " << NodeCount << endl;
////	//Obj.Partition(4);
////	//cout << "After Partition(4): " << endl;
////	//Obj.Print();
////
////	
////
////	return 0;
////}
