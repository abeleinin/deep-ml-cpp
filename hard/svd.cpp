#include "svd.h"

SVD svd_2x2_singular_values(const MatrixXd& A)
{
    MatrixXd A_T_A = A.transpose() * A;

    double theta = 0.5 * atan2(2 * A_T_A(1,0), A_T_A(0,0) - A_T_A(1,1));

    MatrixXd j(2,2);
    j << cos(theta), -sin(theta),
         sin(theta), cos(theta);

    MatrixXd A_prime = j.transpose() * A_T_A * j;

    VectorXd singular_values = A_prime.diagonal().array().sqrt();

    return SVD{j, singular_values, j.transpose()};
}
