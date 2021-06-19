#pragma once

namespace LibProjectEstimator {

class Distribution
{
protected:
  Distribution() = default;

public:
  virtual ~Distribution() = default;

  Distribution(const Distribution &) = delete;
  Distribution(Distribution &&) = delete;

  Distribution& operator=(const Distribution &) = delete;
  Distribution& operator=(Distribution &&) = delete;

  virtual double operator()() const = 0;

  virtual double mean() const = 0;

  virtual double std_dev() const = 0;
};

}// namespace LibProjectEstimator
