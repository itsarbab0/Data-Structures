//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//bool ValidParenthesis(string exp)
//{
//	stack<char>s;
//	for (int i = 0; i < exp.length(); i++)
//	{
//		char ch = exp[i];
//		if (ch == '[' || ch == '{' || ch == '(')
//		{
//			s.push(ch);
//		}
//		else
//		{
//			if (!s.empty())
//			{
//				char top = s.top();
//				if (ch==')'&&top=='('|| ch == '}' && top == '{' || ch == ']' && top == '[' )
//				{
//					s.pop();
//				}
//				else
//				{
//					return false;
//				}
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//	if (s.empty())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int main() 
//{
//	string expression;
//
//	cout << "Enter a string with parentheses, square brackets, and curly braces: ";
//	cin >> expression;
//
//	if (ValidParenthesis(expression))
//	{
//		cout << "The entered expression has valid parentheses." << endl;
//	}
//	else 
//	{
//		cout << "The entered expression does not have valid parentheses." << endl;
//	}
//
//	return 0;
//}