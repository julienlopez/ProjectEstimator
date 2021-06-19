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

double Project::mean() const
{
  std::vector<double> means(m_tasks.size());
  std::transform(begin(m_tasks), end(m_tasks), begin(means), [](const auto &task) { return task.time->mean(); });
  return std::accumulate(begin(means), end(means), 0.);
}

double Project::std_dev() const
{
  std::vector<double> variances(m_tasks.size());
  std::transform(begin(m_tasks), end(m_tasks), begin(variances), [](const auto &task) { return std::pow(task.time->std_dev(), 2); });
  return std::sqrt(std::accumulate(begin(variances), end(variances), 0.));
}

}// namespace LibProjectEstimator