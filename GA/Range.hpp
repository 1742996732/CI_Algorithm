//
//  Range.hpp
//  GA
//
//  Created by Math_Still on 2023/4/23.
//

#ifndef Range_hpp
#define Range_hpp

#include <stdio.h>

class Range{
private:
    double Upper;
    double Lower;
public:
    Range();
    Range(double Lower,double Upper);
    double get_Upper();
    double get_Lower();
    bool In_Range(double x);
};


#endif /* Range_hpp */
