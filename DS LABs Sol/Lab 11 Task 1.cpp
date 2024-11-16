#include <iostream>
#include <list>
#include <cassert>
#include<string>
using namespace std;
template <class V>
struct HashItem 
{
    int key;
    V value;
    short status;
    list<V> ll;
};

template <class V>
class HashMap 
{
private:
    HashItem<V>* hashArray;
    int capacity;
    int currentElements;

    virtual int getNextCandidateIndex(int key, int i) 
    {
        return (key + i) % capacity;
    }


public:
    HashMap() : capacity(10), currentElements(0) 
    {
        hashArray = new HashItem<V>[capacity]();
    }

    HashMap(int const capacity) : currentElements(0) 
    {
        assert(capacity > 1);
        this->capacity = capacity;
        hashArray = new HashItem<V>[capacity]();
    }

    void insert(int  key, V const value) 
    {
        int index = key % capacity;
        int i = 1;

        while (hashArray[index].status == 2)
        {
            if (hashArray[index].key == key) 
            {
                hashArray[index].value = value;
                return;
            }

            index = (index + getNextCandidateIndex(key, i)) % capacity;
            i++;

            if (i == capacity)
            {
                cerr << "Error: Unable to insert. Hash map is full." << endl;
                return;
            }
        }

        hashArray[index].key = key;
        hashArray[index].value = value;
        hashArray[index].status = 2;
        currentElements++;

        if (static_cast<double>(currentElements) / capacity >= 0.75)
        {
            doubleCapacity();
        }
    }

    void doubleCapacity() 
    {
        int oldCapacity = capacity;
        HashItem<V>* oldArray = hashArray;

        capacity *= 2;
        hashArray = new HashItem<V>[capacity]();

        for (int i = 0; i < oldCapacity; ++i) 
        {
            if (oldArray[i].status == 2) {
                insert(oldArray[i].key, oldArray[i].value);
            }
        }

        delete[] oldArray;
    }


    bool deleteKey(int  key) 
    {
        int index = key % capacity;
        int i = 1;

        while (hashArray[index].status != 0)
        {
            if (hashArray[index].status == 2 && hashArray[index].key == key)
            {
                hashArray[index].status = 1;
                currentElements--;
                return true;
            }

            index = (index + getNextCandidateIndex(key, i)) % capacity;
            i++;

            if (i == capacity) 
            {
                return false;
            }
        }

        return false;
    }

    V* get(int key) 
    {
        int index = key % capacity;
        int i = 1;

        while (hashArray[index].status != 0) 
        {
            if (hashArray[index].status == 2 && hashArray[index].key == key)
            {
                return &hashArray[index].value;
            }

            index = (index + getNextCandidateIndex(key, i)) % capacity;
            i++;

            if (i == capacity)
            {
                return NULL;
            }
        }

        return NULL;
    }


    ~HashMap() 
    {
        delete[] hashArray;
    }
};

int main() 
{
 
    HashMap<string> map;
    map.insert(1, "One");
    map.insert(11, "Eleven");
    map.insert(21, "Twenty-One");

    cout << *map.get(11) << endl; 
    cout << *map.get(21) << endl;
    map.deleteKey(11);

    if (map.get(11) == NULL)
    {
        cout << " Key Not Found" << endl;
    }
    else
    {
        cout << *map.get(11) << endl;
    }
   

    return 0;
}
