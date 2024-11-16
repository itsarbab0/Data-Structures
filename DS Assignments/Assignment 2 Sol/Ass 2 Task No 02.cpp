//#include <iostream>
//#include <string>
//#include <queue>
//#include <iomanip>
//using namespace std;
//
//class Patient
//{
//private:
//    string Name;
//    string Age;
//    string Condition;
//    string Priority;
//
//public:
//    Patient()
//    {
//        this->Name = "";
//        this->Age = "";
//        this->Condition = "";
//        this->Priority = "";
//    }
//
//    Patient(string n, string a, string c)
//    {
//        this->Name = n;
//        this->Age = a;
//        this->Condition = c;
//        if (c == "Critical" || c == "Intense" || stoi(a) >= 51)
//        {
//            Priority = "High";
//        }
//        else {
//            Priority = "Low";
//        }
//    }
//
//    friend ostream& operator<<(ostream& Out, Patient Obj1)
//    {
//        Out << " Name " << setw(10) << " Age " << setw(10) << " Condition " << setw(10) << " Priority " << endl;
//        Out << Obj1.Name << setw(10) << Obj1.Age << setw(10) << Obj1.Condition << setw(10) << Obj1.Priority << endl;
//        return Out;
//    }
//
//    void EnQueue(string n, string a, string c, queue<Patient>& opdQueue, int& count)
//    {
//        queue<Patient> Dup;
//        Patient patientData(n, a, c);
//        if (c == "Critical" || c == "Intense" || patientData.Priority == "High")
//        {
//            if (count <= 10)
//            {
//                if (opdQueue.empty())
//                {
//                    opdQueue.push(patientData);
//                    count++;
//                }
//                else
//                {
//                    while (!opdQueue.empty())
//                    {
//                        Dup.push(opdQueue.front());
//                        opdQueue.pop();
//                    }
//                    opdQueue.push(patientData);
//                    while (!Dup.empty())
//                    {
//                        opdQueue.push(Dup.front());
//                        Dup.pop();
//                    }
//                }
//                count++;
//            }
//            else
//            {
//                cout << "Queue is Full. Please Wait" << endl;
//            }
//        }
//        else
//        {
//            opdQueue.push(patientData);
//            count++;
//        }
//    }
//
//    void Display(queue<Patient>& opdQueue)
//    {
//        if (opdQueue.empty())
//        {
//            cout << "Queue is Empty " << endl;
//        }
//        else
//        {
//            while (!opdQueue.empty())
//            {
//                cout << opdQueue.front();
//                opdQueue.pop();
//            }
//        }
//    }
//
//
//
//
//
//
//};
//
//int main()
//{
//    queue<Patient> opdQueue;
//    int count = 0;
//
//    while (true)
//    {
//        string n, a, c;
//        cout << "Enter the Name, Age, Condition (or type 'exit' to exit): ";
//        cin >> n;
//        if (n == "exit")
//            break;
//        cin >> a >> c;
//
//        Patient patient;
//        patient.EnQueue(n, a, c, opdQueue, count);
//    }
//
//    Patient patient;
//    patient.Display(opdQueue);
//
//    return 0;
//}
