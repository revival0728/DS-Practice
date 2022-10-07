#include <iostream>
using namespace std;

// include Stack.hpp
#include "Stack.hpp"
#include "Stack.cpp"
using namespace myc;

int main() {
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    cout << stk.size() << '\n';
    stk.pop();
    stk.push(10);
    cout << stk.top() << '\n';
}