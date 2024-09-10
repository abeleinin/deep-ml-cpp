# Deep ML

Solutions to [deep-ml](https://www.deep-ml.com/) in C++ using the [Eigen Library](https://eigen.tuxfamily.org/)

## Solved

| ID |  Problem | Category | Difficulty | Code |
|----|----------|----------|------------|------|
| 1  | [Matrix times Vector](https://www.deep-ml.com/problem/Matrix%20times%20Vector) | Linear Algebra | Easy | [C++](/easy/matrix_dot_vector.cpp) |
| 2  | [Transpose of a Matrix](https://www.deep-ml.com/problem/Transpose%20of%20a%20Matrix) | Linear Algebra | Easy | [C++](easy/transpose.cpp) |
| 3  | [Reshape Matrix](https://www.deep-ml.com/problem/Reshape%20Matrix) | Linear Algebra | Easy | [C++](easy/reshape.cpp) |
| 4  | [Calculate Mean by Row or Column](https://www.deep-ml.com/problem/Calculate%20Mean%20by%20Row%20or%20Column) | Linear Algebra | Easy | [C++](easy/calculate_matrix_mean.cpp) |
| 5  | [Scalar Multiplication of a Matrix](https://www.deep-ml.com/problem/Scalar%20Multiplication%20of%20a%20Matrix) | Linear Algebra | Easy | [C++](easy/scalar_multiply.cpp) |
| 6  | [Calculate Eigenvalues of Matrix](https://www.deep-ml.com/problem/Calculate%20Eigenvalues%20of%20a%20Matrix) | Linear Algebra | Medium | [C++](medium/calculate_eigenvalues.cpp) |
| 7  | [Matrix Transformation](https://www.deep-ml.com/problem/Matrix%20Transformation) | Linear Algebra | Medium | [C++](medium/matrix_transformation.cpp) |
| 8  | [Calculate 2x2 Matrix Inverse](https://www.deep-ml.com/problem/Calculate%202x2%20Matrix%20Inverse) | Linear Algebra | Medium | [C++]() |
| 10  | [Calculate Covariance Matrix](https://www.deep-ml.com/problem/Calculate%20Covariance%20Matrix) | Linear Algebra | Medium | [C++](medium/calculate_covariance_matrix.cpp) |
| 11  | [Solve Linear Equations using Jacobi Method](https://www.deep-ml.com/problem/Solve%20Linear%20Equations%20using%20Jacobi%20Method) | Linear Algebra | Medium | [C++](medium/jacobi_method.cpp) |
| 12  | [Singular Value Decomposition (SVD)](https://www.deep-ml.com/problem/Singular%20Value%20Decomposition%20(SVD)) | Linear Algebra | Hard | [C++](hard/svd.cpp) |
| 14 | [Linear Regression Using Normal Equation](https://www.deep-ml.com/problem/Linear%20Regression%20Using%20Normal%20Equation) | Machine Learning | Easy | [C++](/easy/linear_regression_using_normal_equation.cpp) |
| 15 | [Linear Regression Using Gradient Descent](https://www.deep-ml.com/problem/Linear%20Regression%20Using%20Gradient%20Descent) | Machine Learning | Easy | [C++](/easy/linear_regression_using_gradient_descent.cpp) |
| 16 | [Feature Scaling Implementation](https://www.deep-ml.com/problem/Feature%20Scaling%20Implementation) | Machine Learning | Easy | [C++](/easy/feature_scaling.cpp) |
| 22 | [Sigmoid Activation Function Understanding](https://www.deep-ml.com/problem/Sigmoid%20Activation%20Function%20Understanding) | Deep Learning | Easy | [C++](/easy/sigmoid.cpp) |
| 23 | [Softmax Activation Function Implementation](https://www.deep-ml.com/problem/Softmax%20Activation%20Function%20Implementation) | Deep Learning | Easy | [C++](/easy/softmax.cpp) |
| 24 | [Single Neuron](https://www.deep-ml.com/problem/Single%20Neuron) | Deep Learning | Easy | [C++](/easy/single_neuron.cpp) |
| 27 | [Transformation Matrix from Basis B to C](https://www.deep-ml.com/problem/Transformation%20Matrix%20from%20Basis%20B%20to%20C) | Machine Learning | Easy | [C++](/easy/transform_basis.cpp) |
| 35 | [Convert Vector to Diagonal Matrix](https://www.deep-ml.com/problem/Convert%20Vector%20to%20Diagonal%20Matrix) | Linear Algebra | Easy | [C++](easy/vector_to_diagongal_matrix.cpp) |
| 36 | [Calculate Accuracy Score](https://www.deep-ml.com/problem/Calculate%20Accuracy%20Score) | Linear Algebra | Easy | [C++](easy/accuracy_score.cpp) |
| 39 | [Log Softmax](https://www.deep-ml.com/problem/Log%20Softmax) | Deep Learning | Easy | [C++](easy/log_softmax.cpp) |
| 42 | [ReLU Activation Function](https://www.deep-ml.com/problem/ReLU%20Activation%20Function) | Deep Learning | Easy | [C++](easy/relu.cpp) |
| 43 | [Ridge Regression Loss](https://www.deep-ml.com/problem/Ridge%20Regression%20Loss) | Machine Learning | Easy | [C++](easy/ridge_loss.cpp) |
| 44 | [Leaky ReLU Activation Function](https://www.deep-ml.com/problem/Leaky%20ReLU) | Deep Learning | Easy | [C++](easy/leaky_relu.cpp) |

## Dependencies

This project uses [Eigen](https://eigen.tuxfamily.org/) and [Catch2](https://github.com/catchorg/Catch2) C++ libraries. To install on macOS use the following commands:

```
brew install eigen  # c++ linear algebra library
brew install catch2 # c++ unit testing library
```

## Build and test

Run the following commands to build and run the unit tests:

```
cmake -S . -B build
cmake --build build
cd build && ctest
```