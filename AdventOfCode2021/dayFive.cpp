//
//  dayFive.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 06/12/2021.
//  https://adventofcode.com/2021/day/5
//

#include "dayFive.hpp"

using namespace AdventOfCode;
using namespace std;

struct coord
{
    int x;
    int y;
    
    //Support for struct as key in map
    //https://dawnarc.com/2019/09/c-how-to-use-a-struct-as-key-in-a-std-map/
    bool operator==(const coord &o) const
    {
        return x == o.x && y == o.y;
    }

    bool operator<(const coord &o)  const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
    
    bool operator!=(const coord &o) const
    {
        return x != o.x || y != o.y;
    }
    
    coord getNextCoord(coord modfier)
    {
        coord nextCood;
        nextCood.x = x + modfier.x;
        nextCood.y = y + modfier.y;
        return nextCood;
    }
};

void dayFive::partOne()
{
    ifstream MyReadFile("Day5Input.txt");
    string myText;
    map<coord, long> points;
    while(getline(MyReadFile, myText))
    {
        size_t midPoint = myText.find(" -> ");
        string pointString = myText.substr(0, midPoint);
        size_t commaPoint = pointString.find(",");
        coord startPoint;
        
        startPoint.x = stoi(pointString.substr(0, commaPoint));
        startPoint.y = stoi(pointString.substr(commaPoint + 1, pointString.size()));
       
        pointString = myText.substr(midPoint + 4, myText.size());
        commaPoint = pointString.find(",");
        coord endPoint;
        endPoint.x = stoi(pointString.substr(0, commaPoint));
        endPoint.y = stoi(pointString.substr(commaPoint + 1, pointString.size()));
        
        if(startPoint.x != endPoint.x && startPoint.y != endPoint.y) continue;
        
        coord mod;
        mod.x = startPoint.x == endPoint.x ? 0 : startPoint.x < endPoint.x ? 1 : -1;
        mod.y = startPoint.y == endPoint.y ? 0 : startPoint.y < endPoint.y ? 1 : -1;
        coord c = startPoint;
        points[c]++;
        while(c != endPoint)
        {
            c = c.getNextCoord(mod);
            points[c]++;
        }
    }
    MyReadFile.close();
    
    long dangerPoints = 0;
    for(auto it = points.begin(); it != points.end(); it++)
    {
        if((*it).second > 1) dangerPoints++;
    }
    
    cout << "PART ONE: Number of points: " << dangerPoints << std::endl;
}

void dayFive::partTwo()
{
    ifstream MyReadFile("Day5Input.txt");
    string myText;
    map<coord, long> points;
    while(getline(MyReadFile, myText))
    {
        size_t midPoint = myText.find(" -> ");
        string pointString = myText.substr(0, midPoint);
        size_t commaPoint = pointString.find(",");
        coord startPoint;
        
        startPoint.x = stoi(pointString.substr(0, commaPoint));
        startPoint.y = stoi(pointString.substr(commaPoint + 1, pointString.size()));
       
        pointString = myText.substr(midPoint + 4, myText.size());
        commaPoint = pointString.find(",");
        coord endPoint;
        endPoint.x = stoi(pointString.substr(0, commaPoint));
        endPoint.y = stoi(pointString.substr(commaPoint + 1, pointString.size()));
        
        coord mod;
        mod.x = startPoint.x == endPoint.x ? 0 : startPoint.x < endPoint.x ? 1 : -1;
        mod.y = startPoint.y == endPoint.y ? 0 : startPoint.y < endPoint.y ? 1 : -1;
        coord c = startPoint;
        points[c]++;
        while(c != endPoint)
        {
            c = c.getNextCoord(mod);
            points[c]++;
        }
    }
    MyReadFile.close();
    
    long dangerPoints = 0;
    for(auto it = points.begin(); it != points.end(); it++)
    {
        if((*it).second > 1) dangerPoints++;
    }
    
    cout << "PART TWO: Number of points: " << dangerPoints << std::endl;
}
