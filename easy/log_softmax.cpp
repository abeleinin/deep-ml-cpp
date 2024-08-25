#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void log_softmax(vector<double>& vec)
{
    double max = *max_element(vec.begin(), vec.end());
    int sum = accumulate(vec.begin(), vec.end(), 0);

    double Z = 0.0;
    for (auto& v : vec) {
        v = v - max;
    }
    for (auto& v : vec) {
        Z += exp(v);
    }
    for (auto& v : vec) {
        v = v - log(Z);
    }
}