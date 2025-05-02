#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include "histogram.h"
#include "histogram_internal.h"
#include "text.h"
#include "svg.h"
using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count{};
};

Input input_data() {
    Input in;
    size_t number_count;
    //cout<<"write count of numbers";
    cin >> number_count;

    in.numbers.resize(number_count);

    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> in.numbers[i];
    }
    //cout << "Writes count of bins";
    cin >> in.bin_count;
    return in;
};

int main()
{
    vector<size_t> bins;
    Input in = input_data();
    bins = make_histogram(in.numbers, in.bin_count, in.numbers.size());
    //show_histogram(bins, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}
