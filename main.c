#include <stdio.h>
#include "my_complex.h"


int main() {
	Complex a = {3, 4};
	Complex b = {5, 12};
	
	double (*db_fns[2])(Complex);
	Complex (Complex_fns[4])(Complex, Complex);
	//Created two arrays of pointers to functions
	
	db_fns[0] = magnitude;
	db_fns[1] = phase;

	Complex_fns[0] = complex_add;
       	Complex_fns[1] = complex_sub;
       	Complex_fns[2] = complex_mult;
        Complex_fns[3] = complex_div;

	for(int i=0; i<2; i++) {
		db_fns[i](a);
		db_fns[i](b);
	}

	for(int j=0; j<4; j++) {
		Complex_fns[j](a,b);
	}


	
	return 0;
}
