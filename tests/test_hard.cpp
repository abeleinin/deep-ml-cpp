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
