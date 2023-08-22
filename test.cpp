#include <math.h>
#include <stdio.h>
#include <TXLib.h>


enum Square_solution_cases{ // solution_cases

   INFINITY_SOLUTIONS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
   LINEAR_EQUATION
};

struct Square_equation_coefs{

    double a = 0;
    double b = 0;
    double c = 0;
};


void solver (struct Square_equation_coefs *equation_coef);

Square_solution_cases Square_solution_cases_func (struct Square_equation_coefs *equation_coef, double *discriminant);

void infinity_solutions ();

double Discriminant_calculation (struct Square_equation_coefs *equation_coef);

void no_roots ();

void one_root (struct Square_equation_coefs *equation_coef);

void two_roots (struct Square_equation_coefs *equation_coef, double discriminant);

void linear_equation (struct Square_equation_coefs *equation_coef);

bool compare_double_with_zero (double param);

void a_coef_input (struct Square_equation_coefs *equation_coef);

void b_coef_input (struct Square_equation_coefs *equation_coef);

void c_coef_input (struct Square_equation_coefs *equation_coef);

void cin_coef (int *ch, struct Square_equation_coefs *equation_coef);

void charchecker (int *ch);

void get_correct_input (double *inputParam, char curr_input_param);

void print_enter_coef (char coef);

void greetings_user ();

bool cin_is_normal ();

int comparator_double (double num1, double num2);



int main (){

    int ch = 0; // char

    struct Square_equation_coefs equation_coef;

    cin_coef (&ch, &equation_coef);

    solver (&equation_coef);

    return 0;
}


void infinity_solutions (){

    printf("Уравнение имеет бесконечное количество решений\n");

}

void no_roots (){

    printf("Уравнение не имеет решений на множестве действительных чисел\n");

}

void one_root (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double a = equation_coef->a;

    double solution = -b/(2*a);

    printf("дискриминант = 0, решение единственно, оно равно %g\n", solution);

}

void two_roots (struct Square_equation_coefs *equation_coef, double discriminant){

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

void linear_equation (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double b = equation_coef->b;
    double c = equation_coef->c;
    double solution = -c/b;

    printf("уравнение линейное, его решение = %g\n", solution);
}

double Discriminant_calculation (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    double a = equation_coef->a;
    double b = equation_coef->b;
    double c = equation_coef->c;

    return b*b-4*a*c;

}

Square_solution_cases Square_solution_cases_func (struct Square_equation_coefs *equation_coef, double *discriminant){

    assert(discriminant != nullptr);
    assert(equation_coef != nullptr);

    if (compare_double_with_zero(equation_coef->a)){   // linear equation

        if ((compare_double_with_zero(equation_coef->b)) && (compare_double_with_zero(equation_coef->c))){

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

void cin_coef (int *ch, struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);
    assert(ch != nullptr);

    greetings_user ();
    charchecker (ch);
    a_coef_input (equation_coef);
    b_coef_input (equation_coef);
    c_coef_input (equation_coef);

}

void charchecker (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        *ch = getchar ();
    }
}

void a_coef_input (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'a';
    get_correct_input (&(equation_coef->a), curr_coef);

}

void b_coef_input (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'b';
    get_correct_input (&(equation_coef->b), curr_coef);

}

void c_coef_input (struct Square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'c';
    get_correct_input (&(equation_coef->c), curr_coef);

}

void get_correct_input (double *inputParam, char curr_input_param){

    assert(inputParam != nullptr);

    print_enter_coef (curr_input_param);

    while ((!(scanf("%lg", inputParam))) || ((cin_is_normal ()  ))){

        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
        print_enter_coef (curr_input_param);

    }
}

void print_enter_coef (char coef){

    printf("Введите коэффициент %c = ", coef);
}

void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");

}

bool cin_is_normal (){

    if (getchar () != '\n'){

        return true;
    }

    return false;

}

int comparator_double (double num1, double num2){

    static double EPSILON = 1e-10;

    if (num1-num2 > EPSILON){

        return 1;

    }

    else if (num2-num1 > EPSILON){

        return 2;

    }

    return 0;

}

/*int compare_double (double num1, double num2){

    static double EPSILON = 1e-10;

    if ((num1-num2) > EPSILON){

        return num1g
    }
}*/

void solver (struct Square_equation_coefs *equation_coef){

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
