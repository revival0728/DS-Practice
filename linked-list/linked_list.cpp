#include "linked_list.h"
#include <cassert>

using namespace myc;

// list_node member functions
template<class T> linked_list<T>::list_node::list_node() {}
template<class T> linked_list<T>::list_node::list_node(linked_list<T>::list_node *_next, T _val) {
    this->next = _next;
    this->value = _val;
}

// linked_list member functions
template<class T> linked_list<T>::linked_list() {
    this->front = new linked_list<T>::list_node(nullptr, T());
}
template<class T> void linked_list<T>::insert(const std::size_t index, T _val) {
    linked_list<T>::list_node *tmp = this->front, *que = nullptr;
    for(std::size_t i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    assert(tmp != nullptr);
    if(tmp->next == nullptr)
        tmp->next = new linked_list<T>::list_node(nullptr, _val);
    else
        tmp->next = new linked_list<T>::list_node(tmp->next, _val);
}
template<class T> void linked_list<T>::erase(const std::size_t index) {
    linked_list<T>::list_node *tmp = this->front, *erased = this->front;
    for(std::size_t i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    erased = tmp->next;
    tmp->next = erased->next;
    delete erased;
}
template<class T> T& linked_list<T>::operator[](const std::size_t index) {
    linked_list<T>::list_node *tmp = this->front;
    for(std::size_t i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    tmp = tmp->next;
    return (tmp->value);
}
template<class T> std::size_t linked_list<T>::size() {
    linked_list<T>::list_node *tmp = this->front;
    std::size_t ret = 0;
    while(tmp->next != nullptr) {
        ++ret;
        tmp = tmp->next;
    }
    return ret;
}
