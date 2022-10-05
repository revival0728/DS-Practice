#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

namespace myc
{
    template<class T> class linked_list {
        private:
            class list_node {
                public:
                    list_node *next;
                    T value;
                    list_node();
                    list_node(list_node*, T);
            } *front;
        public:
            linked_list();
            void insert(const std::size_t, T);
            void erase(const std::size_t);
            T& operator[](const std::size_t);
            std::size_t size();
    };
}

#endif
