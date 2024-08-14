#include <Eigen/Dense>

using namespace Eigen;

MatrixXd transform_matrix(const MatrixXd& A, const MatrixXd& T, const MatrixXd& S)
{
    if (T.determinant() == 0 || S.determinant() == 0) {
        throw std::invalid_argument("Matrix T or S are not invertible.");
    }

    return T.inverse() * A * S;
}
