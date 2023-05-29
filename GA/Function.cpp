//
//  Function.cpp
//  GA
//
//  Created by Math_Still on 2023/5/5.
//


#include "Function.hpp"


Function::Function(){
    
}
Function::Function(int function){
    this->function=function;
}
double Function::f1(Individual individual){
    double ans=0;
    for(auto i=0;i<=individual.get_numGenes();i++){
        ans+=individual.get_Gene(i).get_single()*individual.get_Gene(i).get_single();
    }
    return -ans;
}
double Function::f8(Individual individual){
    double ans=0;
    for(auto i=0;i<=individual.get_numGenes();i++){
        double temp=individual.get_Gene(i).get_single();
        ans+=-temp*sin(sqrt(abs(temp)));
    }
    return -ans;
}
double Function::ackley(Individual individual){
    double x=individual.get_Gene(0).get_single();
    double y=individual.get_Gene(1).get_single();

    return -(20+Math_e-20*pow(Math_e,-0.2*(sqrt(0.2*(x*x)+(y*y))))-pow(Math_e,0.5*(cos(2*PI*x)+cos(2*PI*y))));
        
}



