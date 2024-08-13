#include <Eigen/Dense>

#include <cassert>

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

// int main(void)
// {
//     MatrixXd a(2, 3);
//     a << 1, 2, 3,
//          3, 4, 5;

//     // Test 1
//     MatrixXd result;
//     result = transpose(a);
//     assert(result == a.transpose());

//     MatrixXd b(5, 3);
//     b << 1, 2, 3,
//          4, 5, 6,
//          7, 8, 9,
//          10, 11, 12,
//          13, 14, 15;

//     // Test 2
//     result = transpose(b);
//     assert(result == b.transpose());
//     return 0;
// }