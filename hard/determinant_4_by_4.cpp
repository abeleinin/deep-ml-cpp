#include <vector>

using namespace std;

double determinant_4_by_4(const vector<vector<double>>& matrix)
{
    if (matrix.size() == 1) {
        return matrix[0][0];
    }

    double det = 0;
    for (int c = 0; c < matrix.size(); ++c) {
        vector<vector<double>> minor;
        for (int i = 1; i < matrix.size(); ++i) {
            vector<double> row;
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (j != c) row.push_back(matrix[i][j]);
            }
            minor.push_back(row);
        }

        double cofactor = (pow(-1, c)) * determinant_4_by_4(minor);
        det += matrix[0][c] * cofactor;
    }
    return det;
}