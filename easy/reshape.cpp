#include <Eigen/Dense>

#include <iostream>
#include <tuple>
#include <cassert>

using namespace std;
using namespace Eigen;

MatrixXd reshape(const MatrixXd& a, const tuple<int, int>& new_shape)
{
    int rows = get<0>(new_shape);
    int cols = get<1>(new_shape);

    return a.reshaped<RowMajor>(rows, cols);
}

int main(void)
{
    // a is in memory using Column-major storage
    MatrixXd a(2, 4);
    a << 1, 2, 3, 4,
         5, 6, 7, 8; 

    MatrixXd expected(4, 2);
    expected << 1, 2, 
                3, 4,
                5, 6,
                7, 8; 
    
    MatrixXd result = reshape(a, make_tuple(4, 2));

    assert(result == expected);

    return 0;
}