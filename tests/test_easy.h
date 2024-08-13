#ifndef TEST_EASY_H
#define TEST_EASY_H

#include <Eigen/Dense>

#include <vector>
#include <cmath>
#include <cassert>

using namespace std;
using namespace Eigen;

bool are_close(double a, double b, double tolerance) {
    return fabs(a - b) < tolerance;
}

#define ASSERT_CLOSE(a, b, tolerance) assert(are_close(a, b, tolerance))

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
std::pair<MatrixXd, MatrixXd> feature_scaling(const MatrixXd& data);

/**
 * 
 */
VectorXd linear_regression_gradient_descent(const MatrixXd& X, 
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
pair<VectorXd, float> single_neuron(const MatrixXd& features, 
                                    const VectorXd& labels,
                                    const VectorXd& weights, 
                                    float bias);

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

#endif // TEST_EASY_H