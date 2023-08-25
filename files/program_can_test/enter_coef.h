#ifndef enter_coef
#define enter_coef

#include "enumerate.h"
#include "struct_of_square_equation.h"

/// �������, ���������� � main, ������� ������� �� ���� ������ ������������ ����������� ���������
/*!

    ���������������� ���������� ch, ����� ������� ����� ch � charchecker, ����� ���� �������������� ���������� ����

    \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/
void cin_coef (struct square_equation_coefs *equation_coef);



void check_readiness_to_enter_coef (int *ch);

void a_coef_input (struct square_equation_coefs *equation_coef);

void b_coef_input (struct square_equation_coefs *equation_coef);

void c_coef_input (struct square_equation_coefs *equation_coef);

void get_correct_input (double *inputParam, char curr_input_param);

void print_enter_coef (char coef);

void greetings_user ();

#endif
