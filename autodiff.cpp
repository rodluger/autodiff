#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <unsupported/Eigen/AutoDiff>

//! A generic row vector
template <typename T>
using Vector = Eigen::Matrix<T, Eigen::Dynamic, 1>;

//! A custom AutoDiffScalar type
template <typename T, int N>
using ADScalar = Eigen::AutoDiffScalar<Eigen::Matrix<T, N, 1>>;


//! The function we'd like to differentiate
template <typename T>
T func(T x, T y) {
    return x * x * x + y * y;
}

//! A silly example
int main() {

    ADScalar<double, 2> x;
    ADScalar<double, 2> y;

    x.value() = 5;
    y.value() = 3;

    x.derivatives() = Vector<double>::Unit(2, 0);
    y.derivatives() = Vector<double>::Unit(2, 1);

    ADScalar<double, 2> result;
    result = func(x, y);

    std::cout << result.value() << std::endl;
    std::cout << result.derivatives() << std::endl;
}
