#include <iostream>
#include <vector>
#include "rsq_segment_tree.hpp"
using namespace std;


int main(int argc, char* argv[]) {
    vector<int> data = {4, 2, -1, 1, 4, 8, 3};
    
    RSQSegmentTree rsq(data);
    cout << rsq.querySumRange(2, 6);
    return 0;
}