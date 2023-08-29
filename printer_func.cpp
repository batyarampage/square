#include "printer_func.h"
#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "func_tools.h"


void printer (Type_of_equation type_of_input_equation, struct roots_square_equation const *roots_square, Count_of_roots const *count_of_roots){

    assert(count_of_roots != nullptr);
    assert(roots_square   != nullptr);

    switch (*count_of_roots){

        case INFINITE_NUMBER_OF_ROOTS:{

            print_infinity_solution ();

            break;
        }

        case ONE_ROOT:{

            if (type_of_input_equation == LINEAR_EQUATION){

                print_linear_equation (roots_square);

                break;
            }

            else{

                print_zero_discriminant (roots_square);
                break;
            }
        }

        case NO_ROOTS:{

            if (type_of_input_equation == QUADRATIC_EQUATION){

                print_negative_discriminant ();

                break;
            }

            else{

                print_linear_equation_zero ();

                break;
            }
        }

        case TWO_ROOTS:{

            print_positive_discriminant (roots_square);
        }

        case FAULT:{

            break;
        }

        default:{

            break;
        }
    }
}

void print_infinity_solution (){

    printf("Уравнение имеет бесконечное количество решений\n");
}

void print_linear_equation (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);

    static double epsilon = 1e-10;

    double x1 = roots_square->x1;

    if (fabs(x1) < epsilon){

        x1 = 0;
    }

    printf("Уравнение линейное, его решение равно %g", x1);
}

void print_zero_discriminant (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);



    double x1 = roots_square->x1;

    if (compare_double_with_zero(x1)){

        x1 = 0;
    }

    printf("Дискриминант равен 0, решение единственно, оно равно %g", x1);
}

void print_negative_discriminant (){

    printf("Дискриминант меньше 0, корней нет");
}

void print_linear_equation_zero (){

    printf("У уравнения нет решений");
}

void print_positive_discriminant (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);

    printf("Положительный дискриминант, 2 корня\n");
    printf("x1 = %g\n", roots_square->x1);
    printf("x2 = %g\n", roots_square->x2);
}
