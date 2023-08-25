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

    get_coefs (&equation_coef);

    Type_of_equation type_of_input_equation = type_of_equation_function (&equation_coef);
    Count_of_roots roots_quantity = solving_equation (&equation_coef, &type_of_input_equation, &roots_square);

    printer (&type_of_input_equation, &roots_square, &roots_quantity);

    return 0;
}
