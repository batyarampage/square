#ifndef enter_coef
#define enter_coef

#include "enumerate.h"
#include "struct_of_square_equation.h"

/// �������, ���������� � main, ������� ������� �� ���� ������ ������������ ����������� ���������
/*!

    ���������������� ���������� ch, ����� ������� ����� ch � check_readiness_to_enter_coef, ����� ���� �������������� ���������� ����

    \param equation_coef - ��������� �� ��������� � �������������� ����������� ���������
*/
void get_coefs (struct square_equation_coefs *equation_coef);


/// �������, ������� ������������ ������� ENTER, ��� �������� � ����� ������������
/*!
    \param ch - ���������, ��� �������� ����� �������
*/
void check_readiness_to_enter_coef (int *ch);


/// �������, ������� ��������� ������������ ����� ������������ ����������� ���������
/*!

    \param inputParam - ��������� �� ������ ��������� equation_coef, ���������� �������������� ����������� ���������
    \param curr_input_param - ������� �������� ����������� (a, b, c)

*/
void get_correct_input (double *inputParam, const char * curr_input_param);


///�������, ������� ���������� ������������, ����� ��������� �������
/*!
 \param coef - �������� �����������
*/
void print_enter_coef (const char * curr_input_param);


///����������� ������������
void greetings_user ();

#endif
