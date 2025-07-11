#include <iostream>
#include "dft.hpp"

int main() {
    dsp::fft myFFT;

    std::vector<std::complex<double>> input = {
        1, 2, 3, 4, 5   // Length 5, not a power of 2
    };

    auto output = myFFT.compute(input);

    std::cout << "FFT Output:\n";
    for (const auto &val : output) {
        std::cout << val << "\n";
    }
}