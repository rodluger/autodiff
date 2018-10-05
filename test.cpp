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

    // Declare our type and the number of derivative
    // directions to compute
    using T = double;
    const int N = 2;

    // Instantiate an AutoDiffScalar
    ADScalar<T, N> x;
    x.value() = 1.0;
    x.derivatives() = Vector<T>::Unit(N, 0);

    // Instantiate another AutoDiffScalar
    ADScalar<T, N> y;
    y.value() = 2.0;
    y.derivatives() = Vector<T>::Unit(N, 1);

    // Compute the function value and its derivs
    ADScalar<T, N> result = func(x, y);
    std::cout << result.value() << std::endl;
    std::cout << result.derivatives() << std::endl;

}
