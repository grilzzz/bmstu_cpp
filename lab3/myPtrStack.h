#include <vector>


template <typename T>
class Stack {
private:
    std::vector<T> stack;


public : 
    void append(T x);
    T pop();
    int length();
};


template <typename T>
void Stack<T>::append(T x) {
    this->stack.push_back(x);
}

template <typename T>
T Stack<T>::pop() {
    int x;
    x = this->stack[this->stack.size()-1];
    this->stack.pop_back();
    return x;
}

template <typename T>
int Stack<T>::length() {
    return this->stack.size();
}