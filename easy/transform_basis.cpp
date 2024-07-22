#include <Eigen/Dense>

#include <iostream>

using namespace std;
using namespace Eigen;

Matrix3d transform_basis(const Matrix3d& B, const Matrix3d& C)
{
    return C.inverse() * B;
}

int main(void)
{
    Matrix3d B;
    B << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;
    Matrix3d C;
    C << 1, 2.3, 3,
         4.4, 25, 6,
         7.4, 8, 9;
        
    Matrix3d result =  transform_basis(B, C);

    cout << result << endl; 

    return 0;
}