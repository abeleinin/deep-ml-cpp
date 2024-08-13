#include <Eigen/Dense>

#include <cassert>

using namespace Eigen;

MatrixXd make_diagonal(VectorXd x)
{
    return x.asDiagonal();
}
