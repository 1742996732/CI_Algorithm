//
//  Range.hpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#ifndef Range_hpp
#define Range_hpp

#include <stdio.h>

class Range{
private:
    double v_MAX;
    double v_MIN;
    double x_MAX;
    double x_MIN;
public:
    Range();
    Range(double v_MAX,double v_MIN,double x_MAX,double x_MIN);
    bool x_In_Range(double x);
    bool v_In_Range(double v);
    double get_v_MAX();
    double get_v_MIN();
    double get_x_MAX();
    double get_x_MIN();
};
#endif /* Range_hpp */
