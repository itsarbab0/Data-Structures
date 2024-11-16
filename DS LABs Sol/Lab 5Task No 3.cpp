//#include <iostream>
//using namespace std;
//class Node 
//{
//public:
//    int Data;
//    Node* next;
//
//    Node(int d) 
//    {
//        this->Data = d;
//        this->next = NULL;
//    }
//};
//
//class MyStack 
//{
//private:
//    Node* Top;
//
//public:
//    MyStack() 
//    {
//    this->Top=NULL;
//    }
//
//    ~MyStack()
//    {
//        while (!isEmpty()) 
//        {
//            pop();
//        }
//    }
//
//    void push(int item) 
//    {
//        Node* newNode = new Node(item);
//        newNode->next = Top;
//        Top = newNode;
//    }
//
//    int pop()
//    {
//        if (isEmpty()) 
//        {
//            cerr << "Stack is Empty" << endl;
//            return -1; 
//        }
//
//        Node* temp = Top;
//        int poppedItem = temp->Data;
//        Top = Top->next;
//        delete temp;
//
//        return poppedItem;
//    }
//
//    int peek()
//    {
//        if (isEmpty())
//        {
//            cerr << "Stack is Empty" << endl;
//            return -1; 
//        }
//        return Top->Data;
//    }
//
//    bool isEmpty() 
//    {
//        return Top == NULL;
//    }
//    void display()
//    {
//        if (isEmpty())
//        {
//            cout << "Stack is empty." << endl;
//            return;
//        }
//
//        Node* current = Top;
//        while (current != NULL) 
//        {
//            cout << current->Data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//};
//
//class MyQueue 
//{
//private:
//    Node* Front;
//    Node* Rear;
//
//public:
//    MyQueue()
//    {
//        this->Front = NULL;
//        this->Rear = NULL;
//    }
//
//    ~MyQueue()
//    {
//        while (!isEmpty()) 
//        {
//            dequeue();
//        }
//    }
//
//    void EnQueue(int item) 
//    {
//        Node* newNode = new Node(item);
//
//        if (isEmpty()) 
//        {
//            Front = newNode;
//            Rear = newNode;
//        }
//        else {
//            Rear->next = newNode;
//            Rear = newNode;
//        }
//    }
//
//    int dequeue() 
//    {
//        if (isEmpty())
//        {
//            cerr << "Queue is Empty" << endl;
//            return -1; 
//        }
//
//        Node* temp = Front;
//        int DeQueuedItem = temp->Data;
//        Front = Front->next;
//        delete temp;
//
//        if (Front == NULL) 
//        {
//            Rear = NULL;
//        }
//
//        return DeQueuedItem;
//    }
//
//    int peek()
//    {
//        if (isEmpty())
//        {
//            cerr << "Queue is Empty" << endl;
//            return -1; 
//        }
//        return Front->Data;
//    }
//
//    bool isEmpty()
//    {
//        return Front == NULL;
//    }
//    void display() 
//    {
//        if (isEmpty())
//        {
//            cout << "Queue is Empty." << endl;
//            return;
//        }
//
//        Node* current = Front;
//        while (current != NULL) 
//        {
//            cout << current->Data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//};
//
//class MinQueue
//{
//public:
//    MyQueue Obj1;
//    MyQueue minQ;
//    MyStack MinStack;
//    void EnQueue(int item)
//    {
//        Obj1.EnQueue(item);
//
//        
//        if (MinStack.isEmpty() || item <= MinStack.peek())
//        {
//            MinStack.push(item);
//            minQ.EnQueue(item);
//        }
//        else 
//        {
//            minQ.EnQueue(MinStack.peek());
//        }
//    }
//
//    int DeQueue() 
//    {
//        if (isEmpty()) 
//        {
//            cerr << "Queue is Empty." << endl;
//            return -1; 
//        }
//
//        int FrontItem = Obj1.DeQueue();
//        minQ.DeQueue();
//
//       
//        if (FrontItem == MinStack.peek()) 
//        {
//            MinStack.pop();
//        }
//
//        return FrontItem;
//    }
//
//    int getMin() 
//    {
//        if (isEmpty()) 
//        {
//            cerr << "Queue is empty. Cannot getMin." << endl;
//            return -1; 
//        }
//        return minQ.peek();
//    }
//
//    bool isEmpty()
//    {
//        return Obj1.isEmpty();
//    }
//};
//
//int main() 
//{
//    MinQueue Obj;
//
//    Obj.EnQueue(3);
//    Obj.EnQueue(1);
//    Obj.EnQueue(4);
//
//    cout << " Minimum: " << Obj.getMin() << endl;
//
//    Obj.DeQueue();
//
//    cout << " Minimum: " << Obj.getMin() << endl;
//
//    Obj.EnQueue(2);
//
//    cout << " Queue contents: ";
//    Obj.Obj1.display(); 
//    cout << " MinQueue contents: ";
//    Obj.minQ.display(); 
//    cout << " Stack contents: ";
//    Obj.MinStack.display(); 
//
//    while (!Obj.isEmpty()) 
//    {
//        cout << " DeQueue: " << Obj.DeQueue() << endl;
//    }
//
//    return 0;
//}
