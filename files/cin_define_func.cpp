#include "cin_define.h"

/// Функция, вызываемая в main, которая связана со всем вводом коэффицентов квадратного уравнения
/*!

    Инициализируется переменная ch, чтобы передав адрес ch в charchecker, можно было контролировать корректный ввод

    \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
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


/// Функция, которая контролирует нажатие ENTER, для перехода к вводу коэффциентов

/*!
    \param ch - указатель, для контроля ввода пробела

*/
void charchecker (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        *ch = getchar ();
    }
}

/// Функция ввода коэффциента a
void a_coef_input (struct square_equation_coefs *equation_coef){

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

    while ((!(scanf("%lg", inputParam))) || ((cin_is_normal ()))){

        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
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

///Функция для проверки, что пользователь помимо коэффициентов ввел еще посторонние символы в буфер ввода
bool cin_is_normal (){

    if (getchar () != '\n'){

        return true;
    }

    return false;

}


