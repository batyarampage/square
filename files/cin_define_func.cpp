#include "cin_define.h"

/// �������, ���������� � main, ������� ������� �� ���� ������ ������������ ����������� ���������
/*!

    ���������������� ���������� ch, ����� ������� ����� ch � charchecker, ����� ���� �������������� ���������� ����

    \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/

void cin_coef (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    int ch = 0;

    greetings_user ();
    charchecker (&ch);
    a_coef_input (equation_coef);
    b_coef_input (equation_coef);
    c_coef_input (equation_coef);

}


/// �������, ������� ������������ ������� ENTER, ��� �������� � ����� ������������

/*!
    \param ch - ���������, ��� �������� ����� �������

*/
void charchecker (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("������������ ����, ���������� ��� ��� ������ ������\n");
        *ch = getchar ();
    }
}

/// ������� ����� ����������� a
void a_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'a';
    get_correct_input (&(equation_coef->a), curr_coef);

}


/// ������� ����� ����������� b
void b_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'b';
    get_correct_input (&(equation_coef->b), curr_coef);

}


/// ������� ����� ����������� c
void c_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != NULL);

    char curr_coef = 'c';

    get_correct_input (&(equation_coef->c), curr_coef);

}


/// �������, ������� ��������� ������������ ����� ������������ ����������� ���������
/*!

    \param inputParam - ��������� �� ������ ��������� equation_coef, ���������� �������������� ����������� ���������
    \param curr_input_param - ������� �������� ����������� (a, b, c)
    \warning ������ ������� �� ����� ���������, ��� ������������ ���� ������ ENTER, ��� �������� � ������������ ���������

*/
void get_correct_input (double *inputParam, char curr_input_param){

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

///�������, ������� ���������� ������������, ����� ��������� �������
void print_enter_coef (char coef){

    printf("������� ����������� %c = ", coef);
}

///����������� ������������
void greetings_user (){

    printf("������, ��� ��������� ������ ���������� ���������, ����� ������� ������������ ������� ������\n");
    printf("����� ������ ������ ������� �����������, ������� Enter");

}
