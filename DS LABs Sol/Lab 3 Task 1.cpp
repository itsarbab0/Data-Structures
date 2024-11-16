#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T Data;
	Node* next;

	Node(T d)
	{
		this->Data = d;
		this->next = NULL;
	}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;

public:
	LinkedList()
	{
		this->Head = NULL;
		this->Tail = NULL;
	}
	~LinkedList()
	{
		while (Head)
		{
			Node<T>* temp = Head;
			Head = Head->next;
			delete temp;
		}
	}
	void InsertAtStart(T D)
	{
		Node<T>* newNode = new Node<T>(D);
		if (!Head)
		{
			Head = Tail = newNode;
		}
		else
		{
			Tail->next = newNode;
			Tail = newNode;
		}
	}
	void InsertAtEnd(T D)
	{
		Node<T>* temp = new Node<T>(D);
		if (Tail == NULL)
		{
			Head = Tail = temp;
		}
		else
		{
			Tail->next = temp;
			Tail = temp;
		}
	}

	void Print()
	{
		Node<T>* temp = Head;
		while (temp != NULL)
		{
			cout << " " << temp->Data << "->";
			temp = temp->next;
		}
		cout << endl;
	}
	bool Search(T Data)
	{
		Node<T>* temp = Head;
		while (temp != NULL)
		{
			if (temp->Data == Data)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool IsEmpty()
	{
		return Head == NULL;
	}
	void InsertAtPosition(Node<T>* Mid, T Pos, T D)
	{
		Node<T>* temp = Mid;
		if (Pos == 1)
		{
			InsertAtStart(Mid, D);
		}
		Node<T>* nodetoInsert = new Node(D);
		nodetoInsert->next = temp->next;
		temp->next = nodetoInsert;

	}
	void InsertAtValue()
	{
		T Val1, Val2;
		cout << " Enter the Value you want to Add: ";
		cin >> Val1;
		Print();
		cout << " Enter the VAlue you Want to Add before: ";
		cin >> Val2;
		Node<T>* temp = Head;
		int count = 0;
		while (temp->Data != Val2)
		{
			temp = temp->next;
			count++;
		}

		InsertAtPosition(temp, count, Val1);


	}
	void DeleteAtStart()
	{
		if (Head)
		{
			Node<T>* temp = Head;
			Head = Head->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void DeleteAllVal(T Value)
	{
		Node<T>* Curr = Head;
		Node<T>* Prev = NULL;
		while (Curr != NULL)
		{
			if (Curr->Data == Value)
			{
				if (Prev)
				{
					Prev->next = Curr->next;
				}
				else
				{
					Head = Curr->next;
				}

				Node<T>* temp = Curr;
				Curr = Curr->next;
				delete temp;
			}
			else
			{
				Prev = Curr;
				Curr = Curr->next;
			}
		}

	}
	void Reverse()
	{
		Node<T>* NextNode = Head;
		Node<T>* Curr = Head;
		Node<T>* Prev = NULL;
		if (Head == NULL || Head->next == NULL)
		{
			cout << " There is only Single Node or No Node is created " << endl;
		}
		while (Curr != NULL)
		{
			NextNode = Curr->next;
			Curr->next = Prev;
			Prev = Curr;
			Curr = NextNode;
		}
		Tail = Head;
		Head = Prev;

	}
	bool IsPallindrome()
	{
		if (Head == NULL || Head->next == NULL)
		{
			return true;

		}
		Node<T>* CNT = Head;
		int count = 0;
		while (CNT != NULL)
		{
			CNT = CNT->next;
			count++;
		}
		cout << " The number of Nodes are: " << count << endl;
		Node<T>* Mid = Head;
		Node<T>* Last = Head;
		while (Last && Last->next)
		{
			Mid = Mid->next;
			Last = Last->next->next;
		}
		Node<T>* SecndHalf = Mid;
		Node<T>* Prev = NULL;
		Node<T>* NextNode = NULL;
		while (SecndHalf != NULL)
		{
			NextNode = SecndHalf->next;
			SecndHalf->next = Prev;
			Prev = SecndHalf;
			SecndHalf = NextNode;
		}
		Node<T>* Part1 = Head;
		Node<T>* Part2 = Prev;
		while (Part1 && Part2)
		{
			if (Part1->Data != Part2->Data)
			{
				return false;
			}
			Part1 = Part1->next;
			Part2 = Part2->next;
		}
		SecndHalf = Prev;
		Prev = nullptr;
		NextNode = nullptr;
		while (SecndHalf != NULL)
		{
			NextNode = SecndHalf->next;
			SecndHalf->next = Prev;
			Prev = SecndHalf;
			SecndHalf = NextNode;
		}

		return true;
	}
	void Swap(int k)
	{
		if (k <= 0)
		{
			cout << "Invalid Index" << endl;
			return;
		}

		int count = 0;
		Node<T>* temp = Head;
		Node<T>* FirstPrev = NULL;
		Node<T>* First = NULL;
		Node<T>* SecondPrev = NULL;
		Node<T>* Second = NULL;

		while (temp != NULL)
		{
			count++;
			if (count == k - 1)
			{
				FirstPrev = temp;
			}
			else if (count == k)
			{
				First = temp;
			}
			else if (count == count - k + 1)
			{
				SecondPrev = temp;
			}
			else if (count == count - k + 2)
			{
				Second = temp;
			}

			temp = temp->next;
		}

		if (!First || !Second)
		{
			cout << "Invalid Index" << endl;
			return;
		}


		if (FirstPrev)
		{
			FirstPrev->next = Second;
		}
		else
		{
			Head = Second;
		}

		if (SecondPrev)
		{
			SecondPrev->next = First;
		}
		else
		{
			Head = First;
		}

		Node<T>* tempNext = Second->next;
		Second->next = First->next;
		First->next = tempNext;
	}
};

int main()
{
	LinkedList<int> Obj;
	int data = 0;
	char choice = '\0';

	while (choice != 'q' && choice != 'Q')
	{
		cout << "Menu:" << endl;
		cout << "1. Insert at Head" << endl;
		cout << "2. Insert at Tail" << endl;
		cout << "3. Print" << endl;
		cout << "4. Search" << endl;
		cout << "5. Delete at Start" << endl;
		cout << "6. Delete all Value" << endl;
		cout << "7. Reverse" << endl;
		cout << "8. Is Palindrome" << endl;
		cout << "9. To Swap Nodes" << endl;
		cout << "q. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "Enter the Data: ";
			cin >> data;
			Obj.InsertAtStart(data);
			break;
		case '2':
			cout << "Enter the Data: ";
			cin >> data;
			Obj.InsertAtEnd(data);
			break;
		case '3':
			Obj.Print();
			break;
		case '4':
			cout << "Enter the value to search for: ";
			cin >> data;
			if (Obj.Search(data))
			{
				cout << "Value found." << endl;
			}
			else
			{
				cout << "Value not found." << endl;
			}
			break;
		case '5':
			Obj.DeleteAtStart();
			break;
		case'6':
			cout << " Enter the Value you want to Delete: ";
			cin >> data;
			Obj.DeleteAllVal(data);
			break;
		case '7':
			Obj.Reverse();
			break;
		case '8':
			if (Obj.IsPallindrome())
			{
				cout << "The list is a palindrome." << endl;
			}
			else
			{
				cout << "The list is Not a palindrome." << endl;
			}
			break;
		case'9':
			cout << " Enter the Index Want to swap: ";
			cin >> data;
			Obj.Swap(data);
			break;
		case 'q':
		case 'Q':
			cout << "Quitting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}

