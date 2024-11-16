#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T Data;
    Node* next;

    Node(T value) 
    {
        this->Data = value;
        this->next = NULL;
    }
};

template <typename T>
class SinglyLinkedList 
{
public:
    Node<T>* Head;
    Node<T>* Tail;
    int size;

    SinglyLinkedList()
    {
        this->Head = NULL;
        this->Tail = NULL;
        this->size = 0;
    }

    void Append(T value)
    {
        Node<T>* NewNode = new Node<T>(value);
        if (Tail == NULL)
        {
            Head = Tail = NewNode;
        }
        else
        {
            Tail->next = NewNode;
            Tail = NewNode;
        }
        size++;
    }

    void Remove(T value) 
    {
        Node<T>* Current = Head;
        Node<T>* Prev = NULL;

        while (Current != NULL)
        {
            if (Current->Data == value) 
            {
                if (Prev == NULL) 
                {
                    Head = Current->next;
                }
                else 
                {
                    Prev->next = Current->next;
                }
                if (Tail == Current)
                {
                    Tail = Prev;
                }
                delete Current;
                size--;
                return;
            }
            Prev = Current;
            Current = Current->next;
        }
    }

    void Display() 
    {
        Node<T>* Current = Head;
        while (Current != NULL) 
        {
            cout << Current->Data << " ";
            Current = Current->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() 
    {
        Node<T>* Current = Head;
        while (Current != NULL) 
        {
            Node<T>* next = Current->next;
            delete Current;
            Current = next;
        }
    }
};
class Block
{
public:
    int Start_Byte_ID;
    int Tot_Bytes;
    Block* next;
    Block()
    {
        this->Start_Byte_ID = 0;
        this->Tot_Bytes = 0;
        this->next = NULL;
    }
    Block(int start, int size)
    {
        this->Start_Byte_ID = start;
        this->Tot_Bytes = size;
        this->next = NULL;
    }
};
class Program 
{
public:
    int Id;
    int Size;
    SinglyLinkedList<Block> blocks;

    Program() 
    {
        this->Id = 0;
        this->Size = 0;
    }

    Program(int id, int size)
    {
        this->Id = id;
        this->Size = size;
    }

    void AllocateMemory(Block block)
    {
        blocks.Append(block);
    }

    void DeallocateMemory(int blockId) 
    {
        Node<Block>* Current = blocks.Head;
        Node<Block>* Prev = NULL;

        while (Current != NULL) 
        {
            if (Current->Data.Start_Byte_ID == blockId) 
            {
                
                if (Prev == NULL)
                {
                   
                    blocks.Head = Current->next;
                }
                else 
                {
                    Prev->next = Current->next;
                }
                delete Current;
                return;
            }
            Prev = Current;
            Current = Current->next;
        }
    }
};

class MemoryManagementSystem 
{
private:
    SinglyLinkedList<Block> Pool;
    SinglyLinkedList<Program> Progs;
    int Size_Of_Mem;
    bool Strategy;

public:
    MemoryManagementSystem(int memorySize, bool firstFit)
    {
        this->Size_Of_Mem = memorySize;
        this->Strategy = firstFit;
        Pool.Append(Block(0, memorySize));
    }

    bool GetMem(int ProgramId, int memorySize) 
    {
        if (Strategy) 
        {
            Node<Block>* Current = Pool.Head;
            Node<Block>* Prev = NULL;

            while (Current != NULL) 
            {
                if (Current->Data.Tot_Bytes >= memorySize)
                {
                    if (Current->Data.Tot_Bytes == memorySize) 
                    {
                        Progs.Append(Program(ProgramId, memorySize));
                        if (Prev == NULL) 
                        {
                            Pool.Head = Current->next;
                        }
                        else 
                        {
                            Prev->next = Current->next;
                        }
                        delete Current;
                    }
                    else 
                    {
                        Current->Data.Start_Byte_ID = Current->Data.Start_Byte_ID + memorySize;
                        Current->Data.Tot_Bytes = Current->Data.Tot_Bytes - memorySize;
                        Progs.Append(Program(ProgramId, memorySize));
                    }
                    return true;
                }
                Prev = Current;
                Current = Current->next;
            }
            return false;
        }
        return false;
    }

    bool FreeMem(int ProgramId) 
    {
        Node<Program>* Curr_Prog = Progs.Head;
        Node<Program>* Prev_Prog = NULL;

        
        while (Curr_Prog != NULL)
        {
            if (Curr_Prog->Data.Id == ProgramId) 
            {
                
                Node<Block>* Curr_Block = Curr_Prog->Data.blocks.Head;

                
                while (Curr_Block != NULL) 
                {
                    
                    Block freeBlock(Curr_Block->Data.Start_Byte_ID, Curr_Block->Data.Tot_Bytes);

                  
                    if (Pool.Head == NULL)
                    {
                        Pool.Head = Pool.Tail = new Node<Block>(freeBlock);
                    }
                    else 
                    {
                        Pool.Tail->next = new Node<Block>(freeBlock);
                        Pool.Tail = Pool.Tail->next;
                    }

                    Node<Block>* toDelete = Curr_Block;
                    Curr_Block = Curr_Block->next;
                    delete toDelete; 
                }

               
                if (Prev_Prog == NULL)
                {
                    Progs.Head = Curr_Prog->next;
                }
                else 
                {
                    Prev_Prog->next = Curr_Prog->next;
                }
                delete Curr_Prog; 
                return true;
            }

            Prev_Prog = Curr_Prog;
            Curr_Prog = Curr_Prog->next;
        }

        
        return false;
    }


    void DisplayMemoryStatus() 
    {
        cout << "Memory Status:" << endl;

        
        Node<Program>* Curr_Prog = Progs.Head;
        while (Curr_Prog != NULL) 
        {
            cout << "Program ID: " << Curr_Prog->Data.Id << endl;
            Node<Block>* Curr_Block = Curr_Prog->Data.blocks.Head;
            while (Curr_Block != NULL)
            {
                cout << "  Allocated Block ID: " << Curr_Block->Data.Start_Byte_ID << " (Size: " << Curr_Block->Data.Tot_Bytes << " bytes)" << endl;
                Curr_Block = Curr_Block->next;
            }
            Curr_Prog = Curr_Prog->next;
        }

       
        Node<Block>* Curr_Block = Pool.Head;
        while (Curr_Block != NULL) 
        {
            cout << " Free Block ID: " << Curr_Block->Data.Start_Byte_ID << " (Size: " << Curr_Block->Data.Tot_Bytes << " bytes)" << endl;
            Curr_Block = Curr_Block->next;
        }
    }


    void DisplayPrograms()
    {
        cout << " Running Programs:" << endl;

        Node<Program>* Curr_Prog = Progs.Head;
        while (Curr_Prog != NULL)
        {
            cout << " Program ID: " << Curr_Prog->Data.Id << " (Size: " << Curr_Prog->Data.Size << " bytes)" << endl;
            Curr_Prog = Curr_Prog->next;
        }
    }
};

int main() 
{
    int memorySize;
    cout << " Enter the total memory size (in bytes): ";
    cin >> memorySize;

    
    MemoryManagementSystem memorySystem(memorySize, true); 

    int choice;
    while (true) 
    {
			
        cout << " Memory Management System Menu:" << endl;
        cout << " 1. Allocate Memory" << endl;
        cout << " 2. Deallocate Memory" << endl;
        cout << " 3. Display Memory Status" << endl;
        cout << " 4. Display Running Programs" << endl;
        cout << " 5. Exit" << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ProgramId, memorySize;
            cout << " Enter Program ID: ";
            cin >> ProgramId;
            cout << " Enter Memory Size (in bytes): ";
            cin >> memorySize;

            if (memorySystem.GetMem(ProgramId, memorySize)) 
            {
                cout << " Memory allocation successful." << endl;
            }
            else
            {
                cout << " Memory allocation failed." << endl;
            }
            break;
        }

        case 2: 
        {
            int ProgramId;
            cout << " Enter Program ID to deallocate memory: ";
            cin >> ProgramId;

            if (memorySystem.FreeMem(ProgramId))
            {
                cout << " Memory deallocation successful." << endl;
            }
            else
            {
                cout << " Program with the given ID not found." << endl;
            }
            break;
        }

        case 3: 
        {
            memorySystem.DisplayMemoryStatus();
            break;
        }

        case 4: 
        {
            memorySystem.DisplayPrograms();
            break;
        }

        case 5:
        {
            cout << " Exiting the Memory Management System." << endl;
            return 0;
        }

        default:
        {
            cout << " Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}




