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

    printf("������������ = 0, ������� �����������, ��� ����� %g\n", -b/(2*a));

}

void infinity_sollutions (){

    printf("��������� ����� ����������� ���������� �������");

}

void zero_A_one_sollution (double b, double c){

    printf("��������� � a = 0, ������� �����������, ��� ����� %g\n", -b/c);

}

void no_sollution (){

    printf("��������� �� ����� ������� �� ��������� �������������� �����");

}

void two_roots_calculate (double a, double b, double Discriminant){

    double sqrt_Discriminant = sqrt(Discriminant);

    double x1 = (-b+sqrt_Discriminant)/(2*a);
    double x2 = (-b-sqrt_Discriminant)/(2*a);

    printf("��������� ����� 2 �������\n");
    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

}

void sollution_is_zero (){

    printf("������� �����������, ��� ����� 0");
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
double a,b,c;
printf("%s","������� ������������ a, b, c\n");
scanf("%lf%lf%lf", &a,&b,&c);
solver(a,b,c);
return 0;
}
