#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "new_solving.h"
#include "test_coef.h"
#include "testing_func.h"
#include "const_def.h"
#include "func_tools.h"

const char* RED = "\033[31m";
const char* WHITE = "\033[0m";
const char* GREEN = "\033[32m";
const char* PURPLE = "\033[3;35m";
const int FSCANF_COUNT_FROM_FILE = 6;

void testing (){

    FILE *fle = fopen("tests.txt", "r");

    if (fle == nullptr){

        printf("Возможно, вы удалили файл с тестовыми условиями, тестов не будет\n");

        cleaner_stdio ();

    }

    else{

        int done_tests = 0;
        int count_of_all_tests = 0;

        double a = 0;
        double b = 0;
        double c = 0;
        int roots_quantity = 0;
        double x1ref = 0;
        double x2ref = 0;

        while ((fscanf(fle, "%lg%lg%lg%d%lg%lg", &a, &b, &c, &roots_quantity, &x1ref, &x2ref)) == FSCANF_COUNT_FROM_FILE){

            count_of_all_tests++;

            struct square_equation_coefs local_coef;
            struct roots_square_equation local_roots;

            local_coef.a = a;
            local_coef.b = b;
            local_coef.c = c;

            Count_of_roots count_of_roots_ref = Count_of_roots (roots_quantity);

            Type_of_equation type_of_input_equation = type_of_equation_function (&local_coef);

            Count_of_roots count_root1 = solving_equation (&local_coef, type_of_input_equation, &local_roots);

            double local_root_x1 = local_roots.x1;
            double local_root_x2 = local_roots.x2;

            if ((compare_two_double_in_test(local_root_x2, x2ref)) || (compare_two_double_in_test(local_root_x1, x1ref)) || (count_of_roots_ref != count_root1)){

                     printf("%s NOT PASSED TEST %d, x1ref = %g, x1 = %g, x2ref = %g, x2 = %g, количество корней ожидаемое = %d, реальное количество корней = %d %s\n ", RED,
                        count_of_all_tests, x1ref, local_root_x1,x2ref,local_root_x2, count_of_roots_ref, count_root1, WHITE);
            }

            else {

                printf("%s CORRECT TEST %s\n", GREEN, WHITE);
                done_tests++;
            }
        }

        fclose(fle);

        if (count_of_all_tests == 0){

            printf("В файле с тестами нет тестов\n");
        }

        else{
            printf("%s Корректно тестов = %d %s\n ", PURPLE,done_tests, WHITE);
            printf("%s Некорректно тестов = %d %s \n", PURPLE, count_of_all_tests-done_tests, WHITE);
            printf("\n");
        }
    }
}

bool compare_two_double_in_test (double num1, double num2){

    static double EPS = 1e-3;

    if (fabs(num1-num2) < EPS){

        return false;
    }

    return true;
}

void greeting_user_for_test (){

    printf("Если хотите прогнать unit-тесты, то введите букву t, иначе любое другое число или букву\n");
}

void is_user_wanna_test (){

    greeting_user_for_test ();

    if (check_user_input()){

        testing ();
    }

    else{

        printf("Вы не захотели тесты, их не будет\n");
    }
}

bool check_user_input (){

    int parametr = 0;

    parametr = getchar ();

    const int TEST_LAUNCH_MARKER = 't';

    if (parametr == TEST_LAUNCH_MARKER){

        return true;
    }

    return false;
}
