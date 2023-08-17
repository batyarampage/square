#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define epsilon 1e-10


void solver (double a, double b, double c);

int Square_root_counter (double a, double b, double c);

double Discriminant_calculation (double a, double b, double c);

void zero_Discriminant (double a, double b);

void infinity_sollutions ();

void zero_A_one_sollution (double b, double c);

void no_sollution ();

void two_roots_calculate (double a, double b, double Discriminant);

void sollution_is_zero ();




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


int Square_root_counter (double a, double b, double c){

    if ((fabs(a) < epsilon) && (fabs(b) < epsilon) && (fabs(c) < epsilon)){
        return 3;
    }

    else if (((fabs(b) < epsilon) && (fabs(c) < epsilon)) || ((fabs(a) < epsilon) && (fabs(c) < epsilon))){
        return 0;
    }

    else if (fabs(a) < epsilon){
        return 1;
    }

    else{
        return 2;
    }


}



void solver (double a, double b, double c){

    int Root_counter = Square_root_counter (a, b, c);

    switch(Root_counter){

        case 0:{

            sollution_is_zero ();
            break;

        }

        case 1:{

            zero_A_one_sollution (b, c);

        }

        case 2:{

            double Discriminant = Discriminant_calculation (a, b, c);

            if (fabs(Discriminant) < epsilon){

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

        case 3:{

            infinity_sollutions ();
            break;

        }

        default:{

            break;

        }



    }



}


int main (){

    double a = 0;
    double b = 0;
    double c = 0;

    printf("введите коэффициенты a, b, c\n");

    scanf("%lf%lf%lf", &a,&b,&c);
    printf("\n");

    solver(a,b,c);

    return 0;
}
