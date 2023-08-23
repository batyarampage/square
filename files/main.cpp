#include "struct_of_square_equation.h"
#include "cin_define.h"
#include "calculation_square_equation.h"

int main (){

    struct square_equation_coefs equation_coef;

    cin_coef (&equation_coef);

    solver (&equation_coef);

    return 0;
}
