#include "heap.h"
using namespace std;
using namespace my_heap;

void heap::_init(vector<int> &vt) {
  this->bucket.resize(vt.size() + 1);
  for (int i = 0; i < vt.size(); ++i) {
    this->bucket[i + 1] = vt[i];
    this->_pull(i);
  }
}

void heap::_push(int id) {
  int lc_id = id << 1, rc_id = id << 1 | 1;
  bool l_or_r = this->bucket[lc_id] >
                this->bucket[rc_id]; // is left child greater than right child
                                     // [0, 1] -> [right, left]
  int target = l_or_r ? lc_id : rc_id;
  if (this->bucket[id] < this->bucket[target]) {
    swap(this->bucket[id], this->bucket[target]);
    this->_push(target);
  }
}

void heap::_pull(int id) {
  int parent = id / 2;
  if (this->bucket[parent] < this->bucket[id]) {
    swap(this->bucket[parent], this->bucket[id]);
    this->_pull(parent);
  }
}

heap::heap() { this->bucket.resize(1); }
heap::heap(vector<int> vt) { this->_init(vt); }

void heap::push(int val) {
  this->bucket.push_back(val);
  this->_pull(this->bucket.size() - 1);
}

void heap::pop() {
  swap(this->bucket[1], this->bucket.back());
  this->bucket.pop_back();
  this->push(1);
}

int heap::top() { return this->bucket[1]; }
