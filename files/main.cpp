#include <stdio.h>
#include <TXLib.h>
#include "struct_of_square_equation.h"
#include "enumerate.h"
#include "cin_define.h"
#include "new_solving_def.h"
#include "printer_define.h"

int main (){

    //tests ();

    struct square_equation_coefs equation_coef;
    struct roots_square_equation roots_square;

    cin_coef (&equation_coef);

    type_of_equation type_of_input_equation = type_of_equation_function (&equation_coef);

    count_of_roots count_root = count_of_roots_func (&equation_coef, &type_of_input_equation, &roots_square);//solving_equation

    printer (&type_of_input_equation, &roots_square, &count_root);

    return 0;
}
