#include <iostream>
#include "ZFraction.h"
#include <cstdlib>


int main()
{

    ZFraction a(11,5);      //Déclare une fraction valant 4/5
    ZFraction b(5);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d,e,f;         //Déclare deux fractions valant 0

    std::cout << "a : " << a << " b : " << b << std::endl;
    c = a+b;               //Calcule 4/5 + 2/1 = 14/5
    d = a*b;               //Calcule 4/5 * 2/1 = 8/5
    e = a-b;
    f = b/a;

    std::cout << a << " + " << b << " = " << c << std::endl;
    std::cout << a << " - " << b << " = " << e << std::endl;

    std::cout << a << " * " << b << " = " << d << std::endl;
    std::cout << b << " / " << a << " = " << f << std::endl;


    if(a > b)
        std::cout << "a est plus grand que b." << std::endl;
    else if(a==b)
        std::cout << "a est egal a b." << std::endl;
    else
        std::cout << "a est plus petit que b." << std::endl;

    system("pause");
    system("cls");
    return 0;
}

