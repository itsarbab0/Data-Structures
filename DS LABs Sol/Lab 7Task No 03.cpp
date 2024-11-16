//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main() 
//{
//    stack<string> backStack;    
//    stack<string> forwardStack; 
//    string current_page = "Homepage"; 
//
//    while (true) 
//    {
//        
//        cout << "Current Page: " << current_page << endl;
//        cout << "Options: " << endl;
//        cout << "1. Visit a New Page " << endl;
//        cout << "2. Go Back " << endl;
//        cout << "3. Go Forward " << endl;
//        cout << "4. Quit " << endl;
//        cout << "Enter your choice: ";
//
//        int choice;
//        cin >> choice;
//
//        switch (choice) 
//        {
//        case 1: 
//        {
//            string new_page;
//            cout << "Enter the URL of the new page: ";
//            cin >> new_page;
//       
//            backStack.push(current_page);
//            current_page = new_page;
//        }
//        break;
//
//        case 2: 
//            if (!backStack.empty())
//            {
//                
//                forwardStack.push(current_page);
//
//                current_page = backStack.top();
//                backStack.pop();
//            }
//            break;
//
//        case 3: 
//            if (!forwardStack.empty()) 
//            {
//
//                backStack.push(current_page);
//
//                current_page = forwardStack.top();
//                forwardStack.pop();
//            }
//            break;
//
//        case 4: 
//            return 0;
//
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    }
//
//    return 0;
//}
