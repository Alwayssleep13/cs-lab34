#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include "text.h"
const size_t MAX_ASTERISK = 80 - 3 - 1;

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
