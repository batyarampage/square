
#ifndef new_solving
#define new_solivng

#include "enumerate.h"
#include "struct_of_square_equation.h"

void solving_linear_equation (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);

void zero_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);

void positive_discriminant(struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square, double *discriminant);

type_of_equation type_of_equation_function (struct square_equation_coefs *equation_coef);

count_of_roots count_of_roots_func (struct square_equation_coefs *equation_coef, enum type_of_equation const *type_of_input_equation, struct roots_square_equation *roots_square);

double Discriminant_calculation (struct square_equation_coefs *equation_coef);

bool compare_double_with_zero (double param);

#endif
