#ifndef struct_of_square_equation
#define struct_of_square_equation
///Структура, указывающая на коэффициенты квадратного уравнения
struct square_equation_coefs{
    /// коэффициент a
    double a = 0;

    /// коэффициент b
    double b = 0;

    /// коэффициент c
    double c = 0;
};


///Структура, указывающая на корни квадратного уравния
struct roots_square_equation{
    ///Первый корень квадратного уравнения (в него записывается корень, если решение единственно)
    double x1 = 0;

    /// Второй корень квадратного уравнения
    double x2 = 0;

};

#endif
