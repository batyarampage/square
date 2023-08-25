
#ifndef enumerate
#define enumerate

enum Type_of_equation{

    LINEAR_EQUATION = 0, //!< Линейное уравнение
    QUADRATIC_EQUATION = 1, //!< Квадратное уравнение
    NOT_A_EQUATION = 2 //!< Не является уравнением (все коэффициенты нули)
};

enum Count_of_roots{

    INFINITI = -1, //!< Бесконечное количество решений
    NO_ROOTS = 0, //!< Нет корней
    ONE_ROOT = 1, //!< Один корень (линейное уравнение или дискриминант у квадратного уравнения равен нулю
    TWO_ROOT = 2  //!< Два корня (положительный дискриминант у квадратного уравнения)
} ;

#endif
