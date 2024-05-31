#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

class RMQ {
private:
    vector<int> tree;
    int inputSize;

    void _constructTree(vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            tree[pos] = input[low];
            return;
        }
        int leftChildIdx = pos * 2 + 1;
        int rightChildIdx = pos * 2 + 2;

        int mid = (low + high) / 2;
        _constructTree(input, low, mid, leftChildIdx);
        _constructTree(input, mid + 1, high, rightChildIdx);
        tree[pos] = min(tree[leftChildIdx], tree[rightChildIdx]);
    }

    int _minQueryRange(int qLow, int qHigh, int low, int high, int pos) {
        if (qHigh == high && qLow == low) {
            return tree[pos];
        }
        int leftChildIdx = pos * 2 + 1;
        int rightChildIdx = pos * 2 + 2;

        int mid = (low + high) / 2;
        if (qLow > mid) {
            return _minQueryRange(qLow, qHigh, mid + 1, high, rightChildIdx);
        } else if (qHigh <= mid) {
            return _minQueryRange(qLow, qHigh, qLow, mid, leftChildIdx);
        } else {
            return min(_minQueryRange(qLow, mid, low, mid, leftChildIdx),
                       _minQueryRange(mid + 1, qHigh, mid + 1, high, rightChildIdx));
        }
    }

public:
    RMQ(vector<int>& input) {
        inputSize = input.size();
        int size;
        if (isPowerOfTwo(inputSize)) {
            size = inputSize * 2 - 1;
        } else {
            size = pow(2, ceil(log2(inputSize))) * 2 - 1;
        }
        tree.resize(size, INT_MAX);
        _constructTree(input, 0, input.size() - 1, 0);
    }

    int minQueryRange(int qLow, int qHigh) { return _minQueryRange(qLow, qHigh, 0, inputSize - 1, 0); }
};

int main() {
    vector<int> v { 4, 2, -1, 1, 4, 8, 3 };
    RMQ rmq(v);
    cout << rmq.minQueryRange(1, 4) << endl;
    return 0;
}