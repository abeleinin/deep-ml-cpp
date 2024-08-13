#include <Eigen/Dense>

#include <iostream>
#include <cassert>

using namespace std;
using namespace Eigen;

VectorXd calculate_matrix_mean(const MatrixXd& matrix, string_view mode)
{
    assert(mode == "row" || mode == "column");

    VectorXd res;
    if (mode == "row"){
        res = VectorXd(matrix.rows());
        for (int i = 0; i < matrix.rows(); i++){
            res(i) = matrix.row(i).mean();
        }
    } else { // mode == "column"
        res = VectorXd(matrix.cols());
        for (int i = 0; i < matrix.cols(); i++){
            res(i) = matrix.col(i).mean();
        }
    }

    return res;
}

// int main(void)
// {
//     MatrixXd a(3, 3);
//     a << 1, 2, 3,
//          4, 5, 6,
//          7, 8, 9; 

//     VectorXd expected_row(3);
//     expected_row << 2, 5, 8;

//     VectorXd expected_column(3);
//     expected_column << 4, 5, 6;
    
//     // Test "row" mean
//     VectorXd result_row = calculate_matrix_mean(a, "row");
//     assert(result_row == expected_row);

//     // Test "column" mean
//     VectorXd result_column = calculate_matrix_mean(a, "column");
//     assert(result_column == expected_column);

//     return 0;
// }