//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class Complex
//{
//private:
//	double Real;
//	double Imag;
//
//public:
//	Complex(double Real, double Imag) : Real(Real), Imag(Imag) {}
//
//	friend ostream& operator<<(ostream& out, const Complex& c)
//	{
//		out << c.Real << " + " << c.Imag << "i";
//		return out;
//	}
//
//	friend istream& operator>>(istream& in, Complex& c)
//	{
//
//		in >> c.Real >> c.Imag ;
//		
//		return in;
//	}
//
//	Complex operator+(const Complex& other) 
//	{
//		return Complex(Real + other.Real, Imag + other.Imag);
//	}
//
//	Complex operator-(const Complex& other) 
//	{
//		return Complex(Real - other.Real, Imag - other.Imag);
//	}
//
//	Complex operator*(const Complex& other) 
//	{
//		double NewReal = Real * other.Real - Imag * other.Imag;
//		double NewImag = Real * other.Imag + Imag * other.Real;
//		return Complex(NewReal, NewImag);
//	}
//
//	Complex operator/(const Complex& other)  
//	{
//		double denominator = other.Real * other.Real + other.Imag * other.Imag;
//		if (denominator == 0.0)
//		{
//			cout << "Division by zero is not allowed." << endl;
//			return Complex(0.0, 0.0);
//		}
//		double NewReal = (Real * other.Real + Imag * other.Imag) / denominator;
//		double NewImag = (Imag * other.Real - Real * other.Imag) / denominator;
//		return Complex(NewReal, NewImag);
//	}
//
//
//	double abs()  
//	{
//		return sqrt(Real * Real + Imag * Imag);
//	}
//
//
//	Complex conjugate() 
//	{
//		return Complex(Real, -Imag);
//	}
//
//	bool equals(const Complex& other) 
//	{
//		return (Real == other.Real && Imag == other.Imag);
//	}
//};
//
//int main()
//{
//	Complex c1(2.0, 3.0);
//	Complex c2(1.0, -2.0);
//
//	cout << "c1: " << c1 << endl;
//	cout << "c2: " << c2 << endl;
//
//	Complex sum = c1 + c2;
//	cout << "Sum: " << sum << endl;
//
//	Complex diff = c1 - c2;
//	cout << "Difference: " << diff << endl;
//
//	Complex product = c1 * c2;
//	cout << "Product: " << product << endl;
//
//	Complex quotient = c1 / c2;
//	cout << "Quotient: " << quotient << endl;
//
//	cout << "Absolute value of c1: " << c1.abs() << endl;
//	cout << "Conjugate of c2: " << c2.conjugate() << endl;
//
//	if (c1.equals(c2))
//	{
//		cout << "c1 and c2 are equal." << endl;
//	}
//	else
//	{
//		cout << "c1 and c2 are not equal." << endl;
//	}
//	system("pause");
//	return 0;
//}







//#include <iostream>
//
//using namespace std;
//class Library
//{
//private:
//	char** titles;
//	char** authors;
//	int* ISBNs;
//	int capacity;
//	int count;
//
//public:
//	Library()
//	{
//		capacity = 10;
//		count = 0;
//		titles = new char*[capacity];
//		authors = new char*[capacity];
//		ISBNs = new int[capacity];
//	}
//
//	Library(int initialCapacity)
//	{
//		capacity = initialCapacity;
//		count = 0;
//		titles = new char*[capacity];
//		authors = new char*[capacity];
//		ISBNs = new int[capacity];
//	}
//
//
//	Library(const Library& other)
//	{
//		capacity = other.capacity;
//		count = other.count;
//		titles = new char*[capacity];
//		authors = new char*[capacity];
//		ISBNs = new int[capacity];
//		for (int i = 0; i < count; ++i)
//		{
//			titles[i] = other.titles[i];
//			authors[i] = other.authors[i];
//			ISBNs[i] = other.ISBNs[i];
//		}
//	}
//
//	~Library()
//	{
//		for (int i = 0; i < count; ++i)
//		{
//			delete(titles[i]);
//			delete(authors[i]);
//		}
//		delete[] titles;
//		delete[] authors;
//		delete[] ISBNs;
//	}
//
//	void addBook(const char* title, const char* author, int ISBN)
//	{
//		if (count == capacity)
//		{
//	
//			capacity *= 2;
//			char** newTitles = new char*[capacity];
//			char** newAuthors = new char*[capacity];
//			int* newISBNs = new int[capacity];
//			for (int i = 0; i < count; ++i)
//			{
//				newTitles[i] = titles[i];
//				newAuthors[i] = authors[i];
//				newISBNs[i] = ISBNs[i];
//			}
//			delete[] titles;
//			delete[] authors;
//			delete[] ISBNs;
//			titles = newTitles;
//			authors = newAuthors;
//			ISBNs = newISBNs;
//		}
//
//
//	}
//
//
//	void removeBook(int ISBN)
//	{
//		for (int i = 0; i < count; ++i)
//		{
//			if (ISBNs[i] == ISBN)
//			{
//				free(titles[i]);
//				free(authors[i]);
//				for (int j = i; j < count - 1; ++j)
//				{
//					titles[j] = titles[j + 1];
//					authors[j] = authors[j + 1];
//					ISBNs[j] = ISBNs[j + 1];
//				}
//				--count;
//				return;
//			}
//		}
//		cout << "Book with ISBN " << ISBN << " not found in the library." << endl;
//	}
//
//	void searchBook(int ISBN)
//	{
//		for (int i = 0; i < count; ++i)
//		{
//			if (ISBNs[i] == ISBN)
//			{
//				cout << "Book found:" << endl;
//				cout << "Title: " << titles[i] << endl;
//				cout << "Author: " << authors[i] << endl;
//				cout << "ISBN: " << ISBNs[i] << endl;
//				return;
//			}
//		}
//		cout << "Book with ISBN " << ISBN << " not found in the library." << endl;
//	}
//
//	void printLibrary()
//	{
//		cout << "Library contents:" << endl;
//		for (int i = 0; i < count; ++i)
//		{
//			cout << "Title: " << titles[i] << endl;
//			cout << "Author: " << authors[i] << endl;
//			cout << "ISBN: " << ISBNs[i] << endl;
//			cout << "-----------------------" << endl;
//		}
//	}
//};
//
//int main()
//{
//
//	Library myLibrary;
//
//	myLibrary.addBook("Book1", "Author1", 123456);
//	myLibrary.addBook("Book2", "Author2", 789012);
//	myLibrary.addBook("Book3", "Author3", 345678);
//
//	myLibrary.printLibrary();
//
//	myLibrary.searchBook(789012);
//
//	myLibrary.removeBook(123456);
//
//	myLibrary.printLibrary();
//	system("pause");
//
//	return 0;
//}