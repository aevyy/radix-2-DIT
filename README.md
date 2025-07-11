## Radix-2 Decimation-in-Time FFT

A simple and clean implementation of the Cooley–Tukey radix-2 decimation-in-time Fast Fourier Transform (FFT) algorithm, written for learning and experimentation.

The algorithm uses a recursive divide-and-conquer and handles non-power-of-two inputs through zero-padding.

Algorithm: split the input into even and odd indexed elements, compute the FFT of each half, then combine the results.


### Reference:
- [Cooley–Tukey FFT algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)
