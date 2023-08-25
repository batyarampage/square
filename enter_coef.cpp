#include "enter_coef.h"
#include <stdio.h>
#include <TXLib.h>
#include <assert.h>
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
        printf("������������ ����, ���������� ��� ��� ������ ������\n");
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

            printf("����������� ����, ��������� ��� ���\n");
            print_enter_coef (curr_input_param);
            symbol = getchar ();
        }

        else{

            ungetc (symbol, stdin);
            break;
        }
    }

    while ((!scanf("%lg", inputParam)) || (getchar () != '\n')){

        printf("����������� ����, ��������� ��� ���\n");
        while (getchar () != '\n');

        print_enter_coef (curr_input_param);

    }
}

void print_enter_coef (const char * coef){

    printf("������� ����������� %c = ", *coef);
}

void greetings_user (){

    printf("������, ��� ��������� ������ ���������� ���������, ����� ������� ������������ ������� ������\n");
    printf("����� ������ ������ ������� �����������, ������� Enter");

}
