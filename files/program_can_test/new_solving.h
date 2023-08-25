#ifndef new_solving
#define new_solivng

#include "enumerate.h"
#include "struct_of_square_equation.h"


///�������, ������� ������ �������� ���������
/*!
������ ��������� ����������� ��������� - �������� ���������
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
 \param roots_square - ��������� �� ��������� � ������� ����������� ���������
*/
void solving_linear_equation (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);


///������� ��� ������� ����������� ��������� � ������� ��������������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
 \param roots_square - ��������� �� ��������� � ������� ����������� ���������

*/
void solve_equation_with_zero_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square);


///������� ��� ������� ��������� � ������������� ��������������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
 \param roots_square - ��������� �� ��������� � ������� ����������� ���������
 \param discriminant - ��������� �� ������������ ������������
*/
void solve_equation_with_positive_discriminant (struct square_equation_coefs *equation_coef, struct roots_square_equation *roots_square, double *discriminant);


///������� ��� ����������� ���� ���������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/
Type_of_equation type_of_equation_function (struct square_equation_coefs *equation_coef);


///������� ��� ������� � �������� ���������� ������ ���������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
 \param roots_square - ��������� �� ��������� � ������� ����������� ���������
 \param type_of_input_equation - ��������� �� ��� ���������
*/
Count_of_roots solving_equation (struct square_equation_coefs *equation_coef, enum Type_of_equation const *type_of_input_equation, struct roots_square_equation *roots_square);


///������� ��� �������� ������������� ����������� ���������
/*!
 \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/
double Discriminant_calculation (struct square_equation_coefs *equation_coef);


///������� ��� ��������� double � ����� � ��������� EPSILON
bool compare_double_with_zero (double param);

#endif
