#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

double accuracy_score(const vector<double>& y_true, const vector<double>& y_pred)
{
    assert(y_true.size() == y_pred.size());
    double correct = 0;
    for (int i = 0; i < y_true.size(); i++){
        if (y_true[i] == y_pred[i]){
            ++correct;
        }
    }

    return correct / y_true.size();
}
