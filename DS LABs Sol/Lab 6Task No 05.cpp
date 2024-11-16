#include<iostream>
using namespace std;
int Exponent(int Num, int Exp)
{
	if (Exp == 0)
	{
		return 1;
	}
	int Result = Num * Exponent(Num, Exp - 1);
	return Result;
}
int main()
{
	int Num = 0, Exp = 0;
	cout << " Enter the Base: ";
	cin >> Num;
	cout << " Enter the Exponent: ";
	cin >> Exp;
	int Ans = Exponent(Num, Exp);
	cout << Num << " raised to power " << Exp << " is: " << Ans << endl;


	return 0;
}