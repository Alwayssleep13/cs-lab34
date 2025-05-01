#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
std::vector<size_t> make_histogram(std::vector<double>& numbers, size_t binCount, size_t countOfNumbers);
void show_histogram(std::vector<size_t>& bins, size_t bin_count);
void find_minmax(std::vector<double>& numbers, double& min, double& max);

#endif // HISTOGRAM_H_INCLUDED
