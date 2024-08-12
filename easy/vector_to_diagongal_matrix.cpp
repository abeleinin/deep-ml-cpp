#include <Eigen/Dense>

#include <cassert>

using namespace Eigen;

MatrixXd make_diagonal(VectorXd x)
{
    return x.asDiagonal();
}

int main(void) 
{
    VectorXd x(3);
    x << 1, 2, 3;

    MatrixXd res = make_diagonal(x);

    assert(x == res.diagonal());

    return 0;
}