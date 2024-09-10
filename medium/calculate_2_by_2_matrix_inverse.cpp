#include <vector>
#include <optional>

using namespace std;

optional<vector<vector<double>>> inverse_2x2(const vector<vector<double>>& matrix)
{
    double a = matrix[0][0];
    double b = matrix[0][1];
    double c = matrix[1][0];
    double d = matrix[1][1];

    double det = a*d-b*c;

    if (det == 0) return nullopt;

    vector<vector<double>> matrix_inv = {
        {d/det, -b/det},
        {-c/det, a/det}
    };

    return matrix_inv;
}