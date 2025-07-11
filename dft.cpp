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

std::vector<std::complex<double>> fft::compute(const std::vector<std::complex<double>> &input) {
    int originalSize    = input.size();
    int paddedSize      = nextPowerOfTwo(originalSize);

    std::vector<std::complex<double>> paddedInput = input;
    paddedInput.resize(paddedSize, 0.0);    // Padding with zerors

    return recursiveFFT(paddedInput);

}

std::vector<std::complex<double>> fft::recursiveFFT(const std::vector<std::complex<double>> &x) {
    int n = x.size();

    // Base case
    if (n == 1) return x;

    // Seperating the input into ecen and odd indexed elements
    std::vector<std::complex<double>> even(n/2), odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = x[i * 2];     // -> x[0], x[2], ...
        odd[i] = x[i * 2 + 1];  // -> x[1], x[2], ...
    }

    // Recursive calls to compute FFT of even and odd parts
    auto E = recursiveFFT(even);    // E_k: FFT of even terms
    auto O = recursiveFFT(odd);     // O_k: FFT of odd terms

    // Now lets merge the odd and even results using twiddle factors
    std::vector<std::complex<double>> X(n);
    for (int k = 0; k < n/2; k++) {
        // Twiddle factor: e^(-j * 2 * pi * k/n)
        std::complex<double> twiddle = std::polar(1.0, -2 * M_PI * k / n);

        // Butterfly operation:
        // X{k] = E[k] + W * O[k]
        // X[k + n/2] = E[k] - W * O[K]
        X[k] = E[k] + twiddle * O[k];
        X[k + n/2] = E[k] - twiddle * O[k];
    }

    return X;
}

}   // Namespace dsp