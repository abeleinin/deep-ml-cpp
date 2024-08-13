#include <vector>
#include <cassert>

using namespace std;

vector<float> matrix_dot_vector(const vector<vector<float> >& m, const vector<float>& v)
{
    // N x M matrix needs vector of length M
    assert(m[0].size() == v.size());

    vector<float> res(v.size(), 0.0);
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            res[i] += v[j] * m[i][j];
        }
    }       
    return res;
}
