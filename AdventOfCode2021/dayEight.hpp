//
//  dayEight.hpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 08/12/2021.
//  https://adventofcode.com/2021/day/8
//

#ifndef dayEight_hpp
#define dayEight_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

namespace AdventOfCode
{
    class dayEight
    {
    public:
        void partOne();
        void partTwo();
    private:
        std::vector<std::string> split(std::string input);
        std::vector<std::string> findNumbers(std::vector<std::string>, int length);
        bool containsChar(std::string outputValue, char character);
    };
}

#endif /* dayEight_hpp */
