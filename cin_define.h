#include <stdio.h>
#include <TXLib.h>
#include "struct_of_square_equation.h"

#ifndef cin_define
#define cin_define

void cin_coef (struct square_equation_coefs *equation_coef);

void charchecker (int *ch);

void a_coef_input (struct square_equation_coefs *equation_coef);

void b_coef_input (struct square_equation_coefs *equation_coef);

void c_coef_input (struct square_equation_coefs *equation_coef);

void get_correct_input (double *inputParam, char curr_input_param);

void print_enter_coef (char coef);

void greetings_user ();

bool cin_is_normal ();

#endif
