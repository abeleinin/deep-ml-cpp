#include <Eigen/Dense>

#include <vector>
#include <cassert>

using namespace std;
using namespace Eigen;

void scalar_multiply(vector<vector<double>>& matrix, float scalar)
{
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] *= scalar;
        }
    }
}

MatrixXd scalar_multiply(const MatrixXd& matrix, float scalar)
{
    return matrix * scalar;
}
