//
//  Population.cpp
//  GA
//
//  Created by Math_Still on 2023/4/22.
//

#include "Population.hpp"


Population::Population(int nums){
    this->nums=nums;
    this->best_fitness=-99999999;
}
void Population::Add_Individual(Individual individual){
    this->people.push_back(individual);
}
void Population::Test_print_Individual(){
    for(auto i:people){
        i.Test_print_gene();
        std::cout<<std::endl;
    }
}
void Population::Init_Population(){
    double temp=0;
    for(int i=0;i<this->nums;i++){
        this->people[i].Caculate_fitness();
    }
    for(auto i:people){
        temp+=i.get_fitness();
    }
    this->fitness_Sum=temp;
    Caculate_Individual_Ratio();
    Caculate_best_fitness();
}
void Population::Caculate_Individual_Ratio(){
    this->Individual_Ratio.clear();
    double sum=0.0;
    for(int i=0;i<nums;i++){
        sum+=this->people[i].get_fitness();
        this->Individual_Ratio.push_back((double)sum/this->fitness_Sum);
    }
}
void Population::select(){
    std::default_random_engine e((unsigned int)((clock())+time(0)));
    std::uniform_real_distribution<double> u(0.0,1.0);
    for(int i=0;i<nums;i++){
        double temp=u(e);
        
        int flag=0;
        double select_value=this->Individual_Ratio[flag];
        while(select_value<=temp){
            flag++;
            select_value=this->Individual_Ratio[flag];
        }
        this->next_people.push_back(this->people[flag]);
    }
}

void Population::select(int sub_individual){
    int count=0;
    Individual temp_individual;
    while(count<this->nums){
        std::set<int> rand_set;
        std::default_random_engine e((unsigned int)((clock())+time(0)));
        std::uniform_real_distribution<double> u(0,this->nums-1);
        while(rand_set.size()<=sub_individual){
            rand_set.insert(u(e));
        }
        double fitness=-99999999;
        for(auto i:rand_set){
            if(this->people[i].get_fitness()>fitness){
//                temp_individual=this->get_Individual(i);
                temp_individual=this->people[i];
                fitness=temp_individual.get_fitness();//this->get_Individual(i).get_fitness();
            }
        }
        this->next_people.push_back(temp_individual);
        count++;
        rand_set.clear();
    }

}

void Population::Cross(double probability){
    for(int i=0;i<nums-1;i+=2){
        Individual individual1=this->next_people[i];
        Individual individual2=this->next_people[i+1];
        std::uniform_real_distribution<double> u(0,1);
        std::default_random_engine e((unsigned int)((clock())+time(0)));
        double temp=u(e);
        if(temp<=probability){
            int temp=rand()%individual1.get_numGenes();
            for(int j=0;j<temp;j++){
                this->people[i].set_Gene(j,next_people[i+1].get_Gene(j));
                this->people[i+1].set_Gene(j,next_people[i].get_Gene(j));
            }
            for(int j=temp;j<individual1.get_numGenes();j++){
                this->people[i].set_Gene(j,next_people[i].get_Gene(j));
                this->people[i+1].set_Gene(j,next_people[i+1].get_Gene(j));
            }
        }
    }
    this->next_people.clear();
}
void Population::Cross_rand(double probability){
    if(((int)clock()+time(0))%2==0){
        for(int i=0;i<nums-1;i+=2){
            Individual individual1=this->next_people[i];
            Individual individual2=this->next_people[i+1];
            std::uniform_real_distribution<double> u(0,1);
            std::default_random_engine e((unsigned int)((clock())+time(0)));
            double temp=u(e);
            if(temp<=probability){
                int temp=rand()%individual1.get_numGenes();
                for(int j=0;j<temp;j++){
                    this->people[i].set_Gene(j,next_people[i+1].get_Gene(j));
                    this->people[i+1].set_Gene(j,next_people[i].get_Gene(j));
                }
                for(int j=temp;j<individual1.get_numGenes();j++){
                    this->people[i].set_Gene(j,next_people[i].get_Gene(j));
                    this->people[i+1].set_Gene(j,next_people[i+1].get_Gene(j));
                }
            }
        }
        this->next_people.clear();
    }else{
        for(int i=0;i<nums/2;i++){
            Individual individual1=this->next_people[i];
            Individual individual2=this->next_people[nums-i-1];
            std::uniform_real_distribution<double> u(0,1);
            std::default_random_engine e((unsigned int)((clock())+time(0)));
            double temp=u(e);
            if(temp<=probability){
                int temp=rand()%individual1.get_numGenes();
                for(int j=0;j<temp;j++){
                    this->people[i].set_Gene(j,next_people[nums-i-1].get_Gene(j));
                    this->people[nums-i-1].set_Gene(j,next_people[i].get_Gene(j));
                }
                for(int j=temp;j<individual1.get_numGenes();j++){
                    this->people[i].set_Gene(j,next_people[i].get_Gene(j));
                    this->people[nums-i-1].set_Gene(j,next_people[nums-i-1].get_Gene(j));
                }
            }
        }
        this->next_people.clear();
    }
    
}

void Population::populatation_variation(double probability){
    std::default_random_engine e((unsigned int)((clock())+time(0)));
    for(int i=0;i<this->nums;i++){
        this->people[i].variation(probability);
    }
}
void Population::Caculate_best_fitness(){
    int count=0;
    for(auto i:this->people){
//        =std::max(this->best_fitness,);
        if(i.get_fitness()>this->best_fitness){
            best_tag=count;
            this->best_fitness=i.get_fitness();
            this->best_Individual=i;
        }
        count++;
    }
}
double Population::get_best_fitness(){
    return this->best_fitness;
}
Individual Population::get_Individual(int index){
    return this->people[index];
}
int Population::get_best_tag(){
    return this->best_tag;
}
Individual Population::get_best_Individual(){
    return this->best_Individual;
}
