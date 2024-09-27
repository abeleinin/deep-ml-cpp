#ifndef TEST_HARD_H
#define TEST_HARD_H

#include "svd.h"

#include <catch2/catch_test_macros.hpp>
#include <Eigen/Dense>

#include <vector>

using namespace std;
using namespace Eigen;

/**
 * 
 */
SVD svd_2x2_singular_values(const MatrixXd& A);

/**
 * 
 */
double determinant_4_by_4(const vector<vector<double>>& matrix);

#endif // TEST_HARD_H