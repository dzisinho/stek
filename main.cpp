

#include <iostream>
using namespace std;

class CharStack {
private:
    char stack[10];  
    int top;          
    int maxSize;      

public:
    CharStack(int size) {
        maxSize = size;
        top = -1;  
    }

    void push(char c) {
        if (top < maxSize - 1) {
            stack[++top] = c;
        }
        else {
            cout << "Stack is full!" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Stack is empty!" << endl;
        }
    }

    char peek() {
        if (top >= 0) {
            return stack[top];
        }
        else {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
    }

    int size() {
        return top + 1;
    }

    void clear() {
        top = -1;
    }
};

int main() {
    CharStack stack(5);  

    stack.push('X');
    stack.push('Y');
    stack.push('Z');

    cout << "Top character: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;

    stack.pop();
    cout << "After popping, top character: " << stack.peek() << endl;

    stack.clear();
    cout << "Size after clearing: " << stack.size() << endl;

    return 0;
}
