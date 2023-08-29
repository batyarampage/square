#include "enter_coef.h"
#include <stdio.h>
#include <TXLib.h>

///Макрос предназначенный для упрощения вызова функции ввода коэффициентов квадратного уравнения
#define COEF_CORRECT_INPUT(coef_symbol) get_correct_input(&(equation_coef->coef_symbol), #coef_symbol)

void get_coefs (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    greetings_user ();


    check_readiness_to_enter_coef ();
    COEF_CORRECT_INPUT(a);
    COEF_CORRECT_INPUT(b);
    COEF_CORRECT_INPUT(c);
}

void check_readiness_to_enter_coef (){

    int ch = 0;
    ch = getchar ();

    while (ch != '\n'){

        while (getchar() != '\n');  // copypaste, into func
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        ch = getchar ();
    }
}

void get_correct_input (double *inputParam, const char *curr_input_param){

    assert(inputParam != nullptr);

    ask_enter_coef (curr_input_param);

    int symbol = 0;

    symbol = getchar ();

    while (true){   // asks to enter coefficient again if '\n' was entered, while (symbol != EOF)

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

    while ((!scanf("%lg", inputParam)) || (getchar () != '\n')){//проверка на EOF

        printf("Некоректный ввод, повторите еще раз\n");
        while (getchar () != '\n');

        ask_enter_coef (curr_input_param);
    }
}

void ask_enter_coef (const char *coef){  // fix prototype

    printf("Введите коэффициент %c = ", *coef);
}

void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");
}
