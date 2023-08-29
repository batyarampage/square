#ifndef enter_coef
#define enter_coef

#include "enumerate.h"
#include "struct_of_square_equation.h"

/// Функция, вызываемая в main, которая связана со всем вводом коэффицентов квадратного уравнения
/*!

    Инициализируется переменная ch, чтобы передав адрес ch в check_readiness_to_enter_coef, можно было контролировать корректный ввод

    \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
*/
bool get_coefs (struct square_equation_coefs *equation_coef);


/// Функция, которая контролирует нажатие ENTER, для перехода к вводу коэффциентов
/*!
    \param ch - указатель, для контроля ввода пробела
*/
bool check_readiness_to_enter_coef ();


/// Функция, которая проверяет корректность ввода коэффицентов квадратного уравнения
/*!

    \param inputParam - указатель на модуль структуры equation_coef, являющейся коэффициентами квадратного уравнения
    \param curr_input_param - текущий вводимый коэффициент (a, b, c)

*/
bool get_correct_input (double *inputParam, const char * curr_input_param);


///Функция, которая показывает пользователю, какой коэффиент вводить
/*!
 \param coef - вводимый коэффициент
*/
void ask_enter_coef (const char *coef);


///приветствие пользователя
void greetings_user ();

#endif
