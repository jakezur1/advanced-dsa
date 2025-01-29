#include "rsq_segment_tree.hpp"

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> data = {4, 2, -1, 1, 4, 8, 3};

  RSQSegmentTree rsq(data);
  std::cout << rsq.querySumRange(2, 6);
  return 0;
}
