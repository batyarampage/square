#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "struct_of_square_equation.h"

#ifndef calculation_square_equation
#define calculation_square_equation


enum Square_solution_cases{ /// —лучаи, которые могут быть при решении квадратного уравнени€

   INFINITY_SOLUTIONS = -1, ///< ”казывает на бесконечность решений
   NO_ROOTS,///< ”казывает на то, что дискриминант отрицательный
   ONE_ROOT,///< ”казывает на нулевой дискриминант
   TWO_ROOTS,///< ”казывает на положительность дискриминанта
   LINEAR_EQUATION/// ”казывает на линейное уравнение или в общем случае квадратное уравнение с a=b=0 и c!=0
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
