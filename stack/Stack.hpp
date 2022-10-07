#ifndef STACK_H
#define STACK_H

#include <cstddef>

namespace myc
{
    template<class T> class Stack {
        private:
            class stack_node {
                public:
                    T value;
                    stack_node *next;
                    stack_node();
                    stack_node(stack_node*, const T);
            } *root;
        public:
            Stack();
            void push(const T);
            T& top();
            void pop();
            std::size_t size();
    };
}

#endif