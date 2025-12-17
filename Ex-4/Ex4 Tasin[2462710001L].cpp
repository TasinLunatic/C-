#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAXSTACK = 1000;

struct Stack {
    int data[MAXSTACK];
    int top = -1;  // Initialize top directly
};

bool IsEmpty(const Stack& s) { return s.top == -1; }
bool IsFull(const Stack& s) { return s.top == MAXSTACK - 1; }

bool Push(Stack& s, int x) {
    if (IsFull(s)) return false;
    s.data[++s.top] = x;
    return true;
}

bool Pop(Stack& s, int& x) {
    if (IsEmpty(s)) return false;
    x = s.data[s.top--];
    return true;
}

int EvaluatePostfix(const string& line) {
    Stack s;  // top already -1
    stringstream ss(line);
    string token;

    while (ss >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int b, a;
            if (!Pop(s, b) || !Pop(s, a)) {
                cerr << "ERROR\n";
                exit(1);
            }
            int result;
            char op = token[0];
            if (op == '+') result = a + b;
            else if (op == '-') result = a - b;
            else if (op == '*') result = a * b;
            else {  // '/'
                if (b == 0) {
                    cerr << "ERROR\n";
                    exit(1);
                }
                result = a / b;
            }
            if (!Push(s, result)) {
                cerr << "ERROR\n";
                exit(1);
            }
        } else {
            // Parse as integer
            char* endptr;
            long val = strtol(token.c_str(), &endptr, 10);
            if (*endptr != '\0' || val > INT_MAX || val < INT_MIN) {
                cerr << "ERROR\n";
                exit(1);
            }
            if (!Push(s, static_cast<int>(val))) {
                cerr << "ERROR\n";
                exit(1);
            }
        }
    }

    int result;
    if (!Pop(s, result) || !IsEmpty(s)) {
        cerr << "ERROR\n";
        exit(1);
    }
    return result;
}

int main() {
    string line;
    if (!getline(cin, line)) {
        cerr << "ERROR\n";
        return 1;
    }
    cout << EvaluatePostfix(line) << endl;
    return 0;
}

