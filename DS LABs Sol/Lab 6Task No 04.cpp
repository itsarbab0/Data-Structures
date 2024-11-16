#include <iostream>
#include <string>
using namespace std;
void generatesubs(const string& str, string sub, int ind) 
{
    
    if (ind == str.length()) 
    {
        cout << sub << endl;
        return;
    }

  
    generatesubs(str, sub + str[ind], ind + 1);


    generatesubs(str, sub, ind + 1);
}

int main()
{
    string input;

    cout << "enter a string: ";
    cin >> input;

    generatesubs(input, "", 0);

    return 0;
}
