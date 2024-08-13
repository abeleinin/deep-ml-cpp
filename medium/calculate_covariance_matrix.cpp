#include <vector>
#include <cassert>
#include <numeric>
#include <cmath>
#include <iostream>

using namespace std;

vector<vector<double>> calculated_covariance_matrix(const vector<vector<double>>& vectors)
{
    int n_features = vectors.size();
    int n_observations = vectors[0].size();
    vector<vector<double>> cov_matrix(n_features, vector<double>(n_features, 0.0));

    vector<double> means;
    for (int i = 0; i < n_features; i++){
        means.push_back(accumulate(vectors[i].begin(), vectors[i].end(), 0.0)/vectors[i].size());
    }

    for (int i = 0; i < n_features; i++){
        for (int j = i; j < n_features; j++){
            double numerator = 0.0;
            for (int k = 0; k < n_observations; k++){
                numerator += (vectors[i][k] - means[i]) * (vectors[j][k] - means[j]);
            }
            double cov = numerator / (n_observations - 1);
            cov_matrix[i][j] = cov_matrix[j][i] = cov;
        }
    }

    return cov_matrix;
}

// int main(void)
// {
//     vector<vector<double>> features, expected, result;
//     features = {{1, 2, 3},{4, 5, 6}};
//     expected = {{1.0, 1.0}, {1.0, 1.0}};

//     result = calculated_covariance_matrix(features);

//     assert(result == expected);
// }