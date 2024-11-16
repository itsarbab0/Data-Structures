#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Node
{
    friend class LinkedList;
public:
    int Data;
    Node* Left;
    Node* Right;
    Node* Up;
    Node* Down;

    Node()
    {
        Data = 0;
        Left = NULL;
        Right = NULL;
        Up = NULL;
        Down = NULL;
    }
    Node(int d)
    {
        Data = d;
        Left = NULL;
        Right = NULL;
        Up = NULL;
        Down = NULL;
    }
};

class LinkedList
{

public:
    Node* Head;
    int TotRows, TotCols;
    vector<Node*> VisitedNode;
    LinkedList()
    {
        Head = NULL;
        TotRows = 0;
        TotCols = 0;
    }
    void insert(int value, int rows, int cols)
    {
        Node* newNode = new Node(value);
        if (Head == NULL)
        {
            Head = newNode;
            return;
        }

        Node* Current = Head;
        while (Current->Down != NULL)
        {
            Current = Current->Down;
        }
        if (cols == 0)
        {
            Current->Down = newNode;
            newNode->Up = Current;
            return;
        }

        while (Current->Right != NULL)
        {
            Current = Current->Right;

        }

        Current->Right = newNode;
        newNode->Left = Current;

        if (rows != 0)
        {
            Current->Up->Right->Down = newNode;
            newNode->Up = Current->Up->Right;
        }

    }

    int ClueRow(int value)
    {
        int Next = 0;  
        int Remin;   
        while (value > 0)
        {
            Remin = 0;
            Remin = value % 10;
            Next = Next + Remin;
            value = value / 10;

        }
        int result = (Next % TotRows) + 1;

        return result;
    }

    int ClueCols(int value)
    {
        int count = 0;
        while (value > 0)
        {
            value = value / 10;
            count++;
        }

        if (count > TotRows)
        {
            return -1;
        }
        return count;
    }

    Node* visited(Node* Current)
    {
        cout << Current->Data << " -> ";

        Node* temp = Head;
        for (int i = 0; i < VisitedNode.size(); i++)
        {
            if (VisitedNode[i] == Current)
            {
                cout << "\nElite not found\n";
                return NULL;
            }
        }
        VisitedNode.push_back(Current);

        int row = ClueRow(Current->Data);
        int column = ClueCols(Current->Data);
        if (column == -1)
        {
            return NULL;
        }

        for (int i = 1; i < row; i++)
        {
            temp = temp->Down;
        }

        for (int j = 1; j < column; j++)
        {
            temp = temp->Right;
        }

        if (temp == Current)
        {
            EliteNode(Current);
            return NULL;
        }
        return temp;
    }



    void setRows(int r)
    {
        TotCols = r;
    }
    void setCols(int c)
    {
        TotCols = c;
    }

    void Display()
    {
        Node* Current = Head;
        Node* Current1 = Current;
        while (Current != 0)
        {
            while (Current1 != 0)
            {
                cout << Current1->Data << " ";
                Current1 = Current1->Right;
            }
            cout << endl;
            Current = Current->Down;
            Current1 = Current;
        }
    }

    void EliteNode(Node* Current)
    {
        cout << "Elite Node has been found.";
        cout << endl;
        cout << "Data is :" << Current->Data;
    }
};

int main()
{
    LinkedList Obj;
    {
        ifstream Inp;
        Inp.open("Data.txt");
        int rows = 0;
        string value;
        while (!Inp.eof())
        {
            getline(Inp, value);
            rows++;
        }
        Inp.close();
        int cols = 1;
        for (int i = 0; i < value.size(); i++)
        {
            if (value[i] == ',')
            {
                cols++;
            }
            else
            {
                continue;
            }
        }

        Obj.setRows(rows);
        Obj.setCols(cols);

        Inp.open("Data.txt");
        int k;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Inp >> k;
                Inp.ignore();
                Obj.insert(k, i, j);


            }
        }

        Inp.close();

    }


    Obj.Display();


    Node* Current = Obj.Head;
    while (Current != NULL)
    {
        Current = Obj.visited(Current);
    }


    return 0;
}
