#include "dft.hpp"

namespace dsp {

dft::dft(int N) {
    this->N = N;
    buildTwiddleTable();
}

void dft::buildTwiddleTable() {
    this->twiddleTable.resize(N, std::vector<std::complex<double>>(N));
    for (int k = 0; k < this->N; k++) {
        for (int n = 0; n < this->N; n++) {
            double angle = (-2 * M_PI * n * k) / this->N;
            twiddleTable[k][n] = std::polar(1.0, angle);
        }
    }
}

std::vector<std::complex<double>> dft::compute(const std::vector<std::complex<double>> &inputs) {
    std::vector<std::complex<double>> output(N);
    
    for (int k = 0; k < N; k++) {
        output[k] = 0.0;
        for (int n = 0; n < N; n++) {
            output[k] += inputs[n] * twiddleTable[k][n];
        }
    }

    return output;
}

}

