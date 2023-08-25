#include "struct_of_square_equation.h"
#include "enumerate.h"
#include "enter_coef.h"
#include "new_solving.h"
#include "printer_func.h"
#include "test_coef.h"
#include "testing_func.h"
#include "const_def.h"

int main (){

    is_user_wonna_test ();

    struct square_equation_coefs equation_coef;
    struct roots_square_equation roots_square;

    cin_coef (&equation_coef);      // get_coefs

    type_of_equation type_of_input_equation = type_of_equation_function (&equation_coef);// enum с большой

    count_of_roots roots_quantity = count_of_roots_func (&equation_coef, &type_of_input_equation, &roots_square);//solving_equation   enum с большой

                    //roots_quantity



    printer (&type_of_input_equation, &roots_square, &roots_quantity);

    return 0;
}
