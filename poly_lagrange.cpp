#include "poly_lagrange.hpp"

PolyLagrange::PolyLagrange(std::vector<point_t> & table):
    table_(table)
{ }

double PolyLagrange::operator()(double x)
{
  return getPolyValue(x);
}

double PolyLagrange::getPolyValue(double x)
{
  double value = 0;

  for (size_t k = 0; k < table_.size(); ++k)
  {
    double Tk = 1;
    size_t i = 0;

    while (i != k)
    {
      Tk *= (x - table_[i].x) / (table_[k].x - table_[i].x);
      ++i;
    }
    ++i;
    while (i < table_.size())
    {
      Tk *= (x - table_[i].x) / (table_[k].x - table_[i].x);
      ++i;
    }

    value += Tk * table_[k].y;
  }

  return value;
}