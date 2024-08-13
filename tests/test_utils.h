#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <catch2/catch_test_macros.hpp>

#include <Eigen/Dense>

#include <cmath>

using namespace Eigen;

bool all_close(double a, double b, float tolerance) {
    return fabs(a - b) < tolerance;
}

template <typename T>
bool all_close(const T& a, const T& b, float tolerance) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (std::abs(a[i] - b[i]) > tolerance) {
            return false;
        }
    }

    return true;
}

bool all_close(const MatrixXd& a, const MatrixXd& b, float tolerance) {
    if (a.rows() != b.rows() || a.cols() != b.cols()) {
        return false;
    }

    for (int i = 0; i < a.rows(); ++i) {
        for (int j = 0; j < a.cols(); ++j) {
            if (std::abs(a(i, j) - b(i, j)) > tolerance) {
                return false;
            }
        }
    }

    return true;
}

#define REQUIRE_CLOSE(a, b, tolerance) REQUIRE(all_close(a, b, tolerance))

#endif // TEST_UTILS_H