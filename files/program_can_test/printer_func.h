#ifndef printer_func
#define printer_func

#include "struct_of_square_equation.h"
#include "enumerate.h"


///ќсновна€ функци€ дл€ вывода решени€ квадратного уравнени€
/*!
 ¬ызываетс€ в main дл€ вывода корней квадратного уравнени€
 \param type_of_input_equation - константный указатель на тип уравнени€
 \param roots_square - константный указатель на корни квадратного уравнени€
 \param count_of_roots - константный указатель на количество корней уравнени€
*/
void printer (Type_of_equation const *type_of_input_equation, struct roots_square_equation const *roots_square, Count_of_roots const *count_of_roots);


///‘ункци€ дл€ вывода сообщени€ о бесконечности решений
void print_infinity_solution ();


///‘ункци€ дл€ вывода сообщени€ о решении линейного уравнени€ (подслуча€ квадратного)
void print_linear_equation (struct roots_square_equation const *roots_square);


///‘ункци€ дл€ вывода сообщени€ о решении квадратного уравнени€ с нулевым дискриминантом
void print_zero_discriminant (struct roots_square_equation const *roots_square);


///‘ункци€ дл€ вывода сообщени€ об отрицательности дискриминанта квадратного уравнени€
void print_negative_discriminant ();

///‘ункци€ дл€ вывода сообщени€ об отсутствии решений
void print_linear_equation_zero ();

///‘ункци€ дл€ вывода сообщени€ о решении квадратного уравнени€ с положительным дискриминантом
void print_positive_discriminant (struct roots_square_equation const *roots_square);

#endif
