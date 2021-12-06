//
//  dayFour.cpp
//  AdventOfCode2021
//
//  Created by Steven Coull on 05/12/2021.
//  https://adventofcode.com/2021/day/3
//

#include "dayFour.hpp"

using namespace AdventOfCode;
using namespace std;

struct boardNum
{
    int number;
    bool checked;
};

class bingoBoard {
    public:
        void addRow(vector<boardNum> row)
        {
            boardRows.push_back(row);
        }
        bool addNumber(int number)
        {
            for(int i = 0; i < boardRows.size(); i++)
            {
                for(int j = 0; j < boardRows[i].size(); j++)
                {
                    if(boardRows[i][j].number == number)
                        boardRows[i][j].checked = true;
                }
            }
            
            for(int i = 0; i < boardRows.size(); i++)
            {
                vector<boardNum> boardRow = boardRows[i];
                bool allChecked = true;
                for(int j = 0; j < boardRow.size(); j++)
                {
                    if(!boardRow[j].checked)
                    {
                        allChecked = false;
                        break;
                    }
                }
                if(allChecked) return true;
            }
            
            for(int i = 0; i < boardRows[0].size(); i++)
            {
                bool allChecked = true;
                for(int j = 0; j < boardRows.size(); j++)
                {
                    if(!boardRows[j][i].checked)
                    {
                        allChecked = false;
                        break;
                    }
                }
                if(allChecked) return true;
            }
            
            return false;
        }
        int score(int lastNum)
        {
            int score = 0;
            for(int i = 0; i < boardRows.size(); i++)
            {
                for(int j = 0; j < boardRows[i].size(); j++)
                {
                    if(!boardRows[i][j].checked)
                        score += boardRows[i][j].number;
                }
            }
            return score * lastNum;
        }
    private:
        vector<vector<boardNum>> boardRows;
};

void dayFour::partOne() {
    
    string myText;
    ifstream MyReadFile("Day4Input.txt");
    
    getline (MyReadFile, myText);
    vector<int> drawnNumbers;
    stringstream ss(myText);
    
    for(int i; ss >> i;)
    {
        drawnNumbers.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    vector<bingoBoard> boards;
    
    while(getline(MyReadFile, myText))
    {
        if(myText.empty())
        {
            bingoBoard board;
            boards.push_back(board);
            continue;
        }
        
        stringstream ss(myText);
        vector<boardNum> boardRow;
        
        for(int i; ss >> i;)
        {
            boardNum bNum;
            bNum.number = i;
            bNum.checked = false;
            boardRow.push_back(bNum);
            if(ss.peek() == ' ')
                ss.ignore();
        }
        
        boards[boards.size() - 1].addRow(boardRow);
    }
    
    MyReadFile.close();
        
    for(int i = 0; i < drawnNumbers.size(); i++)
    {
        int drawnNum = drawnNumbers[i];
        bool foundBingo = false;
        
        for(int j = 0; j < boards.size(); j++)
        {
            foundBingo = boards[j].addNumber(drawnNum);
            if(foundBingo)
            {
                cout << "PART ONE: Score: " << boards[j].score(drawnNum) << std::endl;
                return;
            }
        }
    }
}

void dayFour::partTwo() {
    
    string myText;
    ifstream MyReadFile("Day4Input.txt");
    
    getline (MyReadFile, myText);
    vector<int> drawnNumbers;
    stringstream ss(myText);
    
    for(int i; ss >> i;)
    {
        drawnNumbers.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    vector<bingoBoard> boards;
    
    while(getline(MyReadFile, myText))
    {
        if(myText.empty())
        {
            bingoBoard board;
            boards.push_back(board);
            continue;
        }
        
        stringstream ss(myText);
        vector<boardNum> boardRow;
        
        for(int i; ss >> i;)
        {
            boardNum bNum;
            bNum.number = i;
            bNum.checked = false;
            boardRow.push_back(bNum);
            if(ss.peek() == ' ')
                ss.ignore();
        }
        
        boards[boards.size() - 1].addRow(boardRow);
    }
    
    MyReadFile.close();
        
    for(int i = 0; i < drawnNumbers.size(); i++)
    {
        int drawnNum = drawnNumbers[i];
        bool foundBingo = false;
        
        for(auto it = boards.begin(); it != boards.end(); it++)
        {
            foundBingo = (*it).addNumber(drawnNum);
            if(!foundBingo) continue;
            
            if(boards.size() == 1)
            {
                cout << "PART TWO: Score: " << (*it).score(drawnNum) << std::endl;
                return;
            }
            else
                boards.erase(it--);
        }
    }
}
