//
//  dayEight.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 08/12/2021.
//  https://adventofcode.com/2021/day/8
//

#include "dayEight.hpp"

using namespace AdventOfCode;
using namespace std;

void dayEight::partOne()
{
    string myText;
    ifstream MyReadFile("Day8Input.txt");
    
    int appearCount = 0;
    while(getline (MyReadFile, myText))
    {
        size_t midPoint = myText.find(" | ");
        string outputValues = myText.substr(midPoint + 3, myText.size());
        
        for(int i = 0; i < 4; i++)
        {
            size_t pos = outputValues.find(" ");
            string substring = outputValues.substr(0, pos);
            unsigned long valueSize = substring.size();
            if(valueSize == 2 || valueSize == 3 || valueSize == 4 || valueSize == 7) appearCount++;
            outputValues.erase(0, pos + 1);
        }
        
    }
    MyReadFile.close();

    cout << "PART ONE: Appear Count:" << appearCount << std::endl;
}

void dayEight::partTwo()
{
    string myText;
    ifstream MyReadFile("Day8Input.txt");
    
    int outputValueCount = 0;
    while(getline (MyReadFile, myText))
    {
        size_t midPoint = myText.find(" | ");
        vector<string> signalPatterns = split(myText.substr(0, midPoint));
        
        //character that appears in seven and not one must be a
        string oneValue = findNumbers(signalPatterns, 2)[0];
        cout << "ONE: " << oneValue << std::endl;
        string sevenValue = findNumbers(signalPatterns, 3)[0];
        cout << "SEVEN: " << sevenValue << std::endl;
        
        char aWire = 'a';
        
        for(int i = 0; i < sevenValue.size(); i++)
        {
            bool foundChar = false;
            for(int j = 0; j < oneValue.size(); j++)
            {
                if(oneValue[j] == sevenValue[i])
                {
                    foundChar = true;
                    break;
                }
            }
            if(foundChar) continue;
            else aWire = sevenValue[i];
        }
        cout << "A: " << aWire << std::endl;
        
        char cWire = 'c';
        char fWire = 'f';
        
        //values 0, 6, and 9 each have one character missing, but 0 and 9 should include the values in 1.
        //The one that doesnt is 6, and the value it's missing is c. The remaining character from one is f
        vector<string> sixValues = findNumbers(signalPatterns, 6);
        for(int i = 0; i < sixValues.size(); i++)
        {
            vector<char> foundWires;
            for(int j = 0; j < sixValues[i].size(); j++)
            {
                for(int k = 0; k < oneValue.size(); k++)
                {
                    if(oneValue[k] == sixValues[i][j])
                        foundWires.push_back(oneValue[k]);
                }
            }
            if(foundWires.size() == 1)
            {
                if(oneValue[0] == foundWires[0])
                {
                    cWire = oneValue[0];
                    fWire = oneValue[1];
                }
                else
                {
                    cWire = oneValue[1];
                    fWire = oneValue[0];
                    
                }
                sixValues.erase(sixValues.begin() + i);
                break;
            }
        }
        
        cout << "C: " << cWire << std::endl;
        cout << "F: " << fWire << std::endl;
        
        //9 contains all the characters that are in 4.
        //0 has one missing - except d
        string fourValue = findNumbers(signalPatterns, 4)[0];
        char dWire = 'x';
        for(int i = 0; i < sixValues.size(); i++)
        {
            for(int j = 0; j < fourValue.size(); j++)
            {
                dWire = fourValue[j];
                for(int k = 0; k < sixValues[i].size(); k++)
                {
                    if(fourValue[j] == sixValues[i][k])
                    {
                        dWire = 'x';
                        break;
                    }
                }
                if(dWire != 'x') break;
            }
            if(dWire != 'x') break;
        }
        cout << "D: " << dWire << std::endl;
        
        vector<string> outputValues = split(myText.substr(midPoint + 3, myText.size()));
        
        string outputValue = "";
        for(int i = 0; i < outputValues.size(); i++)
        {
            unsigned long valueLength = outputValues[i].size();
            if(valueLength == 2)
                outputValue += '1';
            else if(valueLength == 3)
                outputValue += '7';
            else if(valueLength == 4)
                outputValue += '4';
            else if(valueLength == 7)
                outputValue += '8';
            else if(valueLength == 5)
            {
                if(!containsChar(outputValues[i], fWire))
                    outputValue += '2';
                else if(!containsChar(outputValues[i], cWire))
                    outputValue += '5';
                else
                    outputValue += '3';
            }
            else
            {
                if(!containsChar(outputValues[i], dWire))
                    outputValue += '0';
                else if(!containsChar(outputValues[i], cWire))
                    outputValue += '6';
                else
                    outputValue += '9';
            }
        }
        cout << outputValue << ": " << outputValue << std::endl;
        outputValueCount += stoi(outputValue);
        
    }
    MyReadFile.close();

    cout << "PART TWO: Output Count:" << outputValueCount << std::endl;
}

vector<string> dayEight::split(string input)
{
    vector<string> list;
    string substring;
    while(true)
    {
        size_t pos = input.find(" ");
        string substring = input.substr(0, pos);
        list.push_back(substring);
        input.erase(0, pos + 1);
        if(pos == string::npos) break;
    }
    return list;
}

vector<string> dayEight::findNumbers(vector<string> signalPatterns, int length)
{
    vector<string> subset;
    for(int i = 0; i < signalPatterns.size(); i++)
        if(signalPatterns[i].size() == length) subset.push_back(signalPatterns[i]);
    return subset;
}

bool dayEight::containsChar(string outputValue, char character)
{
    for(int i = 0; i < outputValue.size(); i++)
    {
        if(outputValue[i] == character)
            return true;
    }
    return false;
}
