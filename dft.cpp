#include "dft.hpp"

namespace dsp {

bool fft::isPowerOfTwo(int n) {
    return ((n > 0) && (n & n-1)) == 0;
}

int fft::nextPowerOfTwo(int n) {
    if (n <= 0) return 1;
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

std::vector<std::complex<double>> fft::compute(const std::vector<std::complex<double>> &inputs) {

}

std::vector<std::complex<double>> fft::recursiveFFT(const std::vector<std::complex<double>> &input) {
    
}

}

