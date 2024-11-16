//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//class Student
//{
//public:
//    string Name;
//    int Roll_No;
//
//    Student(string n, int R)
//    {
//        Name = n;
//        Roll_No = R;
//    }
//};
//void ReadStudentData(vector<Student>& Arr)
//{
//    ifstream inputFile("Data.txt");
//
//    int roll;
//    string name;
//    while (inputFile >> roll) 
//    {
//        inputFile.ignore();
//        getline(inputFile, name);
//        Arr.emplace_back(name, roll);
//    }
//}
//void Sorting(vector<Student>& Arr, float size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = i + 1; j < size; j++)
//        {
//            if (Arr[i].Roll_No > Arr[j].Roll_No)
//            {
//                swap(Arr[i], Arr[j]);
//            }
//        }
//
//    }
//
//}
//
//bool CompareRoll(Student& S1, Student& S2)
//{
//    return S1.Roll_No < S2.Roll_No;
//}
//int ExamRecieve(vector<Student> Arr, float size, int HRoll)
//{
//    for (int i = 0; i < size; i++)
//    {
//        if (Arr[i].Roll_No == HRoll)
//        {
//            return i + 1;
//            break;
//        }
//    }
//    return -1;
//}
//float WaitofHammadtoSub(float size)
//{
//    float waitSize = size * 0.03;
//    waitSize = ceil(waitSize);
//    return waitSize;
//}
//float PlacementOfHammadPap(float size)
//{
//    float PaperPos = size * (0.69);
//    PaperPos = ceil(PaperPos);
//    return PaperPos;
//}
//float MarkPosofHammadPap(float size)
//{
//    float MarkPos = size * 0.69;
//    MarkPos = size - ceil(MarkPos);
//    return MarkPos;
//}
//float ReturningExam(float size)
//{
//    float Wait = size * 0.37;
//    Wait = ceil(Wait);
//    return Wait;
//}
//int main()
//{
//    vector<Student> Arr;
//    ReadStudentData(Arr);
//    float Tot_St = Arr.size();
//    cout << " Total Students in Exam Hall: " << Tot_St << endl;
//    sort(Arr.begin(), Arr.end(), CompareRoll);
//    //////  Sorting(Arr, Tot_St);
//    
//        
//    cout << "1. Hammad received his exam after " << ExamRecieve(Arr, Tot_St, 420) << " students." << endl;
//
//    cout << "2. Hammad had to wait to submit his exam after " << WaitofHammadtoSub(Tot_St) << " students." << endl;
//
//    cout << "3. Hammad's exam was placed in the submission pile at position " << PlacementOfHammadPap(Tot_St) << "." << endl;
//
//    cout << "4. Hammad's exam was marked at position " << MarkPosofHammadPap(Tot_St) << "." << endl;
//
//    cout << "5. Hammad's exam got placed at position " << MarkPosofHammadPap(Tot_St) << " in the marked exams Pile." << endl;
//
//    cout << "6. Hammad received his exam back after " << ReturningExam(Tot_St) << " students." << endl;
//
//    cout << "7. The maximum number of exams Hammad would have been through is " << "." << endl;
//
//    cout << "8. The minimum number of exams Hammad would have been through is 1." << endl;
//
//    return 0;
//}
