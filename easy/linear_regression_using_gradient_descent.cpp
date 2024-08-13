#include <Eigen/Dense>

using namespace Eigen;

VectorXd linear_regression_gradient_descent(
    const MatrixXd& X, 
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
