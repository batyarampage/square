#include "struct_of_square_equation.h"
#include "enumerate.h"
#include "enter_coef.h"
#include "new_solving.h"
#include "printer_func.h"
#include "test_coef.h"
#include "testing_func.h"
#include "const_def.h"



//! @mainpage
//! Привет! Моя программа решает квадратное уравнение.
//! Инструкция, если не хочется ничего компилировать самому:
//!     1. Сделать клон репозитория square
//!     2. Запустить makeFile
//!     3. В директории *square* появится файл *square_solver.exe*, запускаем его и радуемся!
//! Инструкция, если все таки хочется скомпилировать самому
//!     1. Сделать клон репозитория square
//!     2. Запустить командную строку
//!     3. Перейти в директорий с клоном репозитория с помощью cd
//!            > Например: cd D:\cdblockscpp\square
//!      4. Скомпилировать файл
//!         > Например: .\g+++ .\main.cpp .\printer_func.cpp .\testing_func.cpp .\new_solving.cpp .\enter_coef.cpp .\func_tools.cpp -o square_solver.exe
//!         > > Примечание: файл "g+++" содержит флаги компиляции
//!     5. В директории клона репозитория появится исполняемый .exe файл, запускаем его и радуемся!
//! \author batyaRampage
//! \version 1.0
//! \date 25.08.2023


int main (){

    is_user_wanna_test ();

    struct square_equation_coefs equation_coef;
    struct roots_square_equation roots_square;

    if (get_coefs (&equation_coef)){

        Type_of_equation type_of_input_equation = type_of_equation_function (&equation_coef);

        Count_of_roots roots_quantity = solving_equation (&equation_coef, type_of_input_equation, &roots_square);

        printer (type_of_input_equation, &roots_square, roots_quantity);
    }

    else {

        print_eof_in_stdio ();
    }

    return 0;
}
