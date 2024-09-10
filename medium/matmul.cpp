#include <vector>
#include <optional>

using namespace std;

optional<vector<vector<double>>> matmul(const vector<vector<double>>& a, const vector<vector<double>>& b)
{
    if (a[0].size() != b.size()) return nullopt;

    vector<vector<double>> vals;
    
    for (int i = 0; i < a.size(); i++) {
        vector<double> hold;
        for (int j = 0; j < b[0].size(); j++) {
            double val = 0;
            for (int k = 0; k < b.size(); k++) {
                val += a[i][k] * b[k][j];
            }
            hold.push_back(val);
        }
        vals.push_back(hold);
    }

    return vals;
}
