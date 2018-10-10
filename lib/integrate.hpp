#pragma once

// Compute an approximate integral using the Trapezoidal Rule with uniform sample spacing
// Adopted from: https://www.geeksforgeeks.org/trapezoidal-rule-for-approximate-value-of-definite-integral/
template <typename T1, typename T2>
T1 trapz(T1 (*fn)(T1), const T2 a, const T2 b, const int N) {

	// validate input
	assert (b > a);
	assert (N > 1);

	// grid spacing
	T1 h = (b-a)/N;

	// compute value and sum first and last values in series
	T1 sum = fn(a) + fn(b);

	// add to cumulative sum using trapezoidal rule
	for (int i=1; i < N; i++) {
		sum += 2*fn(a + i*h);
	}

	return sum * h/2;
}
