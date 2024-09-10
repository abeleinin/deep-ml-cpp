#include "test_medium.h"
#include "test_utils.h"

#include <iostream>

TEST_CASE("Test calcluate_covariance_matrix")
{
    vector<vector<double>> features, expected, result;
    features = {{1, 2, 3},{4, 5, 6}};
    expected = {{1.0, 1.0}, {1.0, 1.0}};

    result = calculated_covariance_matrix(features);

    REQUIRE(result == expected);
}

TEST_CASE("Test solve_jacobi")
{
    MatrixXd A(3, 3);
    A << 5, -2, 3,
         -3, 9, 1,
         2, -1, -7;

    VectorXd b(3);
    b << -1, 2, 3;

    VectorXd result = solve_jacobi(A, b, 2);

    VectorXd expected(3);
    expected << 0.146, 0.2032, -0.5175;

    REQUIRE_CLOSE(result, expected, 1e-4);
}

TEST_CASE("Test calculate_eigenvalues")
{
    vector<vector<double>> matrix = {{2, 1}, {1, 2}};
    vector<double> expected = {3.0, 1.0};

    vector<double> result = calculate_eigenvalues(matrix); 

    REQUIRE(result == expected);
}

TEST_CASE("Test matrix_transformation")
{
    MatrixXd A(2, 2);
    A << 1, 2,
         3, 4; 

    MatrixXd T(2, 2);
    T << 2, 0,
         0, 2; 

    MatrixXd S(2, 2);
    S << 1, 1,
         0, 1; 
    
    MatrixXd expected(2,2);
    expected << 0.5, 1.5,
                1.5, 3.5;

    MatrixXd result = transform_matrix(A, T, S);

    REQUIRE(result == expected);
}

TEST_CASE("Test 2x2 Matrix Inverse")
{
    vector<vector<double>> matrix = {{4, 7}, {2, 6}};

    auto result = inverse_2x2(matrix);

    vector<vector<double>> expected = {{0.6, -0.7}, {-0.2, 0.4}};

    REQUIRE(result == expected);
}

TEST_CASE("Test matmul")
{
    vector<vector<double>> a = {{1, 2}, {2, 4}};
    vector<vector<double>> b = {{2, 1}, {3, 4}};

    // 2x2 2x2 = 2x2
    auto result = matmul(a, b);

    vector<vector<double>> expected = {{8, 9}, {16, 18}};

    REQUIRE(result == expected);

    b = {{2, 1}, {3, 4}, {4, 5}};

    // 2x2 3x2 = null
    result = matmul(a, b);

    REQUIRE(result == nullopt);
}