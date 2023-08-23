#include "calculation_square_equation.h"


///Подслучай, если квадратное уравнение имеет бесконечное количество корней

/*!
 Эту функцию вызывает case INFINITY_SOLUTIONS, расположенный в solver
*/
void infinity_solutions (){

    printf("Уравнение имеет бесконечное количество решений\n");

}


///Подслучай, если квадратное уравнение не имеет решений

/*!
 Эту функцию вызывает case NO_ROOTS, расположенный в solver
*/
void no_roots (){

    printf("Уравнение не имеет решений на множестве действительных чисел\n");

}


///Подслучай, если у квадратного уравнения дискриминант = 0

/*!
 Эту функцию вызывает case ONE_ROOT, расположенный в solver

 \param equation_coef - указатель на структуру из корней квадратного уравнения
*/
void one_root (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;

    double solution = -b/(2*a);

    if (compare_double_with_zero(solution)){

        printf("дискриминант = 0, решение единственно, оно равно 0");

    }

    else{

        printf("дискриминант = 0, решение единственно, оно равно %g\n", solution);

    }
}

///Подслучай, когда у квадратного уравнения дискриминант > 0

/*!
 Эту функцию вызывает case TWO_ROOTS, расположенный в solver

*/
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


/// Подслучай, когда квадратное уравнение - линейное, и подслучай отсутствия решений см. описание функции Square_solution_cases_func
void linear_equation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double c = equation_coef->c;



    if (compare_double_with_zero(b)){

        printf("Уравнение не имеет решений");
    }

    else{

        double solution = -c/b;

        if (compare_double_with_zero(solution)){

            printf("уравнение линейное, его решение = 0");

        }

        else{

            printf("уравнение линейное, его решение = %g\n", solution);
        }
    }
}

/// Подсчет дискриминанта квадратного уравнения
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
*/
double Discriminant_calculation (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    return b*b-4*a*c;

}




/// Функция, которая определяет количество корней

/*!

Возвращает количество корней, или подслучай линейного уравнения, если введеные коэффциенты представляют собой случай линейного уравнения
\param equation_coef - указатель на структуру, содержащая коэффиценты квадратного уравнения
\param discriminant - указатель на discriminant, чтобы посчитать его, если мы зайдем в else

Некоторые уточнения по коду

\code
    Square_solution_cases Square_solution_cases_func (struct square_equation_coefs *equation_coef, double *discriminant){

    if (compare_double_with_zero(a)){   // подслучай линейного уравнения, или бесконечности решений, или отсутствия решений

        if ((compare_double_with_zero(b)) && (compare_double_with_zero(c))){

            return INFINITY_SOLUTIONS; // бесконечность решений
        }

        return LINEAR_EQUATION; // сюда мы спустились, т.к. какой-то коэффицент не ноль, нужно проверить случай нулевого коэффициента b
                                // и НЕнулевого c, это проверяется в функции linear_equation

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






///Функция сравнения числа с плавующей точкой с нулем

/*!
 Сравнивает число типа double с нулем с точностью EPSILON
 \param param - входное число с плавующей точкой, которое нужно сравнить с нулем

*/
bool compare_double_with_zero (double param){

    static double EPSILON = 1e-20;

    if (fabs(param) < EPSILON){

        return true;

    }

    return false;
}



///Основная функция решения квадратного уравнения, вызываемая в main
/*!
С ней связаны все функции, расположенные в файле calculation_square_equation.cpp

\param  equation_coef - является указателем на структуру коэффициентов a,b,c квадратного уравнения

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
