#include <Eigen/Dense>

using namespace Eigen;

MatrixXd transpose(const MatrixXd& x)
{
    int m = x.rows();
    int n = x.cols();
    MatrixXd transpose(n,m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            transpose(i,j) = x(j,i);
        }
    }
    return transpose;
}
