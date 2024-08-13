#include <Eigen/Dense>

#include <iostream>

using namespace std;
using namespace Eigen;

std::pair<MatrixXd, MatrixXd> feature_scaling(const MatrixXd& data)
{
    VectorXd mean = data.colwise().mean();

    MatrixXd d = data.rowwise() - mean.transpose();
    MatrixXd sqr = d.array().square();
    VectorXd var = sqr.colwise().mean();
    VectorXd std = var.array().sqrt();

    MatrixXd standardized = d.array().rowwise() / std.transpose().array();

    VectorXd min_val = data.colwise().minCoeff();
    VectorXd max_val = data.colwise().maxCoeff();
    MatrixXd normal = (data.rowwise() - min_val.transpose()).array().rowwise() / (max_val - min_val).transpose().array();

    return {standardized, normal};
}

// int main() {
//     MatrixXd data(3, 2);
//     data << 1, 2,
//             3, 4,
//             5, 6;

//     auto result = feature_scaling(data);

//     cout << result.first << endl;
//     cout << result.second << endl;

//     return 0;
// }