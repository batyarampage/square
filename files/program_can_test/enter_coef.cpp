#include "enter_coef.h"
#include <stdio.h>
#include <TXLib.h>
#include <assert.h>



void cin_coef (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    int ch = 0;

    greetings_user ();
    check_readiness_to_enter_coef (&ch);
    a_coef_input (equation_coef);//get_correct_input(&(equation_coef->a), 'a') указатель на поле структуры и передавать char сразу же
    b_coef_input (equation_coef);//get_correct_input(&(equation_coef->b), 'b') // define
    c_coef_input (equation_coef);

    /*
    a
    */

}


/// Функция, которая контролирует нажатие ENTER, для перехода к вводу коэффциентов

/*!
    \param ch - указатель, для контроля ввода пробела

*/
void check_readiness_to_enter_coef (int *ch){//rename check_readiness_to_enter_coef

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        *ch = getchar ();
    }
}

/// Функция ввода коэффциента a
void a_coef_input (struct square_equation_coefs *equation_coef){//указатель на поле структуры

    assert(equation_coef != nullptr);

    char curr_coef = 'a';
    get_correct_input (&(equation_coef->a), curr_coef);

}


/// Функция ввода коэффциента b
void b_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'b';
    get_correct_input (&(equation_coef->b), curr_coef);

}


/// Функция ввода коэффциента c
void c_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'c';

    get_correct_input (&(equation_coef->c), curr_coef);

}


/// Функция, которая проверяет корректность ввода коэффицентов квадратного уравнения
/*!

    \param inputParam - указатель на модуль структуры equation_coef, являющейся коэффициентами квадратного уравнения
    \param curr_input_param - текущий вводимый коэффициент (a, b, c)
    \warning Данная функция не может проверить, что пользователь ввел только ENTER, что приводит к зацикливанию программы

*/
void get_correct_input (double *inputParam, char curr_input_param){

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

///Функция, которая показывает пользователю, какой коэффиент вводить
void print_enter_coef (char coef){

    printf("Введите коэффициент %c = ", coef);
}

///приветствие пользователя
void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");

}
