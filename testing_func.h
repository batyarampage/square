#ifndef testing_func
#define testing_func

#include "struct_of_square_equation.h"
#include "enumerate.h"

///Сравнивает два числа - корня уравнения

/*!
    Сравнивает два числа - референсное значение корня и значение полученное из тестов
*/
bool compare_two_double_in_test (double num1, double num2);

///Функция для считывания тестирующих коэффициентов из файла
/*!

 \param all_test[] - массив структур для заполнения из файла
 \param ok_test - указатель на булеву переменную для проверки существования файла тестирования

*/
void read_from_file (struct test_square_coefs all_test[], bool *ok_test);


///Функция тестирования основной программы
/*!
 \param all_test - массив структур для заполнения из файла
*/
void testing (struct test_square_coefs all_test[]);


///Функция вызываемая в main чтобы проверить, хочет ли пользователь провести тесты или же сразу решать уравнения
void is_user_wonna_test ();


///Приветствие пользователя во время теста
void greeting_user_for_test ();


///Проверка коретного ввода символа 't' для старта тестирования
/*!
 \param parametr - вводимый символ с клавиатуры
 \param aim_user - булева переменная, которая показывает, введен ли корректный символ с клавиатуры
*/
void check_user_input (int *parametr, bool *aim_user);

#endif
