#include <Eigen/Dense>

using namespace Eigen;

double ridge_loss(const MatrixXd& X, const VectorXd& w, const VectorXd& y_true, double alpha)
{
    double mse = (y_true - (X * w)).array().square().mean();
    double sqr_coef = w.array().square().sum();

    // loss: mse + pentaly 
    return mse + alpha * sqr_coef;
}