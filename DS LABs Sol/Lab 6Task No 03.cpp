#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int start, int end) 
{
    while (start < end)
    {
        if (s[start] != s[end]) 
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void generatePalindromicPartitions(string s, int start, string currentPartition) 
{
    if (start == s.length())
    {
        cout << currentPartition << endl;
        return;
    }

    for (int end = start; end < s.length(); end++) 
    {
        if (isPalindrome(s, start, end)) 
        {
            string currentPalindromic = s.substr(start, end - start + 1);
            if (start == 0) 
            {
                generatePalindromicPartitions(s, end + 1, currentPalindromic);
            }
            else
            {
                generatePalindromicPartitions(s, end + 1, currentPartition + " | " + currentPalindromic);
            }
        }
    }
}

void printAllPalindromicPartitions(string s)
{
    generatePalindromicPartitions(s, 0, "");
}

int main() 
{
    string input = "aabbaa";

    cout << "All palindromic partitions of '" << input << "':" << endl;
    printAllPalindromicPartitions(input);

    return 0;
}