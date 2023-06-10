//
//  Partical.hpp
//  PSO
//
//  Created by Math_Still on 2023/5/22.
//

#ifndef Partical_hpp
#define Partical_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Gene.hpp"
#define minn -2147483647
#define maxx 2147483647
class Partical{
private:
    int numDimension;
    std::vector<Gene> partical;
    double c1,c2;
    double w;
    double p_best;
    
public:
    Partical();
    void Init_Partical(int numDimension,Range range[],double c1,double c2,double w);
    void Move(double g_best);
    Gene get_Gene(int Dimension);
    int get_numDimension();
    double get_p_best();
    double get_c1();
    double get_c2();
    double get_w();
    
    void Test_print();

};

#endif /* Partical_hpp */

