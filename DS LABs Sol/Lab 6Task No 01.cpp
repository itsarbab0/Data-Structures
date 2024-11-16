#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	int st_id;
	string st_name;
	float st_gpa;
	node* next;
	node(int id, string n, float gpa)
	{
		this->st_id = id;
		this->st_name = n;
		this->st_gpa = gpa;
		this->next = null;
	}
};

class student
{
public:
	node* head;
	student()
	{
		this->head = null;
	}

	void insertdata(int id, string name, float gpa)
	{
		if (head == null)
		{
			head = new node(id, name, gpa);
		}
		else
		{
			node* current = head;
			while (current->next != null)
			{
				current = current->next;
			}
			current->next = new node(id, name, gpa);
		}
	}
	
	void highgparet(node* current)
	{
		if (current == null)
		{
			return;
		}

		if (current->st_gpa > 3.5)
		{
			cout << "student with high gpa is: " << current->st_name << " with gpa: " << current->st_gpa << endl;
		}

		highgparet(current->next);
	}
	node* deletelowgpa(node* current)
	{
		if (current == null)
		{
			return null;

		}
		if (current->st_gpa < 2.0)
		{
			node* temp = current->next;
			delete current;
			return deletelowgpa(temp);
		}

		else
		{
			current->next = deletelowgpa(current->next);
			return current;
		}


	}


	void display(node* current)
	{
		if (current == null)
		{
			return;
		}
		cout << " student id: " << current->st_id << "\n" << " student name: " << current->st_name << "\n" << " gpa: " << current->st_gpa << endl;

		display(current->next);
	}
};

int main()
{
	student obj;
	obj.insertdata(111, "ibbi", 4);
	obj.insertdata(222, "roshan", 3.9);
	obj.insertdata(333, "chapu daud", 1.9);
	obj.insertdata(444, "multani sir dard", 3.3);

	obj.highgparet(obj.head);
	obj.display(obj.head);

	obj.deletelowgpa(obj.head);
	obj.display(obj.head);

	return 0;
}
