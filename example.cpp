#include <iostream>
#include "dft.hpp"

int main() {
    dsp::dft dft(4);
    std::vector<std::complex<double>> input = {1, 2, 3, 4};
    auto output = dft.compute(input);

    for (const auto& val : output) {
        std::cout << val << "\n";
    }

    return 0;
}