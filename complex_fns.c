#include <stdio.h>
#include <math.h>
#include "my_complex.h"

double magnitude(Complex c) {
	return sqrt((c.real*c.real) + (c.imag*c.imag));
}

double phase(Complex c) {
	double ph = atan(c.imag/c.real);
	ph = ph * (180/M_PI);
	return (ph<0) ? -ph : ph;
}

void print_complex(Complex c) {
	if(c.imag < 0) {
		printf("%.3lf - %.3lf\n", c.real, -c.imag);
	}
	else {
		printf("%.3lf + %.3lf\n", c.real, c.imag);
	}
}

Complex complex_conj(Complex c) {
	c.imag *= -1;
	return c;
}

Complex complex_add(Complex c1, Complex c2) {
	Complex c = {c1.real+c2.real, c1.imag+c2.imag};
	return c;
}
		
Complex complex_sub(Complex c1, Complex c2) {
	Complex c = {c1.real-c2.real, c1.imag-c2.imag};
	return c;
}

Complex complex_mult(Complex c1, Complex c2) {
	Complex c = {(c1.real*c2.real)+(c1.imag*c2.imag*-1), (c1.imag*c2.real) + (c1.real*c2.imag)};
	return c;
}

Complex complex_div(Complex c1, Complex c2) {
	double denom = magnitude(c2)*magnitude(c2);
	Complex c = complex_mult(c1, complex_conj(c2));
	if(denom != 0) {
		c.real /= denom;
		c.imag /= denom;
		return c;
		//Only allows division if the denom != 0
	}
	else{
		denom = 1;
		c.real /= denom;
		c.imag /= denom;
		return c;
	}// changes the denominator to 1, so the division will be possible for the computer to compute.
}
void handler1(Complex (*hdlr1)(Complex, Complex), Complex c1, Complex c2) {
	Complex result = hdlr1(c1,c2);
	print_complex(result);
}//Creates a handler function to compute any of the functions that return a complex, and take two complex structures as inputs

void handler2(double (*hdlr2)(Complex), Complex c1){
	double result = hdlr2(c1);
	printf("%lf\n", result);
}// Creates a second handler function that computes any function that returns a double, and takes a Complex structure as an input. Then it prints the result.

