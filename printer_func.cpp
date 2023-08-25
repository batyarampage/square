#include "printer_func.h"
#include <stdio.h>
#include <TXLib.h>
#include <assert.h>
#include <math.h>


void printer (Type_of_equation const *type_of_input_equation, struct roots_square_equation const *roots_square, Count_of_roots const *count_of_roots){

    assert(count_of_roots != nullptr);
    assert(type_of_input_equation != nullptr);
    assert(roots_square != nullptr);

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

                print_linear_equation_zero ();
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

    printf("��������� ������ ����������� ���������� �������");
}

void print_linear_equation (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);

    static double epsilon = 1e-10;

    double x1 = roots_square->x1;

    if (fabs(x1) < epsilon){

        printf("��������� ��������, ��� ������� ����� 0");
    }

    else {

        printf("��������� ��������, ��� ������� ����� %g", roots_square->x1);
    }
}

void print_zero_discriminant (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);

    static double epsilon = 1e-10;

    double x1 = roots_square->x1;

    if (fabs(x1) < epsilon){

        printf("������������ ����� 0, ������� �����������, ��� ����� 0");
    }

    else {

        printf("������������ ����� 0, ������� �����������, ��� ����� %g", x1);
    }



}

void print_negative_discriminant (){

    printf("������������ ������ 0, ������ ���");

}

void print_linear_equation_zero (){

    printf("� ��������� ��� �������");
}

void print_positive_discriminant (struct roots_square_equation const *roots_square){

    assert(roots_square != nullptr);

    printf("������������� ������������, 2 �����\n");
    printf("x1 = %g\n", roots_square->x1);
    printf("x2 = %g\n", roots_square->x2);
}