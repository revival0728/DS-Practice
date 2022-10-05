#include <iostream>
#include "linked_list.h"
using namespace std;
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

int main() {
	linked_list<Student> lst;
	lst.insert(0, Student());
}
