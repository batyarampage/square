#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "new_solving.h"
#include "test_coef.h"
#include "testing_func.h"
#include "const_def.h"

const char* RED = "\033[31m";
const char* WHITE = "\033[0m";
const char* GREEN = "\033[32m";
const char* PURPLE = "\033[3;35m";

// ASSERTS ALL FILE!
void testing (struct test_square_coefs all_test[]){

    assert(all_test != nullptr);

    bool ok_test = true;

    read_from_file (all_test, &ok_test);

    int done_tests = 0;

    if (ok_test){

        for (int i = 0; i < TEST_COUNT; i++){

            struct square_equation_coefs local_coef;
            struct roots_square_equation local_roots;

            local_coef.a = all_test[i].a;
            local_coef.b = all_test[i].b;
            local_coef.c = all_test[i].c;

            Type_of_equation type_of_input_equation = type_of_equation_function (&local_coef);

            Count_of_roots count_root1 = solving_equation (&local_coef, type_of_input_equation, &local_roots);

            double x1ref = all_test[i].x1r;
            double x2ref = all_test[i].x2r;
            Count_of_roots count_of_roots_ref = all_test[i].count_root;

            double local_rootx1 = local_roots.x1;
            double local_rootx2 = local_roots.x2;

            if ((count_of_roots_ref != count_root1) ||
                (compare_two_double_in_test (x1ref, local_rootx1)) ||
                (compare_two_double_in_test (x2ref, local_rootx2))){

                printf("%s NOT PASSED TEST %d, x1ref = %g, x1 = %g, x2ref = %g, x2 = %g, количество корней ожидаемое = %d, реальное количество корней = %d %s\n ", RED,
                        i+1, x1ref, local_roots.x1,x2ref,local_roots.x2, count_of_roots_ref, count_root1, WHITE);

            }

            else{

                printf("%s CORRECT TEST %s\n", GREEN, WHITE);
                done_tests++;
            }
        }

        printf("%s Корректно тестов = %d %s\n ", PURPLE,done_tests, WHITE);
        printf("%s Некорректно тестов = %d %s \n", PURPLE, TEST_COUNT-done_tests, WHITE);
        printf("\n");
        getchar();// Выше сделан перевод строки, чтобы функция проверки ввода не считала этот пробел, я сразу же читаю его
                  // из потока ввода
    }

    else{

        printf("файл не существует\n");
        getchar();
    }
}

bool compare_two_double_in_test (double num1, double num2){

    static double EPS = 1e-3;

    if (fabs(num1-num2) < EPS){

        return false;
    }

    return true;
}

void read_from_file (struct test_square_coefs all_test[], bool *ok_test){

    FILE *fle = fopen("tests.txt", "r");

    if (fle == nullptr){

        printf("Возможно, вы удалили файл с тестовыми условиями, тестов не будет\n");
        *ok_test = false;

        while (getchar () != '\n');
        fclose(fle);

    }
    else {

        for (int i = 0; i<TEST_COUNT;i++){

            double a = 0;
            double b = 0;
            double c = 0;
            int roots_quantity = 0;
            double x1ref = 0;
            double x2ref = 0;

            fscanf(fle, "%lg%lg%lg%d%lg%lg", &a, &b, &c, &roots_quantity, &x1ref, &x2ref);

            Count_of_roots count_roots1 = Count_of_roots (roots_quantity);

            all_test[i].a = a;
            all_test[i].b = b;
            all_test[i].c = c;
            all_test[i].count_root = count_roots1;
            all_test[i].x1r = x1ref;
            all_test[i].x2r = x2ref;
        }

        fclose(fle);
    }
}

void greeting_user_for_test (){

    printf("Если хотите прогнать unit-тесты, то введите букву t, иначе любое другое число или букву\n");
}

void is_user_wanna_test (){

    greeting_user_for_test ();

    if (check_user_input()){

        test_square_coefs all_test[TEST_COUNT] = {{}};

        testing (all_test);
    }

    else{

        while (getchar () != '\n');

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
