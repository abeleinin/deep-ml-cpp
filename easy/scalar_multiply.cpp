#include <Eigen/Dense>

#include <vector>
#include <cassert>

using namespace std;
using namespace Eigen;

// vector implementation
void scalar_multiply(vector<vector<double>>& matrix, float scalar)
{
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] *= scalar;
        }
    }
}

// Eigen implementation
MatrixXd scalar_multiply(const MatrixXd& matrix, float scalar)
{
    return matrix * scalar;
}

int main(void)
{
    // Test vector
    vector<vector<double>> b, expected_vec;

    b = {{1.0, 2.0}, {3.0, 4.0}};
    expected_vec = {{2.0, 4.0}, {6.0, 8.0}};

    scalar_multiply(b, 2);

    assert(b == expected_vec);

    // Test eigen
    MatrixXd a(2, 2);
    a << 1, 2,
         3, 4;

    MatrixXd expected(2, 2);
    expected << 2, 4,
                6, 8;
    
    MatrixXd result = scalar_multiply(a, 2);

    assert(result == expected);

    return 0;
}