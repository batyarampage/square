#ifndef printer_func
#define printer_func

#include "struct_of_square_equation.h"
#include "enumerate.h"

void printer (type_of_equation *type_of_input_equation, struct roots_square_equation *roots_square, count_of_roots *count_of_roots);

void print_infinity_solution ();

void print_linear_equation (struct roots_square_equation *roots_square);

void print_zero_discriminant (struct roots_square_equation *roots_square);

void print_negative_discriminant ();

void print_linear_equation_zero (struct roots_square_equation *roots_square);

void print_positive_discriminant (struct roots_square_equation *roots_square);

#endif
