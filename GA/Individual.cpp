//
//  Individual.cpp
//  GA
//
//  Created by Math_Still on 2023/4/18.
//

#include "Individual.hpp"
#include "Function.hpp"
#define PI atan(1)*4

Individual::Individual(){
    
}
Individual::Individual(int numGenes){
    this->numGenes=numGenes;
    this->fitness=0;
}
double f1(Individual individual);
void Individual::Init_Individual(Range range[],std::default_random_engine e){
    //    std::default_random_engine e((unsigned int)time(0));
    for(int i=0;i<numGenes;i++){
        std::uniform_real_distribution<double> u(range[i].get_Lower(),range[i].get_Upper());
        this->gene.push_back(Gene(u(e),range[i]));
    }
//    this->fitness=this->fitness2(gene[0].get_single(),gene[1].get_single(),gene[2].get_single(),gene[3].get_single());
    this->Caculate_fitness();
//    this->fitness=Function::f1(*this);
}
void Individual::Caculate_fitness(){
//    this->fitness=this->fitness2(gene[0].get_single(),gene[1].get_single(),gene[2].get_single(),gene[3].get_single());
    this->fitness=Function::ackley(*this);
}

double Individual::get_fitness(){
    return this->fitness;
}
int Individual::get_numGenes(){
    return numGenes;
}
Gene Individual::get_Gene(int index){
    return this->gene[index];
}
void Individual::set_Gene(int index,Gene gene){
    this->gene[index]=gene;
}
void Individual::variation(double probability){
    std::default_random_engine e((unsigned int)((clock())+time(0)));
    for(int i=0;i<this->numGenes;i++){
        std::uniform_real_distribution<double> u(0,1);
        double temp=u(e);
        if(temp>=probability){
            continue;
        }else{
            std::uniform_real_distribution<double> ran(this->get_Gene(i).get_Range().get_Lower(),this->get_Gene(i).get_Range().get_Upper());
//            double change=ran(e);
//            std::uniform_real_distribution<double> ran1(-0.01,0.01);
            double change1=ran(e);
            if(change1<=5&&change1>=-5){
                gene[i].set_single(change1);
            }
        }
    }
}

void Individual::Test_print_gene(){
    for(auto i:this->gene){
        std::cout<<i.get_single()<<" ";
    }
}


