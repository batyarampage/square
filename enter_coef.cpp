#include "enter_coef.h"
#include <stdio.h>
#include <TXLib.h>
#include "func_tools.h"

///Макрос предназначенный для упрощения вызова функции ввода коэффициентов квадратного уравнения
#define COEF_CORRECT_INPUT(coef_symbol) get_correct_input(&(equation_coef->coef_symbol), #coef_symbol)

bool get_coefs (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    greetings_user ();

    if ((check_readiness_to_enter_coef ()) && (COEF_CORRECT_INPUT(a)) && (COEF_CORRECT_INPUT(b)) && (COEF_CORRECT_INPUT(c))){

        return true;
    }
    return false;
}

bool check_readiness_to_enter_coef (){

    int ch = 0;
    ch = getchar ();

    while (ch != '\n'){

        if (ch == EOF){

            return false;
        }

        cleaner_stdio ();
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        ch = getchar ();
    }

    return true;
}

bool get_correct_input (double *inputParam, const char *curr_input_param){

    assert(inputParam != nullptr);

    ask_enter_coef (curr_input_param);

    int symbol = getchar ();

    while (symbol != EOF){

        if (symbol == '\n'){

            printf("Некоректный ввод, повторите еще раз\n");

            ask_enter_coef (curr_input_param);

            symbol = getchar ();
        }

        else{

            ungetc (symbol, stdin);
            break;
        }
    }



    if (symbol == EOF){

        return false;
    }

    while ((!scanf("%lg", inputParam)) || (symbol = getchar () != '\n')){

        if (symbol == EOF){

            return false;
        }
        printf("Некоректный ввод, повторите еще раз\n");

        cleaner_stdio ();

        ask_enter_coef (curr_input_param);
    }
    return true;
}

void ask_enter_coef (const char *coef){

    printf("Введите коэффициент %c = ", *coef);
}

void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");

    while (getchar() == EOF);
}
