#include "printer_define.h"
void printer (type_of_equation *type_of_input_equation, struct roots_square_equation *roots_square, count_of_roots *count_of_roots){

    switch (*count_of_roots){

        case INFINITI:{

            print_infinity_solution ();
            break;

        }

        case ONE_ROOT:{

            if (*type_of_input_equation == LINEAR_EQUATION){

                print_linear_equation (roots_square);
                break;

            }

            else{

                print_zero_discriminant (roots_square);
                break;
            }

        }

        case NO_ROOTS:{

            if (*type_of_input_equation == QUADRATIC_EQUATION){

                print_negative_discriminant ();
                break;

            }

            else{

                print_linear_equation_zero (roots_square);
                break;

            }

        }

        case TWO_ROOT:{

            print_positive_discriminant (roots_square);

        }

        default:{
            break;

        }

    }

}


void print_infinity_solution (){

    printf("Уравнение иммеет бесконечное количество решений");
}

void print_linear_equation (struct roots_square_equation *roots_square){

    printf("Уравнение линейное, его решение равно %g", roots_square->x1);

}

void print_zero_discriminant (struct roots_square_equation *roots_square){

    printf("Дискриминант равен 0, решение единственно, оно равно %g", roots_square->x1);

}

void print_negative_discriminant (){

    printf("Дискриминант меньше 0, корней нет");

}

void print_linear_equation_zero (struct roots_square_equation *roots_square){

    printf("Уравнение линейное, его решение равно %g", roots_square->x1);
}

void print_positive_discriminant (struct roots_square_equation *roots_square){

    printf("Положительный дискриминант, 2 корня\n");
    printf("x1 = %g\n", roots_square->x1);
    printf("x2 = %g\n", roots_square->x2);
}
