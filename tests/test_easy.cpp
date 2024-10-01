#include "test_easy.h"
#include "test_utils.h"

TEST_CASE("Test accuracy_score") 
{
    vector<double> y_true = {1, 0, 1, 1, 0, 1};
    vector<double> y_pred = {1, 0, 0, 1, 0, 1};

    double expected = 0.8333;

    double result = accuracy_score(y_true, y_pred);

    REQUIRE_CLOSE(result, expected, 1e-4);
}

TEST_CASE("Test calculate_matrix_mean")
{
    MatrixXd a(3, 3);
    a << 1, 2, 3,
         4, 5, 6,
         7, 8, 9; 

    VectorXd expected_row(3);
    expected_row << 2, 5, 8;

    VectorXd expected_column(3);
    expected_column << 4, 5, 6;
    
    // Test row mean
    VectorXd result_row = calculate_matrix_mean(a, "row");
    REQUIRE(result_row == expected_row);

    // Test column mean
    VectorXd result_column = calculate_matrix_mean(a, "column");
    REQUIRE(result_column == expected_column);
}

TEST_CASE("Test feature_scaling")
{
    MatrixXd data(3, 2);
    data << 1, 2,
            3, 4,
            5, 6;

    auto result = feature_scaling(data);

    MatrixXd expectedFirst(3, 2);
    expectedFirst << -1.2247, -1.2247,
                     0.0, 0.0, 
                     1.2247, 1.2247;

    MatrixXd expectedSecond(3, 2);
    expectedSecond << 0.0, 0.0,  
                     0.5, 0.5,
                     1.0, 1.0;

    REQUIRE_CLOSE(result.first, expectedFirst, 1e-4);
    REQUIRE_CLOSE(result.second, expectedSecond, 1e-4);
}

TEST_CASE("Test linear_regression_using_gradient_descent")
{
    MatrixXd X(3, 2);
    X << 1, 1,
         1, 2,
         1, 3;

    VectorXd y(3);
    y << 1, 2, 3;

    VectorXd expected(2);
    expected << 0.110715, 0.951296;

    VectorXd result = linear_regression_gradient_descent(X, y, 0.01, 1000);
    REQUIRE_CLOSE(result, expected, 1e-4);
}

TEST_CASE("Test linear_regression_using_normal_equation")
{
    MatrixXd X(3, 2);
    X << 1, 1,
         1, 2,
         1, 3;

    VectorXd y(3);
    y << 1, 2, 3;

    VectorXd expect(2);
    expect << 0.0, 1.0;

    VectorXd result = linear_regression_normal_equation(X, y);
    REQUIRE(result == expect);
}

TEST_CASE("Test matrix_dot_vector")
{
    vector<vector<float> > a;
    vector<float> b, expect, result;

    // Test (2,2) * (2,)
    a = {{1, 2}, {2, 4}};
    b = {1, 2};
    expect = {5, 10};
    result = matrix_dot_vector(a, b);
    REQUIRE(result == expect);

    // Test (3,3) * (3,)
    a = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    b = {1, 2, 3};
    expect = {14, 26, 44};
    result = matrix_dot_vector(a, b);
    REQUIRE(result == expect);
}

TEST_CASE("Test reshape")
{
    // a is in memory using Column-major storage
    MatrixXd a(2, 4);
    a << 1, 2, 3, 4,
         5, 6, 7, 8; 

    MatrixXd expected(4, 2);
    expected << 1, 2, 
                3, 4,
                5, 6,
                7, 8; 
    
    MatrixXd result = reshape(a, make_tuple(4, 2));

    REQUIRE(result == expected);
}

TEST_CASE("Test scalar multiply")
{
    SECTION("Test vector implementation")
    {
        vector<vector<double>> b, expected_vec;

        b = {{1.0, 2.0}, {3.0, 4.0}};
        expected_vec = {{2.0, 4.0}, {6.0, 8.0}};

        scalar_multiply(b, 2);

        REQUIRE(b == expected_vec);
    }

    SECTION("Test Eigen implementation") 
    {
        MatrixXd a(2, 2);
        a << 1, 2,
             3, 4;

        MatrixXd expected(2, 2);
        expected << 2, 4,
                    6, 8;
    
        MatrixXd result = scalar_multiply(a, 2);

        REQUIRE(result == expected);
    }
}

