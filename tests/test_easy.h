#ifndef TEST_EASY_H
#define TEST_EASY_H

#include <catch2/catch_test_macros.hpp>

#include <Eigen/Dense>

#include <vector>

using namespace std;
using namespace Eigen;

/**
 * 
 */
double accuracy_score(const vector<double>& y_true, const vector<double>& y_pred);

/**
 * 
 */
VectorXd calculate_matrix_mean(const MatrixXd& matrix, string_view mode);

/**
 * 
 */
pair<MatrixXd, MatrixXd> feature_scaling(const MatrixXd& data);

/**
 * 
 */
VectorXd linear_regression_gradient_descent(
    const MatrixXd& X, 
    const VectorXd& y,
    const float& alpha,
    const int& iterations);

/**
 * 
 */
VectorXd linear_regression_normal_equation(const MatrixXd& X, const VectorXd& y);

/**
 * 
 */
vector<float> matrix_dot_vector(const vector<vector<float> >& m, const vector<float>& v);

/**
 * 
 */
MatrixXd reshape(const MatrixXd& a, const tuple<int, int>& new_shape);

/**
 * 
 */
void softmax(vector<double>& z);

/**
 * 
 */
double sigmoid(double x);

/**
 * 
 */
void scalar_multiply(vector<vector<double>>& matrix, float scalar);
MatrixXd scalar_multiply(const MatrixXd& matrix, float scalar);

/**
 * 
 */
pair<VectorXd, double> single_neuron(
    const MatrixXd& features, 
    const VectorXd& labels,
    const VectorXd& weights, 
    double bias);

/**
 * 
 */
Matrix3d transform_basis(const Matrix3d& B, const Matrix3d& C);

/**
 * 
 */
MatrixXd transpose(const MatrixXd& x);

/**
 * 
 */
MatrixXd make_diagonal(VectorXd x);

/**
 * 
 */
void log_softmax(vector<double>& vec);

/**
 * 
 */
double relu(const double& z);

/**
 * 
 */
double ridge_loss(const MatrixXd& X, const VectorXd& w, const VectorXd& y_true, double alpha);

#endif // TEST_EASY_H