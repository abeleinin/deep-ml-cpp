#include <vector>
#include <Eigen/Dense>
#include <cassert>

using namespace Eigen;
using namespace std;

VectorXd linear_regression(const MatrixXd& X, const VectorXd& y)
{
    // Calculate (X^T X)^-1 X y
    VectorXd theta = (X.transpose() * X).inverse() * X.transpose() * y;
    return theta.array().round();
}

int main(void)
{
    MatrixXd X(3, 2);
    X << 1, 1,
         1, 2,
         1, 3;

    VectorXd y(3);
    y << 1, 2, 3;

    VectorXd expect(2);
    expect << 0.0, 1.0;

    // Test 1
    VectorXd result = linear_regression(X, y);
    assert(result == expect);

    return 0;
}