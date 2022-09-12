#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <vector>
#include "slicer.h"

using namespace std;

class Slicer
{
public:
    int start, end, step;
    auto operator[::](int start, int end, int step) noexcept {
        vector<int> vec;
        for(int i = start; i != end; i += step)
            vec.push_back(i);
        return vec;
    }

};
};

int main() {
    Slicer vec;
    //... filling vec;
    for(auto i : vec[1:10:2])
        cout << i << endl;
    return EXIT_SUCCESS;
}
