#include <Eigen/Dense>

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
