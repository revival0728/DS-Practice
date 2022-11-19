#include "heap.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> test_data = {{1, 2, 3, 4, 5},
                                 {5, 2, 3, 5, 6, 6, 10, 3, 2},
                                 {0, 2, 5, 7, 4, 2, 2, 1, 1, 4, 5, 6}};

vector<vector<int>> test_answer(test_data.begin(), test_data.end());

vector<array<vector<int>, 2>> test_log(test_data.size());

int tester(int test_case,
           array<bool, 2> skip) { // [0, 1, 2] -> [accept, wrong answer with
  // initializer, wrong answer with push function]
  if (!skip[0]) {
    cout << "here" << '\n';
    my_heap::heap hp_1(test_data[test_case]);
    vector<int> ans_1(test_data[test_case].size());
    for (auto &i : ans_1) {
      i = hp_1.top();
      hp_1.pop();
    }
    test_log[test_case][0] = ans_1;
    if (ans_1 != test_answer[test_case])
      return 1;
  }
  if (!skip[1]) {
    my_heap::heap hp_2;
    vector<int> ans_2(test_data[test_case].size());
    for (auto &i : test_data[test_case]) {
      hp_2.push(i);
    }
    for (auto &i : ans_2) {
      i = hp_2.top();
      hp_2.pop();
    }
    test_log[test_case][1] = ans_2;
    if (ans_2 != test_answer[test_case])
      return 2;
  }
  return 0;
}

void print_test_log(int test_case, int test_unit) {
  cout << "\n - test_data: ";
  for (auto &i : test_data[test_case]) {
    cout << i << ' ';
  }
  cout << "\n - test_answer: ";
  for (auto &i : test_answer[test_case]) {
    cout << i << ' ';
  }
  cout << "\n - test_log: ";
  for (auto &i : test_log[test_case][test_unit]) {
    cout << i << ' ';
  }
}

int main() {
  for (auto &vt : test_answer) {
    sort(vt.begin(), vt.end(), greater<int>());
  }
  for (int i = 0; i < test_data.size(); ++i) {
    bool test_result = tester(i, {1, 0});
    cout << "Case #" << i + 1 << ": ";
    if (test_result == 0) {
      cout << "Accept";
      print_test_log(i, 0);
    } else if (test_result == 1) {
      cout << "Wrong Answer with initializer";
      print_test_log(i, 0);
    } else if (test_result == 2) {
      cout << "Wrong Answer with push function";
      print_test_log(i, 1);
    } else {
      cout << "Test Error";
    }
    cout << '\n';
  }
}
