//
//  main.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 02/12/2021.
//

using namespace std;
#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    cout << "Hello, Steven! Starting...\n";
    
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
    
    cout << "Increase Counter: " << depthIncreaseCounter << "\n";
    return 0;
}
