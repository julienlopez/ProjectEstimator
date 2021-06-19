#include "NormalDistribution.hpp"

#include <random>

namespace LibProjectEstimator {

NormalDistribution::NormalDistribution(double mean, double std_dev)
  : m_mean{ mean }, m_std_dev{ std_dev }
{
}

double NormalDistribution::operator()() const
{
  std::random_device rd{};
  std::mt19937 gen{ rd() };
  std::normal_distribution<> d{ m_mean, m_std_dev };
  return d(gen);
}

double NormalDistribution::mean() const
{
  return m_mean;
}

double NormalDistribution::std_dev() const
{
  return m_std_dev;
}

}// namespace LibProjectEstimator
