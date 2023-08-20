#include <math.h>
#include <stdio.h>
#include <TXLib.h>


const double EPSILON = 1e-100;



enum Square_equations_roots{

   INFINITY_SOLUTIONS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
   LINEAR_EQUATION


};

void solver (double a, double b, double c);

Square_equations_roots Square_root_counter (double a, double b, double c, double *discriminant);

void infinity_solutions ();

double Discriminant_calculation (double a, double b, double c);

void no_roots ();

void one_root (double a, double b);

void two_roots (double a, double b, double discriminant);

void linear_equation (double b, double c);

bool compare_double (double param);

void a_coef (double *a);

void b_coef (double *b);

void c_coef (double *c);

void cin_coef (int *ch, double *a, double *b, double *c);

void charchecker (int *ch);


int main (){

    double a = 0;
    double b = 0;
    double c = 0;
    int ch = 0;

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

    if (compare_double(b)){

        printf("Решений нет\n");

    }

    else{

        printf("уравнение линейное, его решение = %g\n", -b/c);

    }

}

double Discriminant_calculation (double a, double b, double c){

    return b*b-4*a*c;

}

Square_equations_roots Square_root_counter (double a, double b, double c, double *discriminant){

    if (compare_double(a)){   // linear equation

        if ((compare_double(b)) && (compare_double(c))){

            return INFINITY_SOLUTIONS;
        }

        return LINEAR_EQUATION;

    }

    else{

        *discriminant = Discriminant_calculation (a, b, c);

        if (compare_double(*discriminant)){

            return ONE_ROOT;

        }

        else if (*discriminant > 0){

            return TWO_ROOTS;

        }

        return NO_ROOTS;

    }
}

bool compare_double (double param){

    if (fabs(param) < EPSILON){

        return true;

    }

    return false;
}


void cin_coef (int *ch, double *a, double *b, double *c){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");

    charchecker (ch);
    a_coef (a);
    b_coef (b);
    c_coef (c);

}

void charchecker (int *ch){

    *ch = getchar ();
    if (!(*ch == '\n')){
        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз\n");

        charchecker (ch);

    }
}

void a_coef (double *a){

    printf("Введите коэффициент a = ");

    if (!(scanf("%lf", a))){
        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
        a_coef (a);
    }
}

void b_coef (double *b){

    printf("Введите коэффициент b = ");

    if (!(scanf("%lf", b))){
        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
        b_coef (b);
    }
}

void c_coef (double *c){

    printf("Введите коэффициент с = ");

    if (!(scanf("%lf", c))){
        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
        c_coef (c);
    }
}



void solver (double a, double b, double c){

    double discriminant = 0;
    Square_equations_roots Root_counter = Square_root_counter (a, b, c, &discriminant);

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



