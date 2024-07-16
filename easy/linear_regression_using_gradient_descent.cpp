#include <Eigen/Dense>

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;
using namespace Eigen;

VectorXd linear_regression(const MatrixXd& X, 
                           const VectorXd& y,
                           const float& alpha,
                           const int& iterations)
{
    int m = X.rows();
    int n = X.cols();
    MatrixXd theta = VectorXd::Zero(n);
    for (int i = 0; i < iterations; i++){
        // (m, n) @ (n, 1) -> (m, 1)
        MatrixXd pred = X * theta;

        // (m) -> (m, 1)
        MatrixXd y_reshape = y.reshaped(y.size(), 1);

        MatrixXd errors = pred - y_reshape;        

        MatrixXd updates = X.transpose() * errors / m;

        theta -= alpha * updates;
    }
    VectorXd theta_flattened = Map<const VectorXd>(theta.data(), theta.size());
    return theta_flattened;
}

int main(void)
{
    MatrixXd X(3, 2);
    X << 1, 1,
         1, 2,
         1, 3;

    VectorXd y(3);
    y << 1, 2, 3;

    VectorXd expected(2);
    expected << 0.110715, 0.951296;

    VectorXd result = linear_regression(X, y, 0.01, 1000);
    cout << result << endl;
    cout << expected << endl;
    return 0;
}