#ifndef SRD
#define SRD

#include <vector>
#include <cmath>

using namespace std;


class SquareRootDecomp {
public:
    SquareRootDecomp(vector<int>& data);

    int querySumRange(int l, int r);

    void update(int idx, int val);

private:
    vector<int> data;
    vector<int> decomp;   
    int decompSize = 0;

    int closestSquareRoot(int n) { return pow(ceil(sqrt(data.size())), 2); } 
};

#endif