

#include <iostream>
using namespace std;

class CharStack {
private:
    char* stack;   
    int top;          
    int capacity;     

    void resize() {
        int newCapacity = capacity * 2;  
        char* newStack = new char[newCapacity];

        for (int i = 0; i <= top; i++) {
            newStack[i] = stack[i];
        }

        delete[] stack;   
        stack = newStack; 
        capacity = newCapacity;

        cout << "Stack resized to " << capacity << " elements." << endl;
    }

public:
    CharStack(int initialSize) {
        capacity = initialSize;
        stack = new char[capacity];
        top = -1;  
    }

    ~CharStack() {
        delete[] stack;
    }

    void push(char c) {
        if (top + 1 == capacity) {
            resize();  
        }
        stack[++top] = c;
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

    int size() const {
        return top + 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void clear() {
        top = -1;
    }
};

int main() {
    CharStack stack(3);  

    stack.push('A');
    stack.push('B');
    stack.push('C');

    cout << "Top character: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;

    stack.push('D');  
    stack.push('E');

    cout << "Top character after resizing: " << stack.peek() << endl;
    cout << "Stack size after resizing: " << stack.size() << endl;

    stack.pop();
    cout << "Top character after popping: " << stack.peek() << endl;

    return 0;
}
