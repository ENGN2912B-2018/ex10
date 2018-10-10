#pragma once

// Compute an approximate integral using the Trapezoidal Rule with uniform sample spacing
// Adopted from: https://www.geeksforgeeks.org/trapezoidal-rule-for-approximate-value-of-definite-integral/
template <typename T>
T trapz(T (*fn)(T), const T a, const T b, const int N) {

	// validate input
	assert (b > a);
	assert (N > 1);

	// grid spacing
	auto h = (b-a)/N;

	// compute value and sum first and last values in series
	T sum = fn(a) + fn(b);

	// add to cumulative sum using trapezoidal rule
	for (int i=1; i < N; i++) {
		sum += 2*fn(a + i*h);
	}

	return sum * h/2;
}
