 #ifndef test_coef
 #define test_coef

/// Структура, предназначенная для ввода тестирующих коэффициентов из файла
struct test_square_coefs{

    /// Коэффициент а
    double a = 0;

    ///Коэффициент b
    double b = 0;

    ///Коэффициент c
    double c = 0;

    ///Референсное количество корней
    Count_of_roots count_root = INFINITI;

    ///Референсное значение первого корня
    double x1r = 0;

    ///Референсное значение второго корня
    double x2r = 0;

};

#endif
