#pragma once

#include "Distribution.hpp"

namespace LibProjectEstimator {

class NormalDistribution : public Distribution
{
public:
  NormalDistribution(double mean, double std_dev);

  virtual ~NormalDistribution() = default;

  double operator()() const override;

private:
  const double m_mean;
  const double m_std_dev;
};

}// namespace LibProjectEstimator
