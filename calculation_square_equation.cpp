#include "calculation_square_equation.h"

void infinity_solutions (){

    printf("Уравнение имеет бесконечное количество решений\n");

}

void no_roots (){

    printf("Уравнение не имеет решений на множестве действительных чисел\n");

}

void one_root (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;

    double solution = -b/(2*a);

    printf("дискриминант = 0, решение единственно, оно равно %g\n", solution);

}

void two_roots (struct square_equation_coefs *equation_coef, double discriminant){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;
    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b+sqrt_discriminant)/(2*a);
    double x2 = (-b-sqrt_discriminant)/(2*a);

    printf("уравнение имеет 2 решения\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}

void linear_equation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double c = equation_coef->c;

    if (compare_double_with_zero(b)){

        printf("Уравнение не имеет решений");
    }
    else{

        double solution = -c/b;
        printf("уравнение линейное, его решение = %g\n", solution);

    }
}

double Discriminant_calculation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    return b*b-4*a*c;

}

Square_solution_cases Square_solution_cases_func (struct square_equation_coefs *equation_coef, double *discriminant){

    assert(discriminant != nullptr);
    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    if (compare_double_with_zero(a)){   // linear equation

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

bool compare_double_with_zero (double param){

    static double EPSILON = 1e-10;

    if (fabs(param) < EPSILON){

        return true;

    }

    return false;
}




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
