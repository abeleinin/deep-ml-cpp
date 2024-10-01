#include <Eigen/Dense>

using namespace Eigen;

double linear_kernel(VectorXd a, VectorXd b)
{
    return a.dot(b);
}