#pragma once

#include "Distribution.hpp"

#include <memory>
#include <string>
#include <vector>

namespace LibProjectEstimator {

struct Task
{
  std::wstring name;
  std::unique_ptr<Distribution> time;

  double estimate() const;
};

class Project
{
public:
  using Container = std::vector<Task>;

  void addTask(Task t);

  double estimate() const;

private:
  Container m_tasks;
};

}// namespace LibProjectEstimator
