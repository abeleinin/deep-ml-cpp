#include <Eigen/Dense>

using namespace Eigen;

double precision(const VectorXd& y_true, const VectorXd& y_pred)
{
    VectorXd true_positives = (y_true.array() == 1).cast<double>() * (y_pred.array() == 1).cast<double>();
    double tp = true_positives.sum();

    VectorXd false_positives = (y_true.array() == 0).cast<double>() * (y_pred.array() == 1).cast<double>();
    double fp = false_positives.sum();

    double denom = tp + fp;
    if (denom > 0) {
        return tp / denom;
    } else {
        return 0.0;
    }
}