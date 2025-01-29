#include "segment_tree.cpp"
#include <iostream>
#include <vector>

class Min {
public:
  int operator()(int a, int b) { return a < b ? a : b; }
};

class Sum {
public:
  int operator()(int a, int b) { return a + b; }
};

int main(int argc, char *argv[]) {
  std::vector<int> data = {4, 2, -1, 1, 4, 8, 3};

  SegmentTree<Min> rmq(data);
  std::cout << rmq.queryRange(2, 6) << std::endl;
  rmq.update(3, -5);
  std::cout << rmq.queryRange(2, 6) << std::endl;

  SegmentTree<Sum> rsq(data);
  std::cout << rsq.queryRange(2, 6) << std::endl;
  rsq.update(3, -5);
  std::cout << rsq.queryRange(2, 6) << std::endl;
  return 0;
}
