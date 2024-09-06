double leaky_relu(double x, double alpha /* = 0.01 */)
{
    return x > 0 ? x : x * alpha;
}