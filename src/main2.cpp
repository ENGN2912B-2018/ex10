#include <iostream>
#include <cassert>
#include <math.h>

#include "integrate.hpp"

using namespace std;

// define a set of test functions
float y1(float x){
	// y(x) = 1/(1+x^2)
	return 1.0/(1.0+x*x);
}

float y2(float x){
	// y(x) = |x|
	return fabs(x);
}

//
// main function
int main(int argc, char* argv[]) {

	// define the default grid size
	int N = 10;

	// initialize integral range and number of uniform grid points
	float a = 0;
	float b = 1;

	// override default arguments
	switch (argc){
		case 4:
			N = atoi(argv[3]);
		case 3:
			b = atof(argv[2]);
			a = atof(argv[1]);
		case 1:
			break;
		default:
			cout << "Invalid number of paramaters entered!" << endl;
			return -1;
	}

	// compute the integral and send to std output
	float y_int_a_b = trapz(y1,a,b,N);
	//float y_int_a_b = trapz(y2,a,b,N);

	cout << "Value of definite integral is " << y_int_a_b << endl;

	return 0;
}
