#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define epsilon 1e-10

void solver (double a, double b, double c);

int Square_root_counter (double a, double b, double c);

double Discriminant_calculation (double a, double b, double c);

double zero_Discriminant (double a, double b);

void infinity_sollutions ();

double zero_A_one_sollution (double b, double c);



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

            infinity_sollutions ();

        }

        case 1:{

            zero_A_one_sollution (b, c);

        }

        case 2:{

            double Discriminant = Discriminant_calculation (a, b, c);

            if (fabs(Discriminant) < epsilon){

                zero_Discriminant (a, b);

            }



        }

    }

}


int main (){
double a,b,c;
printf("%s","введите коэффициенты a, b, c\n");
scanf("%lf%lf%lf", &a,&b,&c);
solver(a,b,c);
return 0;
}
