#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include <stddef.h>


enum Square_solution_cases{ // solution_cases

   INFINITY_SOLUTIONS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
   LINEAR_EQUATION
};

enum comparator_decrypt {

    FIRST_GREATER = 1,
    SECOND_GREATER,
    EQUAL
};

struct Square_equation_coefs{
    double a;
    double b;
    double c;
};

void solver (double a, double b, double c);

Square_solution_cases Square_solution_cases_func (double a, double b, double c, double *discriminant);

void infinity_solutions ();

double Discriminant_calculation (double a, double b, double c);

void no_roots ();

void one_root (double a, double b);

void two_roots (double a, double b, double discriminant);

void linear_equation (double b, double c);

bool compare_double_with_zero (double param);

void a_coef_input (double *a);

void b_coef_input (double *b);

void c_coef_input (double *c);

void cin_coef (int *ch, double *a, double *b, double *c);

void charchecker (int *ch);

void get_correct_input (double *inputParam, char curr_input_param);

void print_enter_coef (char coef);

void greetings_user ();

bool cin_is_normal ();



int main (){

    double a = 0;
    double b = 0;
    double c = 0;
    int ch = 0; // char

    cin_coef (&ch, &a, &b, &c);

    solver (a,b,c);

    return 0;
}


void infinity_solutions (){

    printf("Уравнение имеет бесконечное количество решений\n");

}

void no_roots (){

    printf("Уравнение не имеет решений на множестве действительных чисел\n");

}

void one_root (double a, double b){

    printf("дискриминант = 0, решение единственно, оно равно %g\n", -b/(2*a));

}

void two_roots (double a, double b, double discriminant){

    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b+sqrt_discriminant)/(2*a);
    double x2 = (-b-sqrt_discriminant)/(2*a);

    printf("уравнение имеет 2 решения\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}

void linear_equation (double b, double c){

    if (compare_double_with_zero(b)){

        printf("Решений нет\n");

    }

    else{

        printf("уравнение линейное, его решение = %g\n", -c/b);

    }

}

double Discriminant_calculation (double a, double b, double c){

    return b*b-4*a*c;

}

Square_solution_cases Square_solution_cases_func (double a, double b, double c, double *discriminant){

    assert(discriminant != nullptr);


    if (compare_double_with_zero(a)){   // linear equation

        if ((compare_double_with_zero(b)) && (compare_double_with_zero(c))){

            return INFINITY_SOLUTIONS;
        }

        return LINEAR_EQUATION;

    }

    else{

        *discriminant = Discriminant_calculation (a, b, c);

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

/*
    int comparator(double var1, double var2)
    {
        static double EPSILON = 1e-7;

        double delta = var1 - var2;
        if (delta > 0)
        {
            return 1;
        }
        ...
    }
*/

void cin_coef (int *ch, double *a, double *b, double *c){

    greetings_user ();
    charchecker (ch);
    a_coef_input (a);
    b_coef_input (b);
    c_coef_input (c);

}

void charchecker (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();
    if (!(*ch == '\n')){
        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз\n");

        charchecker (ch);    // лучше через цикл

    }
}

void a_coef_input (double *a){

    assert (a != nullptr);
    char curr_coef = 'a';
    get_correct_input (a, curr_coef);

}

void b_coef_input (double *b){

    assert(b != nullptr);
    char curr_coef = 'b';
    get_correct_input (b, curr_coef);

}

void c_coef_input (double *c){

    assert (c != nullptr);
    char curr_coef = 'c';
    get_correct_input (c, curr_coef);

}

void get_correct_input (double *inputParam, char curr_input_param){

    assert(inputParam != nullptr);
    print_enter_coef (curr_input_param);
    while ((!(scanf("%lg", inputParam))) || (cin_is_normal ())){

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

    while (getchar () != '\n'){

        return true;
    }

    return false;

}

/*int compare_double (double num1, double num2){

    static double EPSILON = 1e-10;

    if ((num1-num2) > EPSILON){

        return num1g
    }
}*/

void solver (double a, double b, double c){

    double discriminant = 0;
    Square_solution_cases Root_counter = Square_solution_cases_func (a, b, c, &discriminant);

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

            one_root (a, b);
            break;

        }

        case TWO_ROOTS:{

            two_roots (a, b, discriminant);
            break;
        }

        case LINEAR_EQUATION:{

            linear_equation (b, c);
            break;

        }

        default:{

            break;

        }
    }
}
