//
//  Range.cpp
//  PSO
//
//  Created by Math_Still on 2023/5/31.
//

#include "Range.hpp"


Range::Range(){
    
}
Range::Range(double v_MIN,double v_MAX,double x_MIN,double x_MAX){
    this->v_MAX=v_MAX;
    this->v_MIN=v_MIN;
    this->x_MAX=x_MAX;
    this->x_MIN=x_MIN;
}
bool Range::x_In_Range(double x){
    if(x>=x_MIN&&x<=x_MAX){
        return true;
    }else{
        return false;
    }
}
bool Range::v_In_Range(double v){
    if(v>=v_MIN&&v<=v_MAX){
        return true;
    }else{
        return false;
    }
}
double Range::get_v_MAX(){
    return this->v_MAX;
}
double Range::get_v_MIN(){
    return this->v_MIN;
}
double Range::get_x_MAX(){
    return this->x_MAX;
}
double Range::get_x_MIN(){
    return this->x_MIN;
}
