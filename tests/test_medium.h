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

/**
 * 
 */
vector<double> calculate_eigenvalues(const vector<vector<double>>& matrix);

/**
 * 
 */
MatrixXd transform_matrix(const MatrixXd& A, const MatrixXd& T, const MatrixXd& S);

/**
 * 
 */
optional<vector<vector<double>>> inverse_2x2(const vector<vector<double>>& matrix);

#endif // TEST_MEDIUM_H