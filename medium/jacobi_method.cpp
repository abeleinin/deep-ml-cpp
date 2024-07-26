#include <Eigen/Dense>

#include <iostream>

using namespace std;
using namespace Eigen;

VectorXd solve_jacobi(const MatrixXd& A, const VectorXd& b, int n)
{
    VectorXd x(b.size());

    MatrixXd d_a = A.diagonal();

    MatrixXd nda = A - d_a;

    for (int iter = 0; iter < n; iter++){
        for (int i = 0; i < x.size(); i++){
                x[i] = (1/d_a[i]) * b(i);
        }
    }

    return x;
}

int main(void)
{
    MatrixXd A(3, 3);
    A << 5, -2, 3,
         -3, 9, 1,
         2, -1, -7;

    VectorXd b(3);
    b << -1, 2, 3;

    VectorXd result = solve_jacobi(A, b, 2);

    std::cout << result << std::endl;

    return 0;
}