#ifndef SEGMENT_TREE
#define SEGMENT_TREE

#include <vector>

template <typename Combine>
class SegmentTree {
public:
  SegmentTree(std::vector<int> data) {
    dataSize = data.size();
    treeSize =
        isPower2(dataSize) ? 2 * dataSize - 1 : 2 * closestPower(dataSize) - 1;
    tree = std::vector<int>(treeSize, INT_MAX);
    build(data, 0, 0, dataSize - 1);
  }

  int queryRange(int qL, int qR) {
    return _queryRange(qL, qR, 0, 0, dataSize - 1);
  }

  void update(int idx, int val) {
    return _update(idx, val, 0, 0, dataSize - 1);
  }

private:
  std::vector<int> tree;

  int treeSize;

  int dataSize;

  Combine combine;

  bool isPower2(int n) { return (n & (n - 1)) == 0; }

  int closestPower(int n) { return pow(2, ceil(log2(n))); }

  void build(std::vector<int> &data, int idx, int l, int r) {
    if (l == r) {
      tree[idx] = data[l];
      return;
    }

    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;

    int m = (r + l) / 2;
    build(data, leftChildIdx, l, m);
    build(data, rightChildIdx, m + 1, r);
    tree[idx] = combine(tree[leftChildIdx], tree[rightChildIdx]);
  }

  int _queryRange(int qL, int qR, int idx, int l, int r) {
    if (qL == l && qR == r)
      return tree[idx];

    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;

    int m = (l + r) / 2;

    if (qL > m)
      return _queryRange(qL, qR, rightChildIdx, m + 1, r);
    else if (qR <= m)
      return _queryRange(qL, qR, leftChildIdx, l, m);
    else
      return combine(_queryRange(qL, m, leftChildIdx, l, m),
                     _queryRange(m + 1, qR, rightChildIdx, m + 1, r));
  }

  void _update(int idx, int val, int currIdx, int l, int r) {
    if (l == r) {
      tree[currIdx] = val;
      return;
    }

    int leftChildIdx = 2 * currIdx + 1;
    int rightChildIdx = 2 * currIdx + 2;

    int m = (l + r) / 2;

    if (idx > m)
      _update(idx, val, rightChildIdx, m + 1, r);
    else
      _update(idx, val, leftChildIdx, l, m);

    tree[currIdx] = combine(tree[leftChildIdx], tree[rightChildIdx]);
  }
};

#endif
