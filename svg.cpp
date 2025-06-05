#include <vector>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "svg.h"

void
svg_begin(double width, double height) {
    std::cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    std::cout << "<svg ";
    std::cout << "width='" << width << "' ";
    std::cout << "height='" << height << "' ";
    std::cout << "viewBox='0 0 " << width << " " << height << "' ";
    std::cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void
svg_end() {
    std::cout << "</svg>\n";
}

void
show_histogram_svg(const std::vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    size_t maxim = 0;
    for (size_t bin: bins) if (bin>maxim) maxim = bin;
    double top = 0;
    std::vector<std::string> colors = {"black", "white", "yellow", "cyan", "green"};
    for (size_t i = 0; i < bins.size(); i++) {
        const double bin_width = (IMAGE_WIDTH-TEXT_WIDTH) / maxim * bins[i];
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, std::to_string(bins[i]));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", colors[i]);
        top += BIN_HEIGHT;
    }
    svg_end();
}

void svg_text(double left, double baseline, std::string text) {
    std::cout << "<text x='" << left << "' y='" << baseline << "'> " << text << "</text>";
}   // <text x='left' y='35' vertical-align='baseline'> text<text/>

void svg_rect(double x, double y, double width, double height,
        std::string stroke="black", std::string _fill="black") {
    printf("<rect x='%f' y='%f' width='%f' height='%f' ", x, y, width, height);
    std::cout<<"stroke='"<<stroke<< "' fill='"<<_fill<<"'></rect>";
}
