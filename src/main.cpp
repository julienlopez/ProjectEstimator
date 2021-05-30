#include "Project.hpp"
#include "NormalDistribution.hpp"

#include <iostream>
#include <numeric>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

static constexpr auto USAGE =
  R"(Naval Fate.

    Usage:
          naval_fate ship new <name>...
          naval_fate ship <name> move <x> <y> [--speed=<kn>]
          naval_fate ship shoot <x> <y>
          naval_fate mine (set|remove) <x> <y> [--moored | --drifting]
          naval_fate (-h | --help)
          naval_fate --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
          --speed=<kn>  Speed in knots [default: 10].
          --moored      Moored (anchored) mine.
          --drifting    Drifting mine.
)";

std::pair<double, double>
  meanAndStdDev(const std::vector<double> &results)
{
  const auto mean = std::accumulate(begin(results), end(results), 0.) / size(results);
  double stddev = 0.;
  for (const auto d : results) {
    stddev += std::sqrt(std::pow(d - mean, 2));
  }
  return std::make_pair(mean, stddev / size(results));
}

int main(/*int argc, const char **argv */)
{
  // std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
  //   { std::next(argv), std::next(argv, argc) },
  //   true,// show help if requested
  //   "Naval Fate 2.0");// version string
  //
  // for (auto const &arg : args) {
  //   std::cout << arg.first << arg.second << std::endl;
  // }


  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  fmt::print("Hello, from {}\n", "{fmt}");

  LibProjectEstimator::Project p;
  p.addTask({ L"task 1", std::make_unique<LibProjectEstimator::NormalDistribution>(10., 2.) });
  p.addTask({ L"task 1", std::make_unique<LibProjectEstimator::NormalDistribution>(5., 1.) });
  p.addTask({ L"task 1", std::make_unique<LibProjectEstimator::NormalDistribution>(3., 3.) });
  p.addTask({ L"task 1", std::make_unique<LibProjectEstimator::NormalDistribution>(7., 1.) });
  p.addTask({ L"task 1", std::make_unique<LibProjectEstimator::NormalDistribution>(15., 5.) });

  const std::size_t N = 1000;
  std::vector<double> results(N);
  for (auto &res : results)
    res = p.estimate();

  fmt::print("Final stats\n");
  auto [mu, std_dev] = meanAndStdDev(results);
  fmt::print("mean = {}\n", mu);
  fmt::print("std dev  = {} \n", std_dev);
}
