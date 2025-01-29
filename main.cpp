#include <iostream>
using namespace std;

bool checkBrackets(const string& s, size_t& errorPos) {
    char stack[1000]; 
    int top = -1; 

    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ';') break;

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c; 
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) { 
                errorPos = i;
                return false;
            }
            char open = stack[top--]; 
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                errorPos = i;
                return false;
            }
        }
    }
    return top == -1; 
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    size_t errorPos;
    if (checkBrackets(input, errorPos)) {
        cout << "The string is correct.\n";
    }
    else {
        cout << "Error in the string: " << input.substr(0, errorPos + 1) << "\n";
    }

    return 0;
}
