#include <cmath>

using namespace std;

double sigmoid(double x)
{
    // \frac{1}{1 + e^{-x}}
    return 1 / (1 + exp(-x));
}
