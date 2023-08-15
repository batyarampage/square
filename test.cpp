#include <TXLib.h>
#include <stdio.h>
#include <math.h>
void solver (double a, double b, double c){
if ((a==0) && (b==0) && (c==0)){
    printf("%s", "бесконечно много решений");

}
else if(((b==0) && (c==0)) || ((a==0) && (c==0))){
    printf("%s","решение = 0");
}
else if (a==0){
    printf("решение = %f", b/c);
}
else{

    double Discriminant = b*b-4*a*c;
    if (Discriminant==0){
        printf("решение = %f", -b/(2*a));
    }
    else if (Discriminant > 0){
        double x1 = (-b+sqrt(Discriminant))/(2*a);
        double x2 = (-b-sqrt(Discriminant))/(2*a);
        printf("2 решения\n");
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
    }
    else{
        printf("нет решений");
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
