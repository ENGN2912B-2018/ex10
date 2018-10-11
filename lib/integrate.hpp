#pragma once

/*
 * trapz() - This function computes an approximate definite integral using the
 * Trapezoidal Rule with uniform grid spacing.
 *
 * Inputs:
 * 	- float (*fn)(float):	pointer to some function f(x)
 * 	- const float a:		integral lower bound
 * 	- const float b:		integral upper bound
 * 	- const int N:			number of computational grids between a and b
 *
 * Output:
 *  - float:				approximate integral result
 *
 * Adopted from: https://www.geeksforgeeks.org/trapezoidal-rule-for-approximate-value-of-definite-integral
 */
template <typename T1, typename T2>
double trapz(T1 (*fn)(T1), const T2 a, const T2 b, const int N) {

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

