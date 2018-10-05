#include <stdlib.h>
#include <iostream>
#include <Eigen/Core>
#include <unsupported/Eigen/AutoDiff>


//! A custom AutoDiffScalar type
template <typename T, int N>
using ADScalar = Eigen::AutoDiffScalar<Eigen::Matrix<T, N, 1>>;


int main() {




}
