/////////------------------------------  TASK 1  -----------------------////////
//
////#include<iostream>
////using namespace std;
////void Bubble_Sort(int Arr[],int size)
////{
////	for (int i = 1; i < size; i++)
////	{
////		for (int j = 0; j < size - 1; j++)
////		{
////			if (Arr[j] > Arr[j + 1])
////			{
////				swap(Arr[j], Arr[j + 1]);
////			}
////		}
////	}
////
////}
////void Print(int arr[],int Size)
////{
////	cout << " The Sorted Array using Bubble Sort is :" << endl;
////	for (int i = 0; i < Size; i++)
////	{
////		cout << " " << arr[i] << ",";
////	}
////	cout << endl;
////}
////int main()
////{
////	const int size = 7;
////	int Array[size] = { 64, 34, 25, 12, 22, 11, 90 };
////	Bubble_Sort(Array, size);
////
////	Print(Array, size);
////
////
////
////	return 0;
////}
//
//////////---------------------------------  TASK 2  --------------------------//////
////
////
////#include<iostream>
////using namespace std;
////void Insertion_Sort(int Arr[],int size)
////{
////	for (int i = 1; i < size; i++)
////	{
////		int temp;
////		temp = Arr[i];
////		int j = i - 1;
////		for ( ;j >= 0; j--)
////		{
////			if (Arr[j] > temp)
////			{
////				Arr[j + 1] = Arr[j];
////			}
////			else
////			{
////				break;
////			}
////		}
////		Arr[j + 1] = temp;
////	}
////
////}
////void Print(int arr[],int Size)
////{
////	cout << " The Sorted Array using Insertion Sort is :" << endl;
////	for (int i = 0; i < Size; i++)
////	{
////		cout << " " << arr[i] << ",";
////	}
////	cout << endl;
////}
////int main()
////{
////	const int size = 7;
////	int Array[size] = { 64, 34, 25, 12, 22, 11, 90 };
////	Insertion_Sort(Array, size);
////
////	Print(Array, size);
////
////
////
////	return 0;
////}
//
//
//
//////////--------------------------------  TASK 3 ------------------------///////
//
////#include<iostream>
////using namespace std;
////void Selection_Sort(int Arr[], int size)
////{
////	for (int i = 0; i < size; i++)
////	{
////		int minIndex = i;
////		for (int j = i + 1; j < size; j++)
////		{
////			if (Arr[j] < Arr[minIndex])
////			{
////				minIndex = j;
////			}
////			
////		}
////		swap(Arr[minIndex], Arr[i]);
////	}
////
////
////}
////
////
////void Print(int arr[], int Size)
////{
////	cout << " The Sorted Array using Selection Sort is :" << endl;
////	for (int i = 0; i < Size; i++)
////	{
////		cout << " " << arr[i] << ",";
////	}
////	cout << endl;
////}
////int main()
////{
////	const int size = 7;
////	int Array[size] = { 64, 34, 25, 12, 22, 11, 90 };
////	Selection_Sort(Array, size);
////
////	Print(Array, size);
////
////
////
////	return 0;
////}
//
///// ------------------------------  TASK 4  ---------------------------------------
//
//
//
#include<iostream>
using namespace std;

void Bubble_Sort(int Arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				swap(Arr[j], Arr[j + 1]);
			}
		}
	}

}

int BinarySearch(int arr[], int size, int Key)
{
	int start = 0, end = size - 1;
	int Mid = (start + end) / 2;
	while (start <= end)
	{
		if (arr[Mid] == Key)
		{
			return Mid;
		}

		if (Key < arr[Mid])
		{
			end = Mid - 1;
		}
		else
		{
			start = Mid + 1;
		}
		Mid = (start + end) / 2;
	}



	return -1;
}

int main()
{
	const int Size = 7;
	int Array[Size] = { 64, 34, 25, 12, 22, 11, 90 };

	Bubble_Sort(Array, Size);
	int Key = 0;
	cout << " Enter the Number You want to search :";
	cin >> Key;

	int Result = BinarySearch(Array, Size, Key);
	cout << " The Number You entered :" << Key << " is on Index " << Result << endl;



	return 0;
}
