#include <iostream>
using namespace std;

/*FOR SKILLS*/
struct skill_node 
{
	int level;
	string name;
	skill_node* left, * right;
	skill_node(string name, int level) 
	{
		this->name = name;
		this->level = level;
		left = right = nullptr;
	}
};
class skill_tree 
{
public:
	skill_node* root;
	skill_tree()
	{
		root = nullptr;
	}
	skill_node* insert(skill_node* current, int level = 3) 
	{
		if (current == nullptr)
		{
			string skill_name = "";
			cout << "Enter skill: ";
			cin >> skill_name;
			return new skill_node(skill_name, level);
		}
		else if (current->level >= level) 
		{
			current->left = insert(current->left, level);
		}
		else if (current->level <= level) 
		{
			current->right = insert(current->right, level);
		}
		return current;
	}
	int insert() 
	{
		int level = 0;
		cout << "\nEnter level: "; cin >> level;
		if (level == -1)
		{ 
			/*To Stop entering skills of a specific name*/
			return level;
		}
		root = insert(root, level);
		return level;
	}
};

/*For Resource Tree*/
struct resource_node
{
	int id;
	string name;
	skill_tree* leaf;
	resource_node* left, * right;
	resource_node(string name, int id) 
	{
		left = right = nullptr;
		leaf = new skill_tree;
		int integer = 0;
		this->name = name;
		this->id = id;
		cout << "*************Enter " << name << " skills***********\n";
		while (integer != -1)
		{
			/*Enter skills until -1*/
			integer = leaf->insert(); /*Checking if the level is -1 or not*/
		}
	}
};
class resource_tree
{
public:
	resource_node* root;

	resource_tree() 
	{
		root = nullptr;
	}

	resource_node* insert(resource_node* current, string name, int id) {
		if (current == nullptr) 
		{
			return new resource_node(name, id);
		}
		else if (current->id >= id)
		{
			current->left = insert(current->left, name, id);
		}
		else if (current->id <= id) 
		{
			current->right = insert(current->right, name, id);
		}
		return current;
	}
	void insert(string name, int id)
	{
		root = insert(root, name, id);
	}
};

/*For Task_Tree*/
struct task_node
{
	string name;
	int task_no;
	skill_tree* leaf;
	task_node* left, * right;
	task_node(string name, int task_no)
	{
		int integer = 0;
		leaf = new skill_tree;
		this->name = name;
		this->task_no = task_no;
		cout << "*************" << name << " Skill_set***********\n";
		while (integer != -1) 
		{
			/*Enter skills until -1*/
			integer = leaf->insert(); /*Checking if the level is -1 or not*/
		}
	}
};
class task_tree 
{
public:
	task_node* root;
	task_tree() 
	{
		root = nullptr;
	}
	task_node* insert(task_node* current, string name, int taskno)
	{
		if (current == nullptr) 
		{
			return new task_node(name, taskno);
		}
		else if (current->task_no >= taskno)
		{
			current->left = insert(current->left, name, taskno);
		}
		else if (current->task_no <= taskno) 
		{
			current->right = insert(current->right, name, taskno);
		}
		return current;
	}
	void insert(string name, int task_no) 
	{
		root = insert(root, name, task_no);
	}
};

/*For Allocation_Tree*/
struct allo_node {
	resource_node* leaf;
	allo_node* left, * right;
	allo_node(resource_node* ptr) 
	{
		left = right = nullptr;
		leaf = ptr;
	}
};

class allocation_tree 
{
public:
	allo_node* root;
	resource_tree* resource;
	task_tree* task;
	task_node* troot;
	resource_node* r_root;
	bool main_bool;
	allocation_tree(resource_tree* r_obj, task_tree* task_obj)
	{
		root = nullptr;
		resource = r_obj;
		task = task_obj;
		troot = task->root;
		r_root = resource->root;
		main_bool = false;
	}

	void Exact_Match(resource_node* rcurrent, task_node* tcurrent) 
	{
		if (rcurrent == nullptr) 
		{
			return;
		}

		skill_node* r_temp = rcurrent->leaf->root;
		skill_node* t_temp = tcurrent->leaf->root;
		Check_Match(r_temp, t_temp);
		if (main_bool) 
		{
			cout << "Not Correct";
		}
		else 
		{
			cout << "Correct";
		}
		Exact_Match(rcurrent->left, tcurrent);
		Exact_Match(rcurrent->right, tcurrent);
	}
	void Check_Match(skill_node* r_current, skill_node* t_current, bool found = true)
	{
		if (r_current == nullptr || found == false) 
		{
			return;
		}
		bool mini_bool = false;
		mini_bool = Mini_Check(r_current, t_current);
		if (mini_bool == false)
		{
			found = false;
			main_bool = true;
		}
		Check_Match(r_current->left, t_current, found);
		Check_Match(r_current->right, t_current, found);
		return;
	}
	bool Mini_Check(skill_node* r_current, skill_node* t_current, bool found = false)
	{
		if (t_current == nullptr) 
		{
			return found;
		}
		else if ((r_current->name == t_current->name) && (r_current->level == t_current->level))
		{
			return true;
		}
		found = Mini_Check(r_current, t_current->left, found);
		found = Mini_Check(r_current, t_current->right, found);
		return found;
	}


	void Skill_Only(resource_node* rcurrent, task_node* tcurrent)
	{
		if (rcurrent == nullptr) 
		{
			return;
		}

		skill_node* r_temp = rcurrent->leaf->root;
		skill_node* t_temp = tcurrent->leaf->root;
		int total_sum = Sum_Skill(r_temp);

	}
	int Sum_Skill(skill_node* current, int sum = 0) 
	{
		if (current == nullptr) 
		{
			return sum;
		}
		sum += current->level;
		sum = Sum_Skill(current->left, sum);
		sum = Sum_Skill(current->right, sum);
		return sum;
	}

};




int main()
{
	resource_tree* resource_obj = new resource_tree;
	task_tree* task_obj = new task_tree;
	string task_name;
	string r_arr[5] = { "Shafiq","Ahmed","Shehzad","Arbab","James" };
	cout << "*******Setup Resource Tree**********\n";
	for (int i = 0; i < 1; i++)
	{
		resource_obj->insert(r_arr[i], i);
	}
	cout << "***************************************\nEnter a Task: "; 
	cin >> task_name;
	task_obj->insert(task_name, 1);
	allocation_tree allo_obj(resource_obj, task_obj);
	allo_obj.Skill_Only(resource_obj->root, task_obj->root);

	return 0;
}

