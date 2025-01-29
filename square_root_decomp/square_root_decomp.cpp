#include "square_root_decomp.hpp"
#include <vector>

SquareRootDecomp::SquareRootDecomp(std::vector<int> &_data) {
  data = _data;

  decompSize = ceil(sqrt(data.size()));

  decomp = std::vector<int>(decompSize, 0);

  int currSum = 0;
  int blockIdx = -1;

  for (int i = 0; i < data.size(); i++) {
    if (!(i % decompSize))
      blockIdx++;

    decomp[blockIdx] += data[i];
  }
}

int SquareRootDecomp::querySumRange(int l, int r) {
  int sum = 0;
  while (l < r && l % decompSize)
    sum += data[l++];

  while (l < r && !(l % decompSize)) {
    sum += decomp[l / decompSize];
    l += decompSize;
  }

  while (l <= r)
    sum += data[l++];
  return sum;
}

void SquareRootDecomp::update(int idx, int val) {
  decomp[idx / decompSize] += val - data[idx];
  data[idx] = val;
}
