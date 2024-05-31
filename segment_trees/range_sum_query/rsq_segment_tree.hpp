#ifndef RSQ_SEGMENT_TREE
#define RSQ_SEGMENT_TREE

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class RSQSegmentTree {
public:
    RSQSegmentTree (vector<int> data);

    int querySumRange(int qL, int qR);


private:
    vector<int> tree;
    int treeSize = 0;

    int dataSize = 0;


    int closestPower(int n);

    bool isPower2(int n);
    
    void build(vector<int>& data, int l, int r, int idx);
    
    int _querySumRange(int qL, int qR, int idx,  int l, int r);
};

#endif