#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "histogram_internal.h"

TEST_CASE("distinct positive numbers") {
    double min = 0;
    double max = 0;
    find_minmax({1, 2}, min, max);
    CHECK(min == 1);
    CHECK(max == 2);
}

TEST_CASE("empty vector") {
    double min = NULL;
    double max = NULL;
    CHECK(!find_minmax({}, min, max));
}

TEST_CASE("singular vector") {
    double min = 0;
    double max = 0;
    find_minmax({3}, min, max);
    CHECK(min == 3);
    CHECK(max == 3);
}

TEST_CASE("negative vector") {
    double min = 0;
    double max = 0;
    find_minmax({-1, -3}, min, max);
    CHECK(min == -3);
    CHECK(max == -1);
}

TEST_CASE("equal vector") {
    double min = 0;
    double max = 0;
    find_minmax({3, 3, 3, 3}, min, max);
    CHECK(min == 3);
    CHECK(max == 3);
}
