//
//  dayTwo.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 03/12/2021.
//  https://adventofcode.com/2021/day/2
//

#include "dayTwo.hpp"

using namespace AdventOfCode;
using namespace std;

void dayTwo::partOne() {
    
    int horizontal = 0;
    int depth = 0;
    
    string myText;
    ifstream MyReadFile("Day2Input.txt");
        
    while (getline (MyReadFile, myText)) {
        size_t space = myText.find(" ");
        string dir = myText.substr(0, space);
        int value = stoi(myText.substr(space + 1, myText.length()));
        
        if(dir == "forward") horizontal += value;
        else if(dir == "down") depth += value;
        else depth -= value;
    }
    
    MyReadFile.close();
    
    cout << "PART ONE: Increase Counter: " << horizontal * depth << "\n";
}

void dayTwo::partTwo() {
    
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    
    string myText;
    ifstream MyReadFile("Day2Input.txt");
        
    while (getline (MyReadFile, myText)) {
        size_t space = myText.find(" ");
        string dir = myText.substr(0, space);
        int value = stoi(myText.substr(space + 1, myText.length()));
        
        if(dir == "forward")
        {
            horizontal += value;
            depth += (aim * value);
        }
        else if(dir == "down") aim += value;
        else aim -= value;
    }
    
    MyReadFile.close();
    
    cout << "PART TWO: Increase Counter: " << horizontal * depth << "\n";
}
