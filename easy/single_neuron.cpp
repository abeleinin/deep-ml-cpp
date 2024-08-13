#include <Eigen/Dense>
#include <cmath>
#include <iostream>

using namespace std;
using namespace Eigen;

double sigmoid(double x);

pair<VectorXd, double> single_neuron(const MatrixXd& features, 
                                    const VectorXd& labels,
                                    const VectorXd& weights, 
                                    double bias)
{
    VectorXd prob(features.rows());
    double mse = 0.0;
    for (int i = 0; i < features.rows(); i++){
        double z = 0.0;
        for (int j = 0; j < features.cols(); j++){
            z += weights(j) * features(i,j);
        }
        prob(i) = sigmoid(z + bias);
        mse += pow(prob(i) - labels(i), 2);
    }
    mse /= features.rows();
    return {prob, mse};
}
