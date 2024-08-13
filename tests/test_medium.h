#ifndef TEST_MEDIUM_H
#define TEST_MEDIUM_H

#include <catch2/catch_test_macros.hpp>

#include <Eigen/Dense>

#include <vector>

using namespace std;
using namespace Eigen;

/**
 * 
 */
vector<vector<double>> calculated_covariance_matrix(const vector<vector<double>>& vectors);

/**
 * 
 */
VectorXd solve_jacobi(const MatrixXd& A, const VectorXd& b, int n);

#endif // TEST_MEDIUM_H