TEST_CASE("Test sigmoid")
{
    double result;

    result = sigmoid(0);
    REQUIRE(result == 0.5);

    result = sigmoid(1);
    REQUIRE_CLOSE(result, 0.7311, 1e-4);

    result = sigmoid(-0.25);
    REQUIRE_CLOSE(result, 0.4378, 1e-4);
}

TEST_CASE("Test single_neuron")
{
    MatrixXd features(3, 2);
    VectorXd labels(3);
    VectorXd weights(2);
    features << 0.5, 1.0,
                -1.5, -2.0,
                2.0, 1.5;
    labels << 0, 1, 0;
    weights << 0.7, -0.4;
    float bias = -0.1;

    VectorXd expectedFirst(3);
    expectedFirst << 0.4626, 0.4134, 0.6682;
    double expectedSecond = 0.3349;

    pair<VectorXd, double> result = single_neuron(features, labels, weights, bias);

    REQUIRE_CLOSE(result.first, expectedFirst, 1e-3);
    REQUIRE_CLOSE(result.second, expectedSecond, 1e-4);
}

TEST_CASE("Test softmax")
{
    vector<double> a = {1, 2, 3};
    vector<double> expected = {0.0900, 0.2447, 0.6652};

    softmax(a);
    REQUIRE_CLOSE(a, expected, 1e-4);
}

TEST_CASE("Test transform_basis")
{
    Matrix3d B;
    B << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;
    Matrix3d C;
    C << 1, 2.3, 3,
         4.4, 25, 6,
         7.4, 8, 9;
        
    Matrix3d result =  transform_basis(B, C);

    MatrixXd expected(3,3);
    expected << -0.6772, -0.0126, 0.2342,
                -0.0184, 0.0505, -0.0275,
                0.5732, -0.0345, -0.0569;

    REQUIRE_CLOSE(result, expected, 1e-4);
}

TEST_CASE("Test transpose")
{
    MatrixXd a(2, 3);
    a << 1, 2, 3,
         3, 4, 5;

    MatrixXd result;
    result = transpose(a);
    REQUIRE(result == a.transpose());

    MatrixXd b(5, 3);
    b << 1, 2, 3,
         4, 5, 6,
         7, 8, 9,
         10, 11, 12,
         13, 14, 15;

    result = transpose(b);
    REQUIRE(result == b.transpose());
}

TEST_CASE("Test vector_to_diagonal")
{
    VectorXd x(3);
    x << 1, 2, 3;

    MatrixXd res = make_diagonal(x);

    REQUIRE(x == res.diagonal());
}

TEST_CASE("Test log_softmax")
{
    vector<double> a = {1, 2, 3};
    vector<double> expected = {-2.4076, -1.4076, -0.4076};

    log_softmax(a);

    REQUIRE_CLOSE(a, expected, 1e-4);
}

TEST_CASE("Test relu")
{
    double result;

    result = relu(0.5);
    REQUIRE(result == 0.5);

    result = relu(-1);
    REQUIRE(result == 0);

    result = relu(1);
    REQUIRE(result == 1);
}

TEST_CASE("Test ridge_loss")
{

    MatrixXd X(4, 2);
    X << 1, 1,
         2, 1, 
         3, 1,
         4, 1;
    VectorXd w(2);
    w << 0.2, 2.0;
    VectorXd y_true(4);
    y_true << 2, 3, 4, 5;

    double expected = 2.204;

    double result = ridge_loss(X, w, y_true, 0.1);
    
    REQUIRE_CLOSE(result, expected, 1e-4);
}

TEST_CASE("Test leaky_relu")
{
    REQUIRE(leaky_relu(0) == 0);
    REQUIRE(leaky_relu(1) == 1);
    REQUIRE(leaky_relu(-1) == -0.01);
    REQUIRE(leaky_relu(-2, 0.1) == -0.2);
}

TEST_CASE("Test linear kernel")
{
    VectorXd a(3);
    a << 1, 2, 3;

    VectorXd b(3);
    b << 4, 5, 6;

    auto result = linear_kernel(a, b);

    REQUIRE(result == 32);
}