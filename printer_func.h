#ifndef printer_func
#define printer_func

#include "struct_of_square_equation.h"
#include "enumerate.h"


///�������� ������� ��� ������ ������� ����������� ���������
/*!
 ���������� � main ��� ������ ������ ����������� ���������
 \param type_of_input_equation - ����������� ��������� �� ��� ���������
 \param roots_square - ����������� ��������� �� ����� ����������� ���������
 \param count_of_roots - ����������� ��������� �� ���������� ������ ���������
*/
void printer (Type_of_equation const *type_of_input_equation, struct roots_square_equation const *roots_square, Count_of_roots const *count_of_roots);


///������� ��� ������ ��������� � ������������� �������
void print_infinity_solution ();


///������� ��� ������ ��������� � ������� ��������� ��������� (��������� �����������)
void print_linear_equation (struct roots_square_equation const *roots_square);


///������� ��� ������ ��������� � ������� ����������� ��������� � ������� ��������������
void print_zero_discriminant (struct roots_square_equation const *roots_square);


///������� ��� ������ ��������� �� ��������������� ������������� ����������� ���������
void print_negative_discriminant ();

///������� ��� ������ ��������� �� ���������� �������
void print_linear_equation_zero ();

///������� ��� ������ ��������� � ������� ����������� ��������� � ������������� ��������������
void print_positive_discriminant (struct roots_square_equation const *roots_square);

#endif
