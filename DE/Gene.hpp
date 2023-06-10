//
//  Gene.hpp
//  GA
//
//  Created by Math_Still on 2023/4/25.
//

#ifndef Gene_hpp
#define Gene_hpp

#include <stdio.h>
#include "Range.hpp"


class Gene{
private:
    double single;
    Range range;
public:
    Gene();
    Gene(double single,Range range);
    Range get_Range();
    double get_single();
    void set_single(double single);
};

#endif /* Gene_hpp */
