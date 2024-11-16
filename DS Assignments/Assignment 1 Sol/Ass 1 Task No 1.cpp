#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    T Data;
    Node<T>* next;

    Node(T d)
    {
        this->Data = d;
        this->next = nullptr;
    }
};

template<typename T>
class linklist
{
public:
    Node<T>* Head;
    Node<T>* tail;

    linklist()
    {
        this->Head = nullptr;
        this->tail = nullptr;
    }

    ~linklist()
    {
        while (Head != nullptr)
        {
            Node<T>* temp = Head;
            Head = Head->next;
            delete temp;
        }
    }

    void creatlist(T d)
    {
        Node<T>* temp = new Node<T>(d);
        if (Head == nullptr)
        {
            Head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void partition(int k)
    {
        if (Head == nullptr)
        {
            cout << " Error: The list is Empty." << endl;
            return;
        }

        int count = 0;
        Node<T>* current = Head;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        if (count < k)
        {
            cout << " Error: Not Enough Nodes in the list for " << k << " Partition." << endl;
            return;
        }

        current = Head;
        int partitionsize = count / k;

        for (int i = 0; i < partitionsize; i++)
        {
            Node<T>* SubListHead = current;
            Node<T>* SubListTail = nullptr;

            for (int j = 0; j < k; j++)
            {
                SubListTail = current;
                current = current->next;
            }

            if (i < count % k)
            {
                SubListTail = current;
                current = current->next;
            }

            SubListTail->next = nullptr;
            print(SubListHead);
        }
    }

    void print(Node<T>* ListHead)
    {
        cout << "[";
        Node<T>* temp = ListHead;
        while (temp != nullptr)
        {
            cout << temp->Data;
            if (temp->next != nullptr)
            {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "-> NULL]" << "->";
    }
};

int main()
{
    linklist<int> Obj;
    int Data, num;
    
    cout << " Enter the number of Nodes you want to Add: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << " Enter the Data for Node " << i + 1 << ": ";
        cin >> Data;
        Obj.creatlist(Data);
    }

    cout << " Enter the number of partitions for major link list: ";
    int k;
    cin >> k;
    Obj.partition(k);

    return 0;
}
