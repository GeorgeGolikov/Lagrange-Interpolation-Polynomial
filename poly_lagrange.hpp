#ifndef POLY_LAGRANGE_HPP
#define POLY_LAGRANGE_HPP

#include <vector>
#include "point.hpp"

class PolyLagrange
{
public:
  explicit PolyLagrange(std::vector<point_t> &);
  double operator()(double);

private:
  std::vector<point_t> table_;
  double getPolyValue(double);
};

#endif