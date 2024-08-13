#include "test_easy.h"

#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <cassert>

TEST_CASE("Test accuracy_score") 
{
    vector<double> y_true = {1, 0, 1, 1, 0, 1};
    vector<double> y_pred = {1, 0, 0, 1, 0, 1};

    double expected = 0.8333;

    double result = accuracy_score(y_true, y_pred);

    REQUIRE(abs(expected - result) < 1e-4);
}

TEST_CASE("Test calculate_matrix_mean")
{
    MatrixXd a(3, 3);
    a << 1, 2, 3,
         4, 5, 6,
         7, 8, 9; 

    VectorXd expected_row(3);
    expected_row << 2, 5, 8;

    VectorXd expected_column(3);
    expected_column << 4, 5, 6;
    
    SECTION("Test row mean") {
        VectorXd result_row = calculate_matrix_mean(a, "row");
        REQUIRE(result_row == expected_row);
    }

    SECTION("Test column mean") {
        VectorXd result_column = calculate_matrix_mean(a, "column");
        REQUIRE(result_column == expected_column);
    }
}
