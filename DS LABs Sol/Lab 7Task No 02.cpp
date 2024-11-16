#include<iostream>
#include<stack>
using namespace std;

int Presidence(char ch)
{
	if (ch == '^')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


string Infix2Postfix(string exp)
{
	string Postfix = "";
	stack<char>Obj;
	for (int i = 0; i < exp.length(); i++)
	{
		char ch = exp[i];
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			Postfix += ch;
		}
		else if (ch == '(')
		{
			Obj.push(ch);
		}
		else if (ch == ')')
		{
			while (!Obj.empty() && Obj.top() != '(')
			{
				Postfix += Obj.top();
				Obj.pop();
			}
			Obj.pop();
		}
		else
		{
			while (!Obj.empty() && Presidence(ch) <= Presidence(Obj.top()))
			{
				if (ch == '^' && Presidence(ch) == Presidence(Obj.top()))
				{
					break;
				}
				Postfix + Obj.top();
				Obj.pop();
			}
			Obj.push(ch);
		}
	}
	while (!Obj.empty())
	{
		Postfix += Obj.top();
		Obj.pop();
	}
	return Postfix;
}
int main()
{
	string Exp = "";
	cout << " Enter the Expression: ";
	cin >> Exp;

	string result = Infix2Postfix(Exp);

	cout << " The Infix to Postfix Notation is: " << result << endl;


	return 0;
}