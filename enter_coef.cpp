#include "enter_coef.h"
#include <stdio.h>
#include <TXLib.h>

///Макрос предназначенный для упрощения вызова функции ввода коэффициентов квадратного уравнения
#define COEF_CORRECT_INPUT(coef_symbol) get_correct_input(&(equation_coef->coef_symbol), #coef_symbol)

void get_coefs (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    int ch = 0;

    greetings_user ();
    check_readiness_to_enter_coef (&ch);
    COEF_CORRECT_INPUT(a);
    COEF_CORRECT_INPUT(b);
    COEF_CORRECT_INPUT(c);
}

void check_readiness_to_enter_coef (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        *ch = getchar ();
    }
}

void get_correct_input (double *inputParam, const char * curr_input_param){

    assert(inputParam != nullptr);

    print_enter_coef (curr_input_param);

    int symbol = 0;

    symbol = getchar ();

    while (true){

        if (symbol == '\n'){

            printf("Некоректный ввод, повторите еще раз\n");
            print_enter_coef (curr_input_param);
            symbol = getchar ();
        }

        else{

            ungetc (symbol, stdin);
            break;
        }
    }

    while ((!scanf("%lg", inputParam)) || (getchar () != '\n')){

        printf("Некоректный ввод, повторите еще раз\n");
        while (getchar () != '\n');

        print_enter_coef (curr_input_param);
    }
}

void print_enter_coef (const char * coef){

    printf("Введите коэффициент %c = ", *coef);
}

void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");
}
