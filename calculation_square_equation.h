#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "struct_of_square_equation.h"

#ifndef calculation_square_equation
#define calculation_square_equation


enum Square_solution_cases{ // solution_cases

   INFINITY_SOLUTIONS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
   LINEAR_EQUATION
};

void infinity_solutions ();

void no_roots ();

void one_root (struct square_equation_coefs *equation_coef);

void two_roots (struct square_equation_coefs *equation_coef, double discriminant);

void linear_equation (struct square_equation_coefs *equation_coef);

double Discriminant_calculation (struct square_equation_coefs *equation_coef);

Square_solution_cases Square_solution_cases_func (struct square_equation_coefs *equation_coef, double *discriminant);

bool compare_double_with_zero (double param);

void solver (struct square_equation_coefs *equation_coef);

#endif
