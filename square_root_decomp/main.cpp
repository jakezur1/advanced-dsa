#include "square_root_decomp.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<int> data = {4, 2, -1, 1, 4, 8, 3};

  SquareRootDecomp srd(data);
  std::cout << srd.querySumRange(1, 6) << std::endl;

  srd.update(2, -8);
  std::cout << srd.querySumRange(1, 6) << std::endl;

  return 0;
}
