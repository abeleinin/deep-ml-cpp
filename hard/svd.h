#ifndef SVD_H
#define SVD_H

#include <Eigen/Dense>

#include <cmath> 

using namespace Eigen;

struct SVD {
    MatrixXd U;
    MatrixXd Sigma;
    MatrixXd V_T;
};

#endif // SVD_H