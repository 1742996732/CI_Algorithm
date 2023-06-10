//
//  main.cpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//
#include <iostream>
#include <ctime>
#include <random>

#include "Partical.hpp"
#include "Range.hpp"
#include "Swarm.hpp"
double w=0.4;

//Range range[]={Range(-5*w,5*w,-5,5),Range(-5*w,5*w,-5,5)};
Range range[]={Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100)};
//Range range[]={Range(-100*w,100*w,-100,100),Range(-100*w,100*w,-100,100)};
int main(){
    int n;
    std::default_random_engine e((unsigned int)(time(0)+clock()));
    std::uniform_real_distribution<double> u(1,2);
    std::cin>>n;
    Swarm swarm=Swarm();
    swarm.Init_Swarm(n,20,range,2,2,0.2);
    
    int count=0;
    while(count<10000){//(swarm.get_g_best()<-0.00001){//
        count++;
        swarm.Move();
    }
    std::cout<<count<<std::endl;
    swarm.Test_print();
    std::cout<<swarm.get_g_best()<<std::endl;
}
