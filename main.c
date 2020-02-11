#include <stdio.h>
#include "my_complex.h"


int main() {
	Complex a = {3, 4};
	Complex b = {5, 12};
	
	double (*db_fns[2])(Complex);
	Complex (*Complex_fns[4])(Complex, Complex);
	//Created two arrays of pointers to functions
	
	db_fns[0] = magnitude;
	db_fns[1] = phase;
	//Adds the functions to the array

	Complex_fns[0] = complex_add;
       	Complex_fns[1] = complex_sub;
       	Complex_fns[2] = complex_mult;
        Complex_fns[3] = complex_div;
	//Stores the functions in the array

	printf("Test for the first array of function pointers\n");
	for(int i=0; i<2; i++) {
		printf("%lf\n",db_fns[i](a));
		printf("%lf\n",db_fns[i](b));
	}
	//Uses a for loop to test the first array of function pointers

	printf("\n");
	printf("Test for the second array of function pointers\n");

	for(int j=0; j<4; j++) {
		Complex c = Complex_fns[j](a,b);
		print_complex(c);
	}
	//For loop to test the second array of function pointers

	printf("\n");
	printf("Test for function handlers.\nSame results as previous tests mean it works\n");

	handler2(magnitude,a);
	handler2(magnitude,b);
	handler2(phase,a);
	handler2(phase,b);
	//Test to see if the second function handler works
	
	printf("\n");
	
	handler1(complex_add,a,b);
	handler1(complex_sub,a,b);
	handler1(complex_mult,a,b);
	handler1(complex_div,a,b);
	//Test to see if the first function handler works
	
	return 0;
}
