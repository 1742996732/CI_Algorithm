//
//  Partical.cpp
//  PSO
//
//  Created by Math_Still on 2023/5/22.
//

#include "Partical.hpp"
#include "Function.hpp"

Partical::Partical(){
    
}
void Partical::Init_Partical(int numDimension,Range range[],double c1,double c2,double w){
    this->p_best=minn;
    this->c1=c1;
    this->c2=c2;
    this->w=w;
    this->numDimension=numDimension;
    for(int i=0;i<this->numDimension;i++){
        Gene gene=Gene(range[i]);
        gene.Init_Gene();
        this->partical.push_back(gene);
    }
    Function function;
    this->p_best=function.f1(*this);
    
}
void Partical::Move(double g_best){
    for(int i=0;i<this->numDimension;i++){
        std::default_random_engine e((unsigned int)(time(0)+clock()));
        std::uniform_real_distribution<double> u(0,1);
        //renew x
        Gene gene=this->partical[i];
        std::uniform_real_distribution<double> u_x(gene.get_Range().get_x_MIN(),gene.get_Range().get_x_MAX());
        double new_x=gene.get_x()+gene.get_v();
        if(gene.get_Range().x_In_Range(new_x)){
            this->partical[i].set_x(new_x);
        }else{
            this->partical[i].set_x(u_x(e));//需要放一个随机数
        }
        //renew v
        double r1,r2;
        r1=u(e);
        r2=u(e);
        std::uniform_real_distribution<double> u_v(gene.get_Range().get_v_MIN(),gene.get_Range().get_v_MAX());
        double new_v=this->w*gene.get_v()+c1*r1*(gene.get_x_best()-gene.get_x())+c2*r2*(g_best-gene.get_x());
        if(gene.get_Range().v_In_Range(new_v)){
            this->partical[i].set_v(new_v);
        }else{
            this->partical[i].set_v(u_v(e));
        }
        //renew best
        Function function;
        if(this->p_best<function.f1(*this)){
            this->p_best=function.f1(*this);
            for(int j=0;j<this->numDimension;j++){
                this->partical[j].set_x_best(partical[j].get_x());
            }
        }
    }
}
int Partical::get_numDimension(){
    return this->numDimension;
}
Gene Partical::get_Gene(int Dimension){
    return this->partical[Dimension];
}
double Partical::get_p_best(){
    return this->p_best;
}
double Partical::get_c1(){
    return this->c1;
}
double Partical::get_c2(){
    return this->c2;
}
double Partical::get_w(){
    return this->w;
}
void Partical::Test_print(){
    for(int i=0;i<this->numDimension;i++){
        std::cout<<"Dim_"<<i<<" ";
        this->get_Gene(i).Test_print();
        std::cout<<" ";
    }
}
