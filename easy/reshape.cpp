#include <Eigen/Dense>

#include <tuple>

using namespace std;
using namespace Eigen;

MatrixXd reshape(const MatrixXd& a, const tuple<int, int>& new_shape)
{
    int rows = get<0>(new_shape);
    int cols = get<1>(new_shape);

    return a.reshaped<RowMajor>(rows, cols);
}
