#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<float> matrix_dot_vector(const vector<vector<float> >& m, const vector<float>& v)
{
    assert(m[0].size() == v.size());

    vector<float> res(v.size(), 0.0);

    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            res[i] += v[j] * m[i][j];
        }
    }       
    return res;
}

int main(void)
{
    vector<vector<float> > a = {{1, 2}, {2, 4}};
    vector<float> b = {1, 2};
    vector<float> exp = {5, 10};
    vector<float> res = matrix_dot_vector(a, b);
    assert(res == exp);

    a = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    b = {1, 2, 3};
    exp = {14, 26, 44};
    res = matrix_dot_vector(a, b);
    assert(res == exp);

    return 0;
}