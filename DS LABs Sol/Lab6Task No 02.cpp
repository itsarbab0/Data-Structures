#include<iostream>
using namespace std;
int EuclideanGCD(int Num1, int Num2)
{
	while (Num2 != 0)
	{
		int temp = Num2;
		Num2 = Num1 % Num2;
		Num1 = temp;
	}
	return Num1;


}
int main()
{
	int Num1 = 0, Num2 = 0;
	cout << " Enter the First Number: ";
	cin >> Num1;
	cout << " Enter the Secode Number: ";
	cin >> Num2;


	int GCD = EuclideanGCD(Num1, Num2);

	cout << " GCD of " << Num1 << " and " << Num2 << " is " << GCD << endl;


	return 0;
}