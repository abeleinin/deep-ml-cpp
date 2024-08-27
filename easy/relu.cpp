#include <algorithm>

using namespace std;

double relu(const double& z)
{
    return max(0.0, z);
}