//
//  Fuction.cpp
//  PSO
//
//  Created by Math_Still on 2023/6/1.
//
#include "Function.hpp"
Function::Function(){
    
}
double Function::f1(Partical partical){
    double ans=0;
    for(auto i=0;i<=partical.get_numDimension();i++){
        ans+=partical.get_Gene(i).get_x()*partical.get_Gene(i).get_x();
    }
    return -ans;
}
//double Function::f8(Individual individual){
//    double ans=0;
//    for(auto i=0;i<=individual.get_numGenes();i++){
//        double temp=individual.get_Gene(i).get_single();
//        ans+=-temp*sin(sqrt(abs(temp)));
//    }
//    return -ans;
//}
double Function::ackley(Partical partical){
    double x=partical.get_Gene(0).get_x();
    double y=partical.get_Gene(1).get_x();

    return -(20+Math_e-20*pow(Math_e,-0.2*(sqrt(0.2*(x*x)+(y*y))))-pow(Math_e,0.5*(cos(2*PI*x)+cos(2*PI*y))));
        
}



