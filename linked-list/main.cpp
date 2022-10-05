#include <iostream>
using namespace std;

// include linked_list
#include "linked_list.h"
#include "linked_list.cpp"
using namespace myc;

struct Student {
    unsigned int number, score;
    string name;
    Student() {}
    Student(unsigned int _number, string _name, unsigned int _score) {
        number = _number;
        name = _name;
        score = _score;
    }
};

const int case_number = 3;
const unsigned int scores[case_number] = {
    90,
    80,
    40
};
const string names[case_number] = {
    "mark",
    "revival",
    "hank"
};

int main() {
    linked_list<Student> lst;
    for(int i = 0; i < case_number; ++i) {
        lst.insert(i, Student(i+1, names[i], scores[i]));
    }
    lst.erase(1);
    const size_t lst_size = lst.size();
    cout << lst_size << '\n';
    for(int i = 0; i < lst_size; ++i) {
        cout << lst[i].number << ' ' << lst[i].name << ' ' << lst[i].score << '\n';
    }
}
