//
//  Gene.cpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#include "Gene.hpp"

Gene::Gene(){
    
}
Gene::Gene(Range range){
    this->range=range;
}
void Gene::Init_Gene(){
    std::default_random_engine e((unsigned int)(time(0)+clock()));
    std::uniform_real_distribution<double> u1(this->range.get_x_MIN(),range.get_x_MAX());
    std::uniform_real_distribution<double> u2(this->range.get_v_MIN(),range.get_v_MAX());
    this->x=u1(e);
    this->v=u2(e);
    this->x_best=x;
}
double Gene::get_v(){
    return this->v;
}
double Gene::get_x(){
    return this->x;
}
Range Gene::get_Range(){
    return this->range;
}
void Gene::Test_print(){
    std::cout<<"x:"<<this->x<<" "<<"v:"<<this->v;
}
void Gene::set_v(double v){
    this->v=v;
}
void Gene::set_x(double x){
    this->x=x;
}
double Gene::get_x_best(){
    return this->x_best;
}
void Gene::set_x_best(double x_best){
    this->x_best=x_best;
}
