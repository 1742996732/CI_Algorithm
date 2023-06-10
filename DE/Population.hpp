//
//  Population.hpp
//  GA
//
//  Created by Math_Still on 2023/4/22.
//

#ifndef Population_hpp
#define Population_hpp

#include <stdio.h>
#include <bitset>
#include "Range.hpp"
#include <vector>
#include <set>
#include <algorithm>
#include "Individual.hpp"
class Population{
private:
    int nums;
    std::vector<Individual> people;
    std::vector<Individual> next_people;
    double fitness_Sum;
    std::vector<double> Individual_Ratio;
    double best_fitness;
    int best_tag;
    Individual best_Individual;
public:
    Population();
    Population(int num);
    void select();
    void select(int sub_individual);
    void Add_Individual(Individual individual);
    void Init_Population();
    void Caculate_Individual_Ratio();
    void Cross(double probability);
    void Cross_rand(double probability);
    void populatation_variation(double probability);
    double get_best_fitness();
    void Caculate_best_fitness();
    Individual get_Individual(int index);
    int get_best_tag();
    Individual get_best_Individual();
    /*
     TEST
     */
    void Test_print_Individual();
    /*
     TEST
    */
    
    
};
#endif /* Population_hpp */
