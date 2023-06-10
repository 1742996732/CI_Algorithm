//
//  Fuction.hpp
//  PSO
//
//  Created by Math_Still on 2023/6/1.
//

#ifndef Function_hpp
#define Function_hpp
#include <stdio.h>
#include <cmath>
#include "Partical.hpp"
#define PI atan(1)*4
#define Math_e exp(1)
class Function{
private:
    int function;
public:
    Function();
    
    double static ackley(Partical partical);
    double static f1(Partical partical);
    double static f8(Partical partical);

    
};



#endif /* Function_hpp */
