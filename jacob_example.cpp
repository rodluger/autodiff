#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>

/*
 *  * Testing differentiation that will produce a Jacobian, using functors and the
 *   * AutoDiffJacobian helper.
 *    */

template <typename Scalar>
struct adFunctor
{
  typedef Eigen::Matrix<Scalar, 3, 1> InputType;
  typedef Eigen::Matrix<Scalar, 2, 1> ValueType;
  typedef Eigen::Matrix<Scalar,
                        ValueType::RowsAtCompileTime,
                        InputType::RowsAtCompileTime> JacobianType;

  enum {
    InputsAtCompileTime = InputType::RowsAtCompileTime,
    ValuesAtCompileTime = ValueType::RowsAtCompileTime
  };

  adFunctor() {}

  size_t inputs() const { return InputsAtCompileTime; }

  template <typename InputType, typename ValueType>
  void operator() (const InputType &input,
                   ValueType *output) const
  {
    //Scalar s1 = Scalar(0), s2 = Scalar(0);

    /* Some operations to test the AD. */
    for (int i = 0; i < 3; i++)
    {
      //s1 =  log(input(i));
      //s2 =  sqrt(input(i));
    }

    (*output)(0) = input(0);
    (*output)(1) = input(1) * input(1);
  }
};



int main(int argc, char *argv[])
{
  Eigen::Matrix<double, 3, 1> in;
  in << 1,2,3;
  Eigen::Matrix<double, 2, 1> out;
  Eigen::AutoDiffJacobian< adFunctor<double> > adjac;
  adjac(in, &out);
  std::cout << in << "\n\n";

  std::cout << out << "\n";
  return 0;
}
