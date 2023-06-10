//
//  Gene.hpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#ifndef Gene_hpp
#define Gene_hpp
//#include <ctime>
#include <random>
#include <stdio.h>
#include <iostream>
#include "Range.hpp"


class Gene{
private:
    double v;
    double x;
    double x_best;
    Range range;
public:
    Gene();
    Gene(Range range);
    void Init_Gene();
    double get_v();
    double get_x();
    void set_v(double v);
    void set_x(double x);
    double get_x_best();
    void set_x_best(double x_best);
    Range get_Range();
    void Test_print();
};
#endif /* Gene_hpp */
