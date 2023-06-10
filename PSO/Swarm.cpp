//
//  Swarm.cpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#include "Swarm.hpp"

Swarm::Swarm(){
    
}


void Swarm::Init_Swarm(int numParticles,int numDimension,Range range[],double c1,double c2,double w){
    this->numParticles=numParticles;
    this->g_best=minn;
    for(int i=0;i<numParticles;i++){
        Partical partical;
        partical.Init_Partical(numDimension,range,c1,c2,w);
        this->swarm.push_back(partical);
        if(this->g_best<partical.get_p_best()){
            this->g_best=partical.get_p_best();
        }
    }
}
void Swarm::Move(){
    for(int i=0;i<this->numParticles;i++){
        this->swarm[i].Move(this->g_best);
        if(this->g_best<swarm[i].get_p_best()){
            this->g_best=swarm[i].get_p_best();
        }
    }
}

double Swarm::get_g_best(){
    return this->g_best;
}







void Swarm::Test_print(){
    for(int i=0;i<this->numParticles;i++){
        std::cout<<"Swarm_"<<i<<" ";
        this->swarm[i].Test_print();
        std::cout<<std::endl;
    }
}

