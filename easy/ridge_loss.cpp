#include <Eigen/Dense>

using namespace Eigen;

#include <iostream>

double ridge_loss(const MatrixXd& X, const VectorXd& w, const VectorXd& y_true, double alpha)
{
    double mse = 0.0;
    for (int i = 0; i < w.size(); i++) {
        mse += pow(y_true(i) - (X(i) * w)(i), 2);
    }

    double penalty = 0.0;
    for (auto w_i : w) {
        penalty += pow(w_i, 2);
    }

    // loss 
    return mse + alpha * penalty;
}