#include <Eigen/Dense>

using namespace Eigen;

VectorXd linear_regression_normal_equation(const MatrixXd& X, const VectorXd& y)
{
    // Calculate (X^T X)^-1 X y
    VectorXd theta = (X.transpose() * X).inverse() * X.transpose() * y;
    return theta.array().round();
}
