#include <vector>
#include <iostream>
#include "square_root_decomp.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> data = {4, 2, -1, 1, 4, 8, 3};

    SquareRootDecomp srd(data);
    cout << srd.querySumRange(1, 6) << endl;
    srd.update(2, -8);
    cout << srd.querySumRange(1, 6) << endl;

    return 0;
}