#include "rsq_segment_tree.hpp"

RSQSegmentTree::RSQSegmentTree(std::vector<int> data) {
  dataSize = data.size();
  treeSize =
      isPower2(dataSize) ? 2 * dataSize - 1 : 2 * closestPower(dataSize) - 1;
  tree = std::vector<int>(treeSize, 0);
  build(data, 0, dataSize - 1, 0);
}

int RSQSegmentTree::querySumRange(int qL, int qR) {
  return _querySumRange(qL, qR, 0, 0, dataSize - 1);
}

int RSQSegmentTree::closestPower(int n) { return pow(2, ceil(log2(n))); }

bool RSQSegmentTree::isPower2(int n) { return n > 0 && (n & (n - 1)) == 0; }

void RSQSegmentTree::build(std::vector<int> &data, int l, int r, int idx) {
  if (l == r) {
    tree[idx] = data[l];
    return;
  }
  int leftChildIdx = idx * 2 + 1;
  int rightChildIdx = idx * 2 + 2;

  int m = (r + l) / 2;
  build(data, l, m, leftChildIdx);
  build(data, m + 1, r, rightChildIdx);
  tree[idx] = tree[leftChildIdx] + tree[rightChildIdx];
}

int RSQSegmentTree::_querySumRange(int qL, int qR, int idx, int l, int r) {
  if (qL == l && qR == r) {
    return tree[idx];
  }
  int leftChildIdx = idx * 2 + 1;
  int rightChildIdx = idx * 2 + 2;

  int m = (l + r) / 2;
  if (qL > m) {
    return _querySumRange(qL, qR, rightChildIdx, m + 1, r);
  } else if (qR <= m) {
    return _querySumRange(qL, qR, leftChildIdx, l, m);
  }
  return _querySumRange(qL, m, leftChildIdx, l, m) +
         _querySumRange(m + 1, qR, rightChildIdx, m + 1, r);
}
