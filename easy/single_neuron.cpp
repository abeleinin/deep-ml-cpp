#include <Eigen/Dense>
#include <cmath>
#include <iostream>

using namespace std;
using namespace Eigen;

double sigmoid(double x);

pair<VectorXd, float> single_neuron(const MatrixXd& features, 
                                    const VectorXd& labels,
                                    const VectorXd& weights, 
                                    float bias)
{
    VectorXd prob(features.rows());
    float mse = 0.0;
    for (int i = 0; i < features.rows(); i++){
        float z = 0.0;
        for (int j = 0; j < features.cols(); j++){
            z += weights(j) * features(i,j);
        }
        prob(i) = sigmoid(z + bias);
        mse += pow(prob(i) - labels(i), 2);
    }
    mse /= features.rows();
    return {prob, mse};
}

// int main(void)
// {
//     MatrixXd features(3, 2);
//     VectorXd labels(3);
//     VectorXd weights(2);
//     features << 0.5, 1.0,
//                 -1.5, -2.0,
//                 2.0, 1.5;
//     labels << 0, 1, 0;
//     weights << 0.7, -0.4;
//     float bias = -0.1;

//     pair<VectorXd, float> result = single_neuron(features, labels, weights, bias);
//     cout << result.first << endl;
//     cout << result.second << endl;

//     return 0;
// }