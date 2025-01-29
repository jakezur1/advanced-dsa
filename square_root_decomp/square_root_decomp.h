#ifndef SRD
#define SRD

#include <cmath>
#include <vector>

class SquareRootDecomp {
public:
  SquareRootDecomp(std::vector<int> &data);

  int querySumRange(int l, int r);

  void update(int idx, int val);

private:
  std::vector<int> data;

  std::vector<int> decomp;

  int decompSize = 0;

  int closestSquareRoot(int n) { return pow(ceil(sqrt(data.size())), 2); }
};

#endif
