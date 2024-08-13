#include "test_medium.h"
#include "test_utils.h"

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