#ifndef testing_func
#define testing_func

#include "struct_of_square_equation.h"
#include "enumerate.h"

///������� ��� ��������� ������������ �������� ����� � ����������� ��� ������������
bool compare_two_double_in_test (double num1, double num2);

///������� ��� ���������� ����������� ������������� �� �����
/*!

 \param all_test[] - ������ �������� ��� ���������� �� �����
 \param ok_test - ��������� �� ������ ���������� ��� �������� ������������� ����� ������������

*/
void cin_from_file (struct test_square_coefs all_test[], bool *ok_test);


///������� ������������ �������� ���������
void testing (struct test_square_coefs all_test[]);


///������� ���������� � main ����� ���������, ����� �� ������������ �������� ����� ��� �� ����� ������ ���������
void is_user_wonna_test ();


///����������� ������������ �� ����� �����
void greeting_user_for_test ();


///�������� ��������� ����� ������� 't' ��� ������ ������������
void check_user_input (int *parametr, bool *aim_user);

#endif
