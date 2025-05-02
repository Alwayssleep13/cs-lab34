#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <iostream>
#include <cstring>
#include <stdio.h>

void svg_begin(double width, double height);
void svg_end();
void show_histogram_svg(const std::vector<size_t>& bins, size_t, size_t);
void svg_text(double left, double baseline, std::string text);
void svg_rect(double x, double y, double width, double height,
    std::string stroke, std::string _fill);
#endif
