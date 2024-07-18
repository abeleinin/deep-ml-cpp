#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool are_close(double a, double b, double tolerance) {
    return fabs(a - b) < tolerance;
}

#define ASSERT_CLOSE(a, b, tolerance) assert(are_close(a, b, tolerance))

double sigmoid(const double& x)
{
    // \frac{1}{1 + e^{-x}}
    return 1 / (1 + exp(-x));
}

int main(void)
{
    double result;

    // Test 1
    result = sigmoid(0);
    assert(result == 0.5);

    // Test 2
    result = sigmoid(1);
    ASSERT_CLOSE(result, 0.7311, 1e-4);

    // Test 3
    result = sigmoid(-0.25);
    ASSERT_CLOSE(result, 0.4378, 1e-4);
    return 0;
}