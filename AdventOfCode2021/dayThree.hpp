//
//  dayThree.hpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 03/12/2021.
//  https://adventofcode.com/2021/day/3
//

#ifndef dayThree_hpp
#define dayThree_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

namespace AdventOfCode
{
    class dayThree
    {
    public:
        void partOne();
        void partTwo();
    private:
        int convert(long n);
    };

}

#endif /* dayThree_hpp */
