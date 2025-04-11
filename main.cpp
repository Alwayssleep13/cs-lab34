#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;


int main()
{
    vector<double> numbers;
    vector<size_t> bins;
    size_t countOfNumbers;
    size_t binCount;
    size_t maxCount;
    cerr << "Input count of numbers:";
    cin >> countOfNumbers;
    numbers.resize(countOfNumbers);
    for (int i = 0; i < countOfNumbers; i++) {
        cerr << i+1 << ": "; cin >> numbers[i];
    }
    cerr << "Input count of bins:";
    cin >> binCount;

    double c;
    if (binCount == 0){
        c = sqrt(countOfNumbers);
        if (c > 25){
            c = 1 + log2(c);
            cout << "rule of Stredjers";
        }
        else cout << "emperic formule";
        binCount = (size_t) c;
        cout << " " << binCount;
    }
    bins.resize(binCount);
    double min = numbers[0];
    double max = numbers[0];
    for (double num : numbers) {
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }
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


    size_t height;
    for (int i = 0; i < binCount; i++) {
            cout<<":)";

        if (bins[i] < 100) cout << " ";

        if (bins[i] < 10) cout << " ";

        cout << bins[i];
        cout << "|";

        if (maxCount > MAX_ASTERISK) height = MAX_ASTERISK * (static_cast<double>(bins[i]) / maxCount);
        else height = bins[i];

        for (size_t i2 = 0; i2 < height; i2++) cout << "*";
        cout << endl;
    }
    return 0;
}
