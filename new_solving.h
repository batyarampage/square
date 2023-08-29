#ifndef new_solving
#define new_solivng

#include "enumerate.h"
#include "struct_of_square_equation.h"


///Функция, которая решает линейное уравнение
/*!
Решает подслучай квадратного уравнения - линейное уравнение
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
 \param roots_square - указатель на структуру с корнями квадратного уравнения
*/
void solving_linear_equation (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);


///Функция для решения квадратного уравнения с нульвым дискриминантом
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
 \param roots_square - указатель на структуру с корнями квадратного уравнения

*/
void solve_equation_with_zero_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);


///Функция для решения уравнения с положительным дискриминантом
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
 \param roots_square - указатель на структуру с корнями квадратного уравнения
 \param discriminant - указатель на подсчитанный дискриминант
*/
void solve_equation_with_positive_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square, double *discriminant);


///Функция для определения типа уравнения
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
*/
Type_of_equation type_of_equation_function (struct square_equation_coefs *equation_coef);


///Функция для решения и подсчета количества корней уравнения
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
 \param roots_square - указатель на структуру с корнями квадратного уравнения
 \param type_of_input_equation - указатель на тип уравнения
*/
Count_of_roots solving_equation (struct square_equation_coefs *equation_coef, enum Type_of_equation type_of_input_equation, struct roots_square_equation *roots_square);


///Функция для подсчета дискриминанта квадратного уравнения
/*!
 \param equation_coef - указатель на структуру с коэффициентами квадратного уравнения
*/
double Discriminant_calculation (struct square_equation_coefs *equation_coef);

///Функция для сравнения дискриминанта с нулем
bool positive_comparator_discriminant (double parametr);

#endif
