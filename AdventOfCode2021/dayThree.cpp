//
//  dayThree.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 03/12/2021.
//  https://adventofcode.com/2021/day/3
//

#include "dayThree.hpp"

using namespace AdventOfCode;
using namespace std;

void dayThree::partOne() {
    
    long zeros[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long ones[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    string myText;
    ifstream MyReadFile("Day3Input.txt");
        
    while (getline (MyReadFile, myText)) {
        for(int i = 0; i < 12; i++)
        {
            if(myText.at(i) == '0') zeros[i]++;
            else ones[i]++;
        }
    }
    
    string gamma;
    string epsilon;
    
    for(int i = 0; i < 12; i++)
    {
        if(zeros[i] > ones[i])
        {
            gamma = gamma + "0";
            epsilon = epsilon + "1";
        }
        else
        {
            gamma = gamma + "1";
            epsilon = epsilon + "0";
        }
    }
    
    int gammaDec = convert(stol(gamma));
    int epsilonDec = convert(stol(epsilon));
    
    MyReadFile.close();
    
    cout << "PART ONE: Power Consumption: " << gammaDec * epsilonDec << "\n";
}

void dayThree::partTwo() {
    
    vector<string> oxygenRatings;
    vector<string> scrubberRatings;
    
    string myText;
    ifstream MyReadFile("Day3Input.txt");
        
    while (getline (MyReadFile, myText)) {
        oxygenRatings.push_back(myText);
        scrubberRatings.push_back(myText);
    }
    
    int oxygenRating = -1;
    int scrubberRating = -1;
    
    for(int i = 0; i < 12; i++)
    {
        long zeroCount = 0;
        long oneCount = 0;
        
        for(int j = 0; j < oxygenRatings.size(); j++)
        {
            if(oxygenRatings[j].at(i) == '0') zeroCount++;
            else oneCount++;
        }
        
        bool zeroCommon = zeroCount > oneCount;
        
        for(auto it = oxygenRatings.begin(); it != oxygenRatings.end(); it++)
        {
            char toCheck = (*it).at(i);
            if(oxygenRatings.size() == 1)
            {
                oxygenRating = convert(stol(*it));
                break;
            }
            
            if((toCheck == '1' && zeroCommon) || (toCheck == '0' && !zeroCommon))
                oxygenRatings.erase(it--);
        }
        if(oxygenRating != -1) break;
    }
    
    for(int i = 0; i < 12; i++)
    {
        long zeroCount = 0;
        long oneCount = 0;
        
        for(int j = 0; j < scrubberRatings.size(); j++)
        {
            if(scrubberRatings[j].at(i) == '0') zeroCount++;
            else oneCount++;
        }
        
        bool zeroCommon = zeroCount > oneCount;
        
        for(auto it = scrubberRatings.begin(); it != scrubberRatings.end(); it++)
        {
            char toCheck = (*it).at(i);
            if(scrubberRatings.size() == 1)
            {
                scrubberRating = convert(stol(*it));
                break;
            }
            
            if((toCheck == '0' && zeroCommon) || (toCheck == '1' && !zeroCommon))
                scrubberRatings.erase(it--);
        }
        if(scrubberRating != -1) break;
    }
    
    MyReadFile.close();
    
    cout << "PART TWO: Power Consumption: " << oxygenRating * scrubberRating << "\n";
}

//Based on: https://www.programiz.com/c-programming/examples/binary-decimal-convert
int dayThree::convert(long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
