//
//  daySix.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 07/12/2021.
//  https://adventofcode.com/2021/day/6
//

#include "daySix.hpp"

using namespace AdventOfCode;
using namespace std;

void daySix::partOne()
{
    string myText;
    ifstream MyReadFile("Day6Input.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    stringstream ss(myText);
    map<int, unsigned long> ageCounts;
    for(int i; ss >> i;)
    {
        ageCounts[i]++;
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    for(int i = 0; i < 80; i++)
    {
        unsigned long zeros = ageCounts[0];
        for(int j = 0; j < 8; j++)
            ageCounts[j] = ageCounts[j + 1];
        ageCounts[6] += zeros;
        ageCounts[8] = zeros;
    }
    
    unsigned long lanternfishCount = 0;
    for(auto it = ageCounts.begin(); it != ageCounts.end(); it++)
        lanternfishCount += (*it).second;
    
    cout << "PART ONE: " << lanternfishCount << std::endl;
}

void daySix::partTwo()
{
    string myText;
    ifstream MyReadFile("Day6Input.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    stringstream ss(myText);
    map<int, unsigned long> ageCounts;
    for(int i; ss >> i;)
    {
        ageCounts[i]++;
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    for(int i = 0; i < 256; i++)
    {
        unsigned long zeros = ageCounts[0];
        for(int j = 0; j < 8; j++)
            ageCounts[j] = ageCounts[j + 1];
        ageCounts[6] += zeros;
        ageCounts[8] = zeros;
    }
    
    unsigned long lanternfishCount = 0;
    for(auto it = ageCounts.begin(); it != ageCounts.end(); it++)
        lanternfishCount += (*it).second;
    
    cout << "PART TWO: " << lanternfishCount << std::endl;
}
