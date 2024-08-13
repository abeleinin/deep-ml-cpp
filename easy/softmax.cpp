#include <vector>
#include <cmath>

using namespace std;

void softmax(vector<double>& z)
{
    double Z = 0.0;
    for (auto& z_i : z){
        z_i = exp(z_i);
        Z += z_i;
    }
    for (auto& z_i : z){
        z_i /= Z;
    }
}
