#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include "histogram_internal.h"
#include <vector>
std::vector<size_t> make_histogram(std::vector<double>& numbers, size_t binCount, size_t countOfNumbers);

#endif // HISTOGRAM_H_INCLUDED
