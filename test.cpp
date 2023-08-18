#include <math.h>
#include <stdio.h>
#include <TXLib.h>


const double EPSILON = 1e-100;



enum Square_equations_roots{

   ANY_NUMBER_IS_SOLUTION = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
   LINEAR_EQUATION


};

void solver (double a, double b, double c);

Square_equations_roots Square_root_counter (double a, double b, double c, double *discriminant);

double Discriminant_calculation (double a, double b, double c);

void zero_Discriminant (double a, double b);

void infinity_sollutions ();

void zero_A_one_sollution (double b, double c);

void no_sollution ();

void two_roots_calculate (double a, double b, double Discriminant);

void sollution_is_zero ();


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




void zero_Discriminant (double a, double b){

    printf("ƒискриминант = 0, решение единственно, оно равно %g\n", -b/(2*a));

}

void infinity_sollutions (){

    printf("”равнение имеет бесконечное количество решений");

}

void zero_A_one_sollution (double b, double c){

    printf("уравнение с a = 0, решение единственно, оно равно %g\n", -b/c);

}

void no_sollution (){

    printf("уравнение не имеет решений на множестве действительных чисел");

}

void two_roots_calculate (double a, double b, double Discriminant){

    double sqrt_Discriminant = sqrt(Discriminant);

    double x1 = (-b+sqrt_Discriminant)/(2*a);
    double x2 = (-b-sqrt_Discriminant)/(2*a);

    printf("уравнение имеет 2 решени€\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}

void sollution_is_zero (){

    printf("решение единственно, оно равно 0");
}

double Discriminant_calculation (double a, double b, double c){

    return b*b-4*a*c;

}


Square_equations_roots Square_root_counter (double a, double b, double c, double *discriminant){

    if (fabs(a) < EPSILON){   // linear equation

        if ((fabs(b) < EPSILON) && (fabs(c) < EPSILON)){

            return ANY_NUMBER_IS_SOLUTION;
        }

        return LINEAR_EQUATION;

    }

    else{

        *discriminant = Discriminant_calculation (a, b, c);

        if (fabs(*discriminant) < 0){

            return ONE_ROOT;

        }

        else if (*discriminant > 0){

            return TWO_ROOTS;

        }

        return NO_ROOTS;

    }
}



void solver (double a, double b, double c){

    double discriminant = 0.0;
    Square_equations_roots Root_counter = Square_root_counter (a, b, c, &discriminant);

    switch (Root_counter){

        case ANY_NUMBER_IS_SOLUTION:{

            sollution_is_zero ();
            break;

        }

        case NO_ROOTS:{
            break;
        }

        case ONE_ROOT:{

            zero_A_one_sollution (b, c);
            break;

        }

        case TWO_ROOTS:{

            double Discriminant = Discriminant_calculation (a, b, c);

            if (fabs(Discriminant) < EPSILON){

                zero_Discriminant (a, b);
                break;

            }

            else if (Discriminant < 0){

                no_sollution ();
                break;

            }

            else{

                two_roots_calculate (a, b, Discriminant);
                break;

            }
        }

        case LINEAR_EQUATION:{

            infinity_sollutions ();
            break;

        }

        default:{

            break;

        }



    }



}



