#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Gender_Sorting {
    stack<char> stackm, stackf;
    queue<char> queueg;
    char** twod;
    int total_counter, row, col, m, f;
    ifstream file_read;

public:
    Gender_Sorting() {
        stackm = stack<char>();
        stackf = stack<char>();
        twod = nullptr;
        total_counter = row = col = m = f = 0;
        file_reading();
    }

    void file_reading() {
        int index = 0;
        file_read.open("People.txt");
        string line = "";

        // Reading Data
        while (getline(file_read, line)) {
            // Totaling Number of Letters
            for (char gender : line) {
                if (gender == 'M' || gender == 'F') {
                    if (gender == 'M') {
                        m++;
                    }
                    else {
                        f++;
                    }
                    total_counter++;
                }
            }
        }
        file_read.close();

        // Initializing Stack with the number of letters as size
        if (m != f) {
            cout << "This cannot be sorted!\n";
            return;
        }

        // Calculating Rows and Columns
        col = 4;
        row = total_counter / col;
        twod = new char* [row + 1];

        // Inserting Letters into Stack
        for (char gender : line) {
            if (gender == 'M') {
                stackm.push(gender);
            }
            else if (gender == 'F') {
                stackf.push(gender);
            }
        }

        // Making 2-D Array with rows and cols
        for (int i = 0; i < row + 1; i++) {
            twod[i] = new char[col];
        }
    }

    void print_twod() {
        cout << "--------------------------------------------------------------------\n";
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                // Note: You need to initialize twod properly before accessing its values
                // Add the logic here based on your requirements
            }
            cout << "|\n--------------------------------------------------------------------\n";
        }
        cout << "Swapped queue track: \n";
        while (!queueg.empty()) {
            cout << queueg.front() << ",";
            queueg.pop();
        }
    }

    void sort() {
        sort(0);
    }

    void sort(int r) {
        if (r == row + 1) {
            return;
        }

        if (r % 2 > 0) {
            for (int i = 0; i < col - 1; i++) {
                if (stackm.empty() && stackf.empty()) {
                    break;
                }
                char letterm = stackm.top();
                char letterf = stackf.top();
                stackm.pop();
                stackf.pop();
                if (i % 2 == 0) {
                    twod[r][i] = letterf;
                    twod[r][i + 1] = letterm;
                }
                else {
                    twod[r][i] = letterm;
                    twod[r][i + 1] = letterf;
                }
                if (queueg.size() < total_counter) {
                    queueg.push(letterf);
                    queueg.push(letterm);
                }

                stackm.push(letterm);
                stackf.push(letterf);
            }
        }
        else {
            for (int i = 0; i < col - 1; i++) {
                if (stackm.empty() && stackf.empty()) {
                    break;
                }
                char letterm = stackm.top();
                char letterf = stackf.top();
                stackm.pop();
                stackf.pop();
                if (i % 2 == 0) {
                    twod[r][i] = letterm;
                    twod[r][i + 1] = letterf;
                }
                else {
                    twod[r][i] = letterf;
                    twod[r][i + 1] = letterm;
                }
                if (queueg.size() < total_counter) {
                    queueg.push(letterf);
                    queueg.push(letterm);
                }
                stackm.push(letterm);
                stackf.push(letterf);
            }
        }

        r++;
        sort(r);
    }
};

int main() {
    Gender_Sorting obj;
    obj.sort();
    obj.print_twod();
    return 0;
}
