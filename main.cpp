#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <curl/curl.h>
#include "histogram.h"
#include "histogram_internal.h"
#include "text.h"
#include "svg.h"
using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count{};
};

Input input_data(istream& in) {
    bool prompt;
    Input inp;
    size_t number_count;
    //cout<<"write count of numbers";
    in >> number_count;

    inp.numbers.resize(number_count);

    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        in >> inp.numbers[i];
    }
    //cout << "Writes count of bins";
    in >> inp.bin_count;
    if (prompt) cerr<<1<<endl;
    return inp;
};

int main()
{
    curl_global_init(CURL_GLOBAL_ALL);
    vector<size_t> bins;
    Input in = input_data(cin);

    size_t dash, space;
    std::cin >> dash >> space;
    bins = make_histogram(in.numbers, in.bin_count, in.numbers.size());
    //show_histogram(bins, in.bin_count);
    show_histogram_svg(bins, dash, space);
    return 0;
}
