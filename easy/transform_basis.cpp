#include <Eigen/Dense>

using namespace Eigen;

Matrix3d transform_basis(const Matrix3d& B, const Matrix3d& C)
{
    return C.inverse() * B;
}
