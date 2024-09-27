#include "test_hard.h"
#include "test_utils.h"

#include <iostream>

TEST_CASE("Test svd")
{
    MatrixXd A(2,2);
    A << 2, 1,
         1, 2;
    
    SVD result = svd_2x2_singular_values(A);

    MatrixXd U(2,2);
    U << 0.70710678, -0.70710678,
         0.70710678,  0.70710678;
    
    VectorXd Sigma(2);
    Sigma << 3.0, 1.0;

    MatrixXd V_T(2,2);
    V_T << 0.70710678, 0.70710678,
           -0.70710678, 0.70710678;

    REQUIRE_CLOSE(result.U, U, 1e-4);
    REQUIRE_CLOSE(result.Sigma, Sigma, 1e-4);
    REQUIRE_CLOSE(result.V_T, V_T, 1e-4);
}

TEST_CASE("Test 4x4 Determinant")
{
     std::vector<std::vector<double>> matrix;
     double result;

     // Test 1
     matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
     };
     result = determinant_4_by_4(matrix);
     REQUIRE(result == 0);

     // Test 2
     matrix = {
        {6,  1,  1,  3},
        {4, -2,  5,  1},
        {2,  8,  7,  6},
        {3,  1,  9,  7}
     };
     result = determinant_4_by_4(matrix);
     REQUIRE(result == -1309);
}
