//
//  dayOne.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 02/12/2021.
//  https://adventofcode.com/2021/day/1
//

#include "dayOne.hpp"

using namespace AdventOfCode;
using namespace std;

void dayOne::partOne() {
    
    int previousMeasurement = -1;
    int depthIncreaseCounter = 0;
    string myText;
    ifstream MyReadFile("Day1Input.txt");
        
    while (getline (MyReadFile, myText)) {
        int depthMeasurement = stoi(myText);
        if(previousMeasurement != -1 && depthMeasurement > previousMeasurement)
            depthIncreaseCounter++;
        previousMeasurement = depthMeasurement;
    }
    MyReadFile.close();
    
    cout << "PART ONE: Increase Counter: " << depthIncreaseCounter << "\n";
}

void dayOne::partTwo() {
    
    int previousMeasurement = 0;
    int measurementA = -1;
    int measurementB = -1;
    int measurementC = -1;
    int depthIncreaseCounter = 0;
    string myText;
    ifstream MyReadFile("Day1Input.txt");
    
    for(int i = 0; getline (MyReadFile, myText); i++)
    {
        int mod = i % 3;
        if(mod == 0)
            measurementA = stoi(myText);
        else if(mod == 1)
            measurementB = stoi(myText);
        else
            measurementC = stoi(myText);
        
        if(i < 2) continue;
        
        int measurement = measurementA + measurementB + measurementC;
        
        if(i > 2 && measurement > previousMeasurement)
            depthIncreaseCounter++;
    
        previousMeasurement = measurement;
    }
    
    MyReadFile.close();
    
    cout << "PART TWO: SlidingWindow Counter: " << depthIncreaseCounter << "\n";
}
