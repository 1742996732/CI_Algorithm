//
//  main.cpp
//  GA
//
//  Created by Math_Still on 2023/4/18.
//

#include <iostream>
#include <ctime>
#include "Range.hpp"
#include "Individual.hpp"
#include "Population.hpp"

//Range range[]={Range(-5,5),Range(-5,5),Range(-5,5),Range(-5,5)};
//Range range[]={Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100),Range(-100,100)};
Range range[]={Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500),Range(-500,500)};
int main(){
    int n;
    std::cin>>n;
    int numGenes=30;
    Population population(n);
    Individual individual;
    for(int i=1;i<=n;i++){
        individual=Individual(numGenes);
        std::default_random_engine e((unsigned int)(time(0)+clock()));
        individual.Init_Individual(range,e);
        population.Add_Individual(individual);
    }
//    population.Caculate_Individual_Ratio();
    population.Init_Population();
//    population.Test_print_Individual();
//    std::cout<<"test"<<std::endl;
    std::cout<<"this is original individual"<<std::endl;
    population.Test_print_Individual();
    std::cout<<std::endl;
    
    int count=0;
    double x=0-0.000001;
    while(count<=10000000){//population.get_best_fitness()<=x){
//        std::default_random_engine e((unsigned int)(time(0)+clock()+count));
        count++;
        if(count%100000==0)std::cout<<count<<" "<<population.get_best_fitness()<<std::endl;
        population.Init_Population();
        population.select(8);
        
//            std::cout<<"this is select individual"<<std::endl;
//            population.Test_print_Individual();
//            std::cout<<std::endl;
        
//        population.Cross(0.65);
        population.Cross_rand(0.65);
//        population.Caculate_Individual_Ratio();

//            std::cout<<"this is cross individual"<<std::endl;
//            population.Test_print_Individual();
//            std::cout<<std::endl;
        
        
        population.populatation_variation(0.075);
        
//        std::cout<<"this is variation individual"<<std::endl;
//        population.Test_print_Individual();
//        std::cout<<std::endl;
//
//        if(count>=1000)break;
//        population.Caculate_best_fitness();
      
    }

//    population.Test_print_Individual();
    
    std::cout<<std::endl;
    std::cout<<"count:"<<count<<std::endl;
//    population.get_Individual(population.get_best_tag()).Test_print_gene();
    std::cout<<population.get_best_fitness();
    std::cout<<std::endl;
    population.get_best_Individual().Test_print_gene();
    std::cout<<std::endl;

  
}
