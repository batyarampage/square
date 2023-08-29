#include "new_solving.h"
#include <assert.h>
#include <math.h>

void solving_linear_equation (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square){

    assert(equation_coef != nullptr);
    assert(roots_square != nullptr);

    double b = equation_coef->b;
    double c = equation_coef->c;
    double solution = -c/b;

    roots_square->x1 = solution;
}

void solve_equation_with_zero_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square){

    assert(equation_coef != nullptr);
    assert(roots_square != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;

    double solution = -b/(2*a);

    if (compare_double_with_zero(solution)){

       roots_square->x1 = 0;

    }

    else{

        roots_square->x1 = solution;
    }
}

void solve_equation_with_positive_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square, double *discriminant){

    assert(equation_coef != nullptr);
    assert(roots_square != nullptr);
    assert(discriminant != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;

    double sqrt_discr = sqrt(*discriminant);

    double x1 = (-b+sqrt_discr)/(2*a);
    double x2 = (-b-sqrt_discr)/(2*a);

    roots_square->x1 = x1;
    roots_square->x2 = x2;
}

Type_of_equation type_of_equation_function (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    if (compare_double_with_zero(a)){

        if (compare_double_with_zero(b) && compare_double_with_zero(c)){

            return NOT_A_EQUATION;
        }

        return LINEAR_EQUATION;
    }

    return QUADRATIC_EQUATION;
}

Count_of_roots solving_equation (struct square_equation_coefs *equation_coef, enum Type_of_equation const *type_of_input_equation, struct roots_square_equation *roots_square){

    assert(equation_coef != nullptr);
    assert(roots_square != nullptr);
    assert(type_of_input_equation != nullptr);

    switch (*type_of_input_equation){

        case NOT_A_EQUATION:{

            return INFINITI;
        }

        case LINEAR_EQUATION:{

            double b = equation_coef->b;

            if (compare_double_with_zero(b)){

                return NO_ROOTS;

            }

            else{

                solving_linear_equation (equation_coef, roots_square);

                return ONE_ROOT;

            }

        }

        case QUADRATIC_EQUATION:{

            double discriminant = 0;

            discriminant = Discriminant_calculation (equation_coef);

            if (compare_double_with_zero(discriminant)){

                solve_equation_with_zero_discriminant (equation_coef, roots_square);//rename func

                return ONE_ROOT;

            }

            else if (discriminant > 0){

                solve_equation_with_positive_discriminant (equation_coef, roots_square, &discriminant);//rename func
                return TWO_ROOT;

            }

            return NO_ROOTS;
        }

        default:{

            return NO_ROOTS;
        }
    }
}

double Discriminant_calculation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    return b*b-4*a*c;
}

bool compare_double_with_zero (double param){

    static double EPSILON = 1e-10;

    if (fabs(param) < EPSILON){

        return true;
    }

    return false;
}
