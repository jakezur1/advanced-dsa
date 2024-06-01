#include <iostream>
#include <vector>
#include "segment_tree.cpp"

using namespace std;


class Min {
public:
    Min () {}
    int operator()(int a, int b) {
        return a < b ? a : b;
    }
};

class Sum {
public:
    Sum () {}
    int operator()(int a, int b) {
        return a + b;
    }
};

int main(int argc, char* argv[]) {
    vector<int> data = {4, 2, -1, 1, 4, 8, 3};

    SegmentTree<Min> rmq(data);
    cout << rmq.queryRange(2, 6) << endl;
    rmq.update(3, -5);
    cout << rmq.queryRange(2, 6) << endl;

    SegmentTree<Sum> rsq(data);
    cout << rsq.queryRange(2, 6) << endl;
    rsq.update(3, -5);
    cout << rsq.queryRange(2, 6) << endl;
    return 0;
}