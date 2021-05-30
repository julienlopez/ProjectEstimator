#include "Project.hpp"

#include "Distribution.hpp"

#include <algorithm>
#include <functional>
#include <numeric>

namespace LibProjectEstimator {


double Task::estimate() const
{
  return (*time)();
}

void Project::addTask(Task t)
{
  m_tasks.push_back(std::move(t));
}

double Project::estimate() const
{
  std::vector<double> times(m_tasks.size());
  std::transform(begin(m_tasks), end(m_tasks), begin(times), std::mem_fn(&Task::estimate));
  return std::accumulate(begin(times), end(times), 0.);
}

}// namespace LibProjectEstimator