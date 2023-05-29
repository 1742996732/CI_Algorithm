//
//  Range.cpp
//  GA
//
//  Created by Math_Still on 2023/4/23.
//

#include "Range.hpp"

Range::Range(){
    
}
Range::Range(double Lower,double Upper){
    this->Lower=Lower;
    this->Upper=Upper;
}
double Range::get_Lower(){
    return this->Lower;
}
double Range::get_Upper(){
    return this->Upper;
}
bool Range::In_Range(double x){
    if(x<=this->Upper&&x>=this->Lower){
        return 1;
    }else{
        return 0;
    }
}
