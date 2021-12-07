//
//  daySeven.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 07/12/2021.
//  https://adventofcode.com/2021/day/7
//

#include "daySeven.hpp"

using namespace AdventOfCode;
using namespace std;

struct option {
    int position;
    unsigned long fuelCost;
    option(int pos) : fuelCost(0)
    {
        position = pos;
    }
    void addFuel(int pos)
    {
        fuelCost += abs(position - pos);
    }
    
    //For part two.
    //Used the examples provided to work out a pattern
    //Diff, Fuel, Squared, Remainer
    //11  , 66  , 121    , 55
    //4   , 10  , 16     , 6
    //3   , 6   , 9      , 3
    //5   , 15  , 25     , 10
    //fuel = squared - (remainder)
    //fuel = squared - ((squared - diff)/2)
    void addComplexFuel(int pos)
    {
        if(pos == position) return;
        unsigned long diff = abs(position - pos);
        unsigned long squared = diff * diff;
        unsigned long fuelRequired = squared - ((squared - diff)/2);
        fuelCost += fuelRequired;
    }
};

void daySeven::partOne()
{
    string myText;
    ifstream MyReadFile("Day7Input.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    stringstream ss(myText);
    vector<option> options;
    for(int i; ss >> i;)
    {
        option o(i);
        options.push_back(o);
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    for(int i = 0; i < options.size(); i++)
    {
        int pos = options[i].position;
        for(int j = 0; j < options.size(); j++)
            options[j].addFuel(pos);
    }
    
    long fuelSpent = options[0].fuelCost;
    for(int i = 0; i < options.size(); i++)
    {
       if(options[i].fuelCost < fuelSpent)
           fuelSpent = options[i].fuelCost;
    }
    
    cout << "PART ONE: Fuel spent:" << fuelSpent << std::endl;
}

void daySeven::partTwo()
{
    string myText;
    ifstream MyReadFile("Day7Input.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    stringstream ss(myText);
    vector<option> options;
    for(int i; ss >> i;)
    {
        option o(i);
        options.push_back(o);
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    for(int i = 0; i < options.size(); i++)
    {
        int pos = options[i].position;
        for(int j = 0; j < options.size(); j++)
            options[j].addComplexFuel(pos);
    }
    
    unsigned long fuelSpent = options[0].fuelCost;
    for(int i = 0; i < options.size(); i++)
    {
       if(options[i].fuelCost < fuelSpent)
           fuelSpent = options[i].fuelCost;
    }
    
    cout << "PART TWO: Fuel spent:" << fuelSpent << std::endl;
}
