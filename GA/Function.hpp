//
//  Function.hpp
//  GA
//
//  Created by Math_Still on 2023/5/5.
//

#ifndef Function_hpp
#define Function_hpp
#include <stdio.h>
#include "Individual.hpp"
#include <cmath>
#define PI atan(1)*4
#define Math_e exp(1)
class Function{
public:
    Function();
    Function(int function);
    double static f1(Individual individual);
    double static f8(Individual individual);
    double static ackley(Individual individual);

private:
    int function;
    
    
};



#endif /* Function_hpp */
