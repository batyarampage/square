#ifndef testing_func
#define testing_func

#include "struct_of_square_equation.h"
#include "enumerate.h"

///Сравнивает два числа - корня уравнения

/*!
    Сравнивает два числа - референсное значение корня и значение полученное из тестов
*/
bool compare_two_double_in_test (double num1, double num2);


///Функция тестирования основной программы
void testing ();


///Функция вызываемая в main чтобы проверить, хочет ли пользователь провести тесты или же сразу решать уравнения
void is_user_wanna_test ();


///Приветствие пользователя во время теста
void greeting_user_for_test ();


///Проверка коретного ввода символа 't' для старта тестирования
bool check_user_input ();

#endif
