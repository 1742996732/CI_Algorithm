//
//  Swarm.hpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include <vector>
#include "Partical.hpp"
#define minn -2147483647
#define maxx 2147483647
class Swarm{
private:
    int numParticles;
    std::vector<Partical> swarm;
    double g_best;
public:
    Swarm();
    void Init_Swarm(int numParticles,int numDimension,Range range[],double c1,double c2,double w);
    double get_g_best();
    void Move();
    void Test_print();
};
#endif /* Swarm_hpp */
