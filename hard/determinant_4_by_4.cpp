#include <vector>

using namespace std;

double determinant_3_by_3(const vector<vector<double>>& m)
{
    double minor_00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
    double minor_01 = m[1][0] * m[2][2] - m[1][2] * m[2][0];
    double minor_02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];

    return m[0][0] * minor_00 - m[0][1] * minor_01 + m[0][2] * minor_02;
}

// https://math.emory.edu/~lchen41/teaching/2020_Fall/Section_3-6.pdf
double determinant_4_by_4(const vector<vector<double>>& matrix)
{
    double det = 0.0;
    for (int c = 0; c < 4; c++) {
        vector<vector<double>> minor(3, vector<double>(3));
        for (int i = 1; i < 4; i++) {
            int minor_col = 0;
            for (int j = 0; j < 4; j++) {
                if (j != c) {
                    minor[i - 1][minor_col] = matrix[i][j];
                    minor_col++;
                }
            }
        }
        double cofactor = (c % 2 == 0 ? 1 : -1) * determinant_3_by_3(minor);
        det += matrix[0][c] * cofactor;
    }

    return det;
}