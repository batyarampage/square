#include "cin_define.h"

void cin_coef (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    int ch = 0;

    greetings_user ();
    charchecker (&ch);
    a_coef_input (equation_coef);
    b_coef_input (equation_coef);
    c_coef_input (equation_coef);

}

void charchecker (int *ch){

    assert (ch != nullptr);
    *ch = getchar ();

    while (!(*ch == '\n')){

        while (getchar() != '\n');
        printf("некорректный ввод, попробуйте еще раз ввести пробел\n");
        *ch = getchar ();
    }
}

void a_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'a';
    get_correct_input (&(equation_coef->a), curr_coef);

}

void b_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'b';
    get_correct_input (&(equation_coef->b), curr_coef);

}

void c_coef_input (struct square_equation_coefs *equation_coef){

    assert(equation_coef != nullptr);

    char curr_coef = 'c';
    get_correct_input (&(equation_coef->c), curr_coef);

}

void get_correct_input (double *inputParam, char curr_input_param){

    assert(inputParam != nullptr);

    print_enter_coef (curr_input_param);

    while ((!(scanf("%lg", inputParam))) || ((cin_is_normal ()))){

        while (getchar () != '\n');
        printf("Некоректный ввод, повторите еще раз\n");
        print_enter_coef (curr_input_param);

    }
}

void print_enter_coef (char coef){

    printf("Введите коэффициент %c = ", coef);
}

void greetings_user (){

    printf("Привет, эта программа решает квадратное уравнение, После каждого коэффициента вводите пробел\n");
    printf("Когда будете готовы вводить коэффициеты, нажмите Enter");

}

bool cin_is_normal (){

    if (getchar () != '\n'){

        return true;
    }

    return false;

}


