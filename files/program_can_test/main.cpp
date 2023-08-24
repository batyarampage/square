#include <stdio.h>
#include <TXLib.h>
#include "struct_of_square_equation.h"
#include "enumerate.h"
#include "cin_define.h"
#include "new_solving_def.h"
#include "printer_define.h"
#include "test_coef.h"
#include "test_func_def.h"
#include "const_def.h"

bool user_wonna_test ();

bool user_wonna_test (){

    printf("Если хотите прогнать тесты введите единичку\n");
    int ed = 0;
    return scanf("%d", &ed);

}

/*void greeting_user_for_test (){

    printf("Если хотите прогнать unit-тесты, то введите единичку, иначе ноль");

}

void is_user_wonna_test (){

    greeting_user_for_test ();

    int parametr = 0; // вводимое число
    check_user_input (&parametr);
}

void check_user_input (int *parametr){



} */

int main (){

    //is_user_wonna_test ();

    if (user_wonna_test ()){

        test_square_coefs all_test[test_count] = {{}};
        testing (all_test);


    }

    struct square_equation_coefs equation_coef;
    struct roots_square_equation roots_square;

    cin_coef (&equation_coef);

    type_of_equation type_of_input_equation = type_of_equation_function (&equation_coef);

    count_of_roots count_root = count_of_roots_func (&equation_coef, &type_of_input_equation, &roots_square);//solving_equation

    printer (&type_of_input_equation, &roots_square, &count_root);

    return 0;
}
