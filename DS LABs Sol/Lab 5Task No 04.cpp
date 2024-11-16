//#include <iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//
//
//struct Customer 
//{
//    int customer_id;
//    string transaction_type;
//    double amount;
//    double balance;
//};
//
//
//void enqueue_customer(queue<Customer>& customer_queue, Customer customer_data)
//{
//    customer_queue.push(customer_data);
//    cout << "Customer " << customer_data.customer_id << " has joined the queue." << endl;
//}
//
//void teller_serve_customer(queue<Customer>& customer_queue, stack<Customer>& teller_stack) 
//{
//    if (!customer_queue.empty())
//    {
//        Customer customer = customer_queue.front();
//        customer_queue.pop();
//        teller_stack.push(customer);
//
//        cout << "Teller is serving customer " << customer.customer_id << "." << endl;
//        
//        if (customer.transaction_type == "withdrawal") 
//        {
//            customer.balance -= customer.amount;
//            cout << "Withdrawal of $" << customer.amount << " is completed." << endl;
//        }
//        else if (customer.transaction_type == "deposit")
//        {
//            customer.balance += customer.amount;
//            cout << "Deposit of $" << customer.amount << " is completed." << endl;
//        }
//        else if (customer.transaction_type == "check_balance") 
//        {
//            cout << "Customer's balance is $" << customer.balance << "." << endl;
//        }
//    }
//    else
//    {
//        cout << "No customers in the queue." << endl;
//    }
//}
//
//
//void check_balance(queue<Customer>& customer_queue, stack<Customer>& teller_stack, Customer customer_data) 
//{
//    if (!customer_queue.empty()) 
//    {
//        cout << "Teller is checking the balance for customer " << customer_data.customer_id << "." << endl;
//        cout << "Customer's balance is $" << customer_data.balance << "." << endl;
//    }
//    else
//    {
//        cout << "No customers in the queue." << endl;
//    }
//}
//
//
//void get_transaction_history(stack<Customer>& teller_stack)
//{
//    if (!teller_stack.empty())
//    {
//        cout << "Transaction history for the current customer:" << endl;
//        stack<Customer> temp_stack = teller_stack;
//        while (!temp_stack.empty())
//        {
//            Customer customer = temp_stack.top();
//            temp_stack.pop();
//            cout << "Customer " << customer.customer_id << " - " << customer.transaction_type;
//            if (customer.transaction_type != "check_balance") 
//            {
//                cout << " $" << customer.amount;
//            }
//            cout << endl;
//        }
//    }
//    else
//    {
//        cout << "No customer being served at the teller." << endl;
//    }
//}
//
//int main()
//{
//    queue<Customer> customer_queue;
//    stack<Customer> teller_stack;
//
//    
//    Customer customer1 = { 1, "deposit", 100.0, 100.0 };
//    Customer customer2 = { 2, "withdrawal", 50.0, 50.0 };
//    Customer customer3 = { 3, "check_balance", 50.0, 200.0 };
//
//    enqueue_customer(customer_queue, customer1);
//    teller_serve_customer(customer_queue, teller_stack);
//    enqueue_customer(customer_queue, customer2);
//    teller_serve_customer(customer_queue, teller_stack);
//    check_balance(customer_queue, teller_stack, customer3);
//    get_transaction_history(teller_stack);
//
//    return 0;
//}