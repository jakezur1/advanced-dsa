#ifndef RSQ_SEGMENT_TREE
#define RSQ_SEGMENT_TREE

#include <cmath>
#include <iostream>
#include <vector>

class RSQSegmentTree {
public:
  RSQSegmentTree(std::vector<int> data);

  int querySumRange(int qL, int qR);

private:
  std::vector<int> tree;
  int treeSize = 0;

  int dataSize = 0;

  int closestPower(int n);

  bool isPower2(int n);

  void build(std::vector<int> &data, int l, int r, int idx);

  int _querySumRange(int qL, int qR, int idx, int l, int r);
};

#endif
