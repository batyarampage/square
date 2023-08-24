#include "enumerate.h"
#include "struct_of_square_equation.h"
#include <math.h>
#include <stdio.h>
#include <TXLib.h>

#ifndef new_solving_def
#define new_solivng_def

void solving_linear_equation (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);

void zero_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);

void positive_discriminant(struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square, double *discriminant);

type_of_equation type_of_equation_function (struct square_equation_coefs *equation_coef);

count_of_roots count_of_roots_func (struct square_equation_coefs *equation_coef, type_of_equation *type_of_input_equation, struct roots_square_equation *roots_square);

double Discriminant_calculation (struct square_equation_coefs *equation_coef);

bool compare_double_with_zero (double param);

#endif
