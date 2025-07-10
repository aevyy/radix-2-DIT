#pragma once

#include <vector>
#include <complex>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace dsp {

class dft {
public:
    dft(int N);
    std::vector<std::complex<double>> compute(const std::vector<std::complex<double>> &input);    
private:
    int N;
    std::vector<std::vector<std::complex<double>>> twiddleTable;
    void buildTwiddleTable();
};
}   // Namespace dsp