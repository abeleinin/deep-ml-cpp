#include <vector>
#include <cmath>

using namespace std;

vector<double> calculate_eigenvalues(const vector<vector<double>>& matrix)
{
    double a = matrix[0][0];
    double b = matrix[0][1];
    double c = matrix[1][0];
    double d = matrix[1][1];
    
    double trace = a + d;
    double det = a * d - b * c;

    double discriminant = pow(trace, 2) - 4*det;

    double lambda1 = (trace + sqrt(discriminant)) / 2;
    double lambda2 = (trace - sqrt(discriminant)) / 2;
    return {lambda1, lambda2};
}
