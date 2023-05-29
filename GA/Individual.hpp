//
//  Individual.hpp
//  GA
//
//  Created by Math_Still on 2023/4/18.
//
#pragma once

#ifndef Individual_hpp
#define Individual_hpp

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include <random>
#include "Range.hpp"
#include "Gene.hpp"
//double fitness1(double x);
//double fitness2(double x1,double x2,double x3,double x4);
class Individual{
public:
    Individual();
    Individual(int numGenes);
    void Init_Individual(Range *range,std::default_random_engine e);
    void variation(double probability);//变异
    double get_fitness();
    int get_numGenes();
//    double fitness2(double x1,double x2,double x3,double x4);
    Gene get_Gene(int index);
    void set_Gene(int index,Gene gene);
    void Caculate_fitness();

    /*
     TEST
     */
    void Test_print_gene();
    /*
     TEST
     */
private:
    int numGenes;
    std::vector<Gene> gene;
    double fitness;
    int function;
};

#endif
