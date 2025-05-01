#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#endif
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include "histogram.h"
const size_t MAX_ASTERISK = 80 - 3 - 1;

void find_minmax(std::vector<double>& numbers, double& min, double& max) {

    min = numbers[0];
    max = numbers[0];
    for (double num : numbers) {
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }
}

std::vector<size_t> make_histogram(std::vector<double>& numbers, size_t binCount, size_t countOfNumbers) {
    std::vector<size_t> bins;
    double min, max;
    size_t maxCount;

    bins.resize(binCount);
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / binCount;
    for (size_t i = 0; i < countOfNumbers; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < binCount - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (hi > numbers[i]))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[binCount - 1]++;
        }
    }
    maxCount = bins[0];
    for (int i = 1; i < bins.size(); i++) {
        if (maxCount < bins[i]) {
            maxCount = bins[i];
        }
    }
    return bins;
}

void show_histogram(std::vector<size_t>& bins, size_t bin_count) {
    size_t maxCount;
    maxCount = bins[0];
    for (int i = 1; i < bin_count; i++) {
        if (maxCount < bins[i]) {
            maxCount = bins[i];
        }
    }


    size_t height;
    for (int i = 0; i < bin_count; i++) {
            std::cout<<":)";

        if (bins[i] < 100) std::cout << " ";

        if (bins[i] < 10) std::cout << " ";

        std::cout << bins[i];
        std::cout << "|";

        if (maxCount > MAX_ASTERISK) height = MAX_ASTERISK * (static_cast<double>(bins[i]) / maxCount);
        else height = bins[i];

        for (size_t i2 = 0; i2 < height; i2++) std::cout << "*";
        std::cout << std::endl;
    }}
