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
    if (prompt) cerr<<"Enter bin count"<<endl;
    return inp;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, stdout);
}

int main(int argc, char** argv)
{
    if (argc > 1) {
    FILE *file = fopen(argv[1], "rb");
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        /* Perform the request, res gets the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            exit(1);}
        }
        /* always cleanup */
    curl_easy_cleanup(curl);
    return 0;
    }
    curl_global_init(CURL_GLOBAL_ALL);
    vector<size_t> bins;
    Input in = input_data(cin);

    bins = make_histogram(in.numbers, in.bin_count, in.numbers.size());
    //show_histogram(bins, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}
