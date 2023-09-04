#ifndef printer_func
#define printer_func

#include "struct_of_square_equation.h"
#include "enumerate.h"


///Основная функция для вывода решения квадратного уравнения
/*!
 Вызывается в main для вывода корней квадратного уравнения
 \param type_of_input_equation - константный указатель на тип уравнения
 \param roots_square - константный указатель на корни квадратного уравнения
 \param count_of_roots - константный указатель на количество корней уравнения
*/
void printer (Type_of_equation type_of_input_equation, const struct roots_square_equation *roots_square, Count_of_roots count_of_roots);

///Функция для вывода сообщения о бесконечности решений
void print_infinity_solution ();


///Функция для вывода сообщения о решении линейного уравнения (подслучая квадратного)
void print_linear_equation (const struct roots_square_equation *roots_square);


///Функция для вывода сообщения о решении квадратного уравнения с нулевым дискриминантом
void print_zero_discriminant (const struct roots_square_equation *roots_square);


///Функция для вывода сообщения об отрицательности дискриминанта квадратного уравнения
void print_negative_discriminant ();

///Функция для вывода сообщения об отсутствии решений
void print_linear_equation_zero ();


///Функция для вывода сообщения о решении квадратного уравнения с положительным дискриминантом
void print_positive_discriminant (const struct roots_square_equation *roots_square);


///Функция для вывода сообщения о том, что EOF в потоке ввода
void print_eof_in_stdio ();

#endif
