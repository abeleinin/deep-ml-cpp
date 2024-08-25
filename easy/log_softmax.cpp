#include <vector>
#include <cmath>

using namespace std;

void log_softmax(const vector<int>& vec)
{
    double max = *max_element(vec.begin(), vec.end());
    for (auto& v : vec) {
        v = v - max;
    }
}