# Classroom examples from Lectures 10 - Preprocessor Directives and Templates

## Numerical integration using the Trapezoidal Rule
Integration can be numerically approximated by using a variety of methods.  One such method, used here, is the Trapezoidal Rule:

<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}&space;f(x)&space;dx&space;\approx&space;\sum_{k=1}^{N}&space;\frac{f(x_{k-1})&plus;f(x_k)}{2}&space;\Delta&space;x_k" title="\int_{a}^{b} f(x) dx \approx \sum_{k=1}^{N} \frac{f(x_{k-1})+f(x_k)}{2} \Delta x_k" />

The Trapezoidal Rule is implemented in a function within `main1.cpp`.  Although we could replicate this function for each and every combination of data types, it is a much better solution to use C++ Templates.  In this manner, we need only to check that the input types and values are valid, rather than maintain numerous copies of the function implementation.

### Generate executables using CMake
```
mkdir build
cd build
cmake ..
make
``` 

Note that the preprocessor directive #define is used to define a preprocessor variable named `DEBUG`.  By commenting this line out, the programmer can explicitly suppress the debugging output because the compiler ignores any text between `#ifdef DEBUG` and `#endif`.  Excessive use of these directives can clutter the source code, so usage should be minimized for readability.  Nevertheless, these directives can be useful for quickly validating the program behavior when a debugger is overkill.

In `main1.cpp`, enter the test function name (i.e., y1, y2) as the first parameter to `trapz()` and validate the resulting output.  You can also use the optional command line parameters to validate the implementation with different integration step sizes.

```
./ex10p1
./ex10p1 -10 10 1000
```

## Using Function Templates

The main1.cpp function is strictly implemented using floats.  Suppose we wanted to use double data types instead.  How would we implement this?  This can be done using function overloading, but then two sets (or more!) of implementations must be maintained.  This is where Function Templates come into play.


