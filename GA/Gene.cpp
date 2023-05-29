// {


#include"Individual.hpp"


Gene::Gene(double single,Range range){
    this->single=single;
    this->range=range;
}
Range Gene::get_Range(){
    return this->range;
}
double Gene::get_single(){
    return this->single;
}
void Gene::set_single(double single){
    this->single=single;
}
    
