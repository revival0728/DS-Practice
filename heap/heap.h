#ifndef HEAP_H
#define HEAP_H

#include <vector>

namespace my_heap {

class heap {
private:
  std::vector<int> bucket;

protected:
  void _init(std::vector<int> &);
  void _push(int);
  void _pull(int);

public:
  heap();
  heap(std::vector<int>);
  void push(int);
  void pop();
  int top();
};

} // namespace my_heap

#endif
