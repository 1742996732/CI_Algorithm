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
class Function{
public:
    Function();
    Function(int function);
    double static f1(Individual individual);
    double static f8(Individual individual);
private:
    int function;
    
    
};



#endif /* Function_hpp */
