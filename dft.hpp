#pragma once

#include <vector>
#include <complex>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace dsp {

class fft {
public:
    fft() = default;
    std::vector<std::complex<double>> compute(const std::vector<std::complex<double>> &input);    
private:
    std::vector<std::complex<double>> recursiveFFT(const std::vector<std::complex<double>> &x);
    bool isPowerOfTwo(int n);
    int nextPowerOfTwo(int n);
};
}   // Namespace dsp