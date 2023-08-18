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

void infinity_sollutions ();

double Discriminant_calculation (double a, double b, double c);

void no_roots ();

void one_root (double a, double b);

void two_roots(double a, double b, double discriminant);

void linear_equation (double b, double c);


int main (){

    double a = 0;
    double b = 0;
    double c = 0;

    printf ("введите коэффициенты a, b, c\n");

    scanf ("%lf%lf%lf", &a,&b,&c);
    printf ("\n");

    solver (a,b,c);

    return 0;
}





void infinity_sollutions (){

    printf("Уравнение имеет бесконечное количество решений");

}

void no_roots (){

    printf("уравнение не имеет решений на множестве действительных чисел");

}

void one_root (double a, double b){

    printf("дискриминант = 0, решение единственно, оно равно %g\n", -b/(2*a));

}

void two_roots(double a, double b, double discriminant){

    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b+sqrt_discriminant)/(2*a);
    double x2 = (-b-sqrt_discriminant)/(2*a);

    printf("уравнение имеет 2 решения\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}

void linear_equation (double b, double c){

    if (fabs(b) < EPSILON){

        printf("решений нет");

    }

    else{

        printf("уравнение линейное, его решение = %g\n", -b/c);

    }

}

double Discriminant_calculation (double a, double b, double c){

    return b*b-4*a*c;

}

Square_equations_roots Square_root_counter (double a, double b, double c, double *discriminant){

    if (fabs(a) < EPSILON){   // linear equation

        if ((fabs(b) < EPSILON) && (fabs(c) < EPSILON)){

            return INFINITY_SOLUTIONS;
        }

        return LINEAR_EQUATION;

    }

    else{

        *discriminant = Discriminant_calculation (a, b, c);

        if (fabs(*discriminant) < EPSILON){

            return ONE_ROOT;

        }

        else if (*discriminant > 0){

            return TWO_ROOTS;

        }

        return NO_ROOTS;

    }
}



void solver (double a, double b, double c){

    double discriminant = 0;
    Square_equations_roots Root_counter = Square_root_counter (a, b, c, &discriminant);

    switch (Root_counter){

        case INFINITY_SOLUTIONS:{

            infinity_sollutions ();
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



