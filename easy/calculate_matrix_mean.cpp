#include <Eigen/Dense>

#include <cassert>

using namespace Eigen;

VectorXd calculate_matrix_mean(const MatrixXd& matrix, std::string_view mode)
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
