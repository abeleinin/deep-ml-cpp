#include <Eigen/Dense>

#include <iostream>

using namespace std;
using namespace Eigen;

VectorXd solve_jacobi(const MatrixXd& A, const VectorXd& b, int n)
{
    int size = A.rows();
    VectorXd x = VectorXd::Zero(size);
    VectorXd x_new = VectorXd::Zero(size);

    for (int iter = 0; iter < n; iter++){
        for (int i = 0; i < size; i++){
            double sum = 0.0;
            for (int j = 0; j < size; j++){
                if (i != j){
                    sum += A(i, j) * x(j);
                }
            }
            x_new(i) = (b(i) - sum) / A(i, i);
        }
        x = x_new;
    }

    return x_new;
}

// int main(void)
// {
//     MatrixXd A(3, 3);
//     A << 5, -2, 3,
//          -3, 9, 1,
//          2, -1, -7;

//     VectorXd b(3);
//     b << -1, 2, 3;

//     VectorXd result = solve_jacobi(A, b, 2);

//     std::cout << result << std::endl;

//     return 0;
// }