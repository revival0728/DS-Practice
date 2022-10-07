#include "Stack.hpp"

#include <stdexcept>

using namespace myc;

// member functions of stack_node
template<class T> Stack<T>::stack_node::stack_node() {}
template<class T> Stack<T>::stack_node::stack_node(stack_node* _next, const T _value) {
    this->next = _next;
    this->value = _value;
}

// member functions of Stack

template<class T> Stack<T>::Stack() {
    this-> root = nullptr;
}

template<class T> void Stack<T>::push(const T _value) {
    this->root = new stack_node(this->root, _value);
}

template<class T> T& Stack<T>::top() {
    if(root == nullptr)
        throw std::runtime_error("myc::Stack<T>: stack is empty");
    return this->root->value;
}

template<class T> void Stack<T>::pop() {
    stack_node *tmp = this->root;
    if(tmp == nullptr)
        throw std::runtime_error("myc::Stack<T>: stack is empty");
    this->root = this->root->next;
    delete tmp;
}

template<class T> std::size_t Stack<T>::size() {
    std::size_t ret = 0;
    stack_node *tmp = this->root;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
        ++ret;
    }
    return ret;
}