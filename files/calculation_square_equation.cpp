#include "calculation_square_equation.h"


///���������, ���� ���������� ��������� ����� ����������� ���������� ������

/*!
 ��� ������� �������� case INFINITY_SOLUTIONS, ������������� � solver
*/
void infinity_solutions (){

    printf("��������� ����� ����������� ���������� �������\n");

}


///���������, ���� ���������� ��������� �� ����� �������

/*!
 ��� ������� �������� case NO_ROOTS, ������������� � solver
*/
void no_roots (){

    printf("��������� �� ����� ������� �� ��������� �������������� �����\n");

}


///���������, ���� � ����������� ��������� ������������ = 0

/*!
 ��� ������� �������� case ONE_ROOT, ������������� � solver

 \param equation_coef - ��������� �� ��������� �� ������ ����������� ���������
*/
void one_root (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;

    double solution = -b/(2*a);

    if (compare_double_with_zero(solution)){

        printf("������������ = 0, ������� �����������, ��� ����� 0");

    }

    else{

        printf("������������ = 0, ������� �����������, ��� ����� %g\n", solution);

    }
}

///���������, ����� � ����������� ��������� ������������ > 0

/*!
 ��� ������� �������� case TWO_ROOTS, ������������� � solver

*/
void two_roots (struct square_equation_coefs *equation_coef, double discriminant){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;
    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b+sqrt_discriminant)/(2*a);
    double x2 = (-b-sqrt_discriminant)/(2*a);

    printf("��������� ����� 2 �������\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}


/// ���������, ����� ���������� ��������� - ��������, � ��������� ���������� ������� ��. �������� ������� Square_solution_cases_func
void linear_equation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double c = equation_coef->c;



    if (compare_double_with_zero(b)){

        printf("��������� �� ����� �������");
    }

    else{

        double solution = -c/b;

        if (compare_double_with_zero(solution)){

            printf("��������� ��������, ��� ������� = 0");

        }

        else{

            printf("��������� ��������, ��� ������� = %g\n", solution);
        }
    }
}

/// ������� ������������� ����������� ���������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/
double Discriminant_calculation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    return b*b-4*a*c;

}




/// �������, ������� ���������� ���������� ������

/*!

���������� ���������� ������, ��� ��������� ��������� ���������, ���� �������� ����������� ������������ ����� ������ ��������� ���������
\param equation_coef - ��������� �� ���������, ���������� ����������� ����������� ���������
\param discriminant - ��������� �� discriminant, ����� ��������� ���, ���� �� ������ � else

��������� ��������� �� ����

\code
    Square_solution_cases Square_solution_cases_func (struct square_equation_coefs *equation_coef, double *discriminant){

    if (compare_double_with_zero(a)){   // ��������� ��������� ���������, ��� ������������� �������, ��� ���������� �������

        if ((compare_double_with_zero(b)) && (compare_double_with_zero(c))){

            return INFINITY_SOLUTIONS; // ������������� �������
        }

        return LINEAR_EQUATION; // ���� �� ����������, �.�. �����-�� ���������� �� ����, ����� ��������� ������ �������� ������������ b
                                // � ���������� c, ��� ����������� � ������� linear_equation

    }


\endcode

*/
Square_solution_cases Square_solution_cases_func (struct square_equation_coefs *equation_coef, double *discriminant){

    assert(discriminant != nullptr);
    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    if (compare_double_with_zero(a)){

        if ((compare_double_with_zero(b)) && (compare_double_with_zero(c))){

            return INFINITY_SOLUTIONS;
        }

        return LINEAR_EQUATION;

    }

    else{

        *discriminant = Discriminant_calculation (equation_coef);

        if (compare_double_with_zero(*discriminant)){

            return ONE_ROOT;

        }

        else if (*discriminant > 0){

            return TWO_ROOTS;

        }

        return NO_ROOTS;

    }
}






///������� ��������� ����� � ��������� ������ � �����

/*!
 ���������� ����� ���� double � ����� � ��������� EPSILON
 \param param - ������� ����� � ��������� ������, ������� ����� �������� � �����

*/
bool compare_double_with_zero (double param){

    static double EPSILON = 1e-20;

    if (fabs(param) < EPSILON){

        return true;

    }

    return false;
}



///�������� ������� ������� ����������� ���������, ���������� � main
/*!
� ��� ������� ��� �������, ������������� � ����� calculation_square_equation.cpp

\param  equation_coef - �������� ���������� �� ��������� ������������� a,b,c ����������� ���������

*/
void solver (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double discriminant = 0;
    Square_solution_cases Root_counter = Square_solution_cases_func (equation_coef, &discriminant);

    switch (Root_counter){

        case INFINITY_SOLUTIONS:{

            infinity_solutions ();
            break;

        }

        case NO_ROOTS:{

            no_roots ();
            break;

        }

        case ONE_ROOT:{

            one_root (equation_coef);
            break;

        }

        case TWO_ROOTS:{

            two_roots (equation_coef, discriminant);
            break;
        }

        case LINEAR_EQUATION:{

            linear_equation (equation_coef);
            break;

        }

        default:{

            break;

        }
    }
}
