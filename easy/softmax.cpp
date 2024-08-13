#include <vector>
#include <cmath>
#include <iostream>

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

// int main(void)
// {
//     vector<double> a = {1, 2, 3};
//     vector<double> expected = {0.0900, 0.2447, 0.6652};

//     softmax(a);
//     for (int i = 0; i < a.size(); i++){
//         cout << a[i] << " == " << expected[i] << endl;
//     }
//     return 0;
// }