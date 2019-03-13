//
//  main.cpp
//  WarAndPeace
//
//  Created by Jerry Garcia on 2/13/19.
//  Copyright © 2019 Jerry Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Names to search for.
const string ALEXEEVICH  = "Makar Alexeevich";
const string BAZDEEV     = "Joseph Bazdeev";
const string DRUBETSKOY  = "Boris Drubetskoy";

const string INPUT_FILE_NAME = "/Users/jerry/Documents/CS144/WarAndPeace/WarAndPeace/WarAndPeace.txt";

//constructors
//searches a given line for the name Makar Alexeevich, Joseph Bazdeev, or Boris Drubetskoy respectively
//@param line that the iteration is currently on
//@param vector that holds the names we are searching for so we can print them out in order
//@param vector that holds the position of where the name was found in the string
//@param vector that holds the line that the name was found on
//@param the line number that we are on
//@param line that we were previously on to help find names that were split
void findA(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine);
void findB(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine);
void findD(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine);

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        //ends program if it fails to open up desired file
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    
    //vectors to help store information and make it easier to print out
    vector<string> str;
    vector<long> pos;
    vector<int> lines;
    //keeps track of line number
    int l = 0;
    string line, preLine = "";
    
    while (getline(input, line)){
        l++;
        findA(line, str, pos, lines, l, preLine);
        findB(line, str, pos, lines, l, preLine);
        findD(line, str, pos, lines, l, preLine);
        
        preLine = line;
    }
    cout << " LINE" << "  POSITION" << "  NAME" << endl;
    //iterate though the vectors and print out the contents
    for(int i = 0; i < pos.size(); i++){
        cout << lines.at(i) << setw(10) << pos.at(i) << "  " << str.at(i) << endl;
    }
    input.close();
}

//search given line for Makar Alexeevich and store information in vectors
void findA(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine){
    long finder = line.find(ALEXEEVICH);
    if(finder >= 0){ //makes sure name is found
        pos.push_back(finder + 1);
        str.push_back(ALEXEEVICH);
        lines.push_back(l);
        return;
    }
    finder = line.find("Alexeevich");
    if(finder == 0){//checks if line starts with last name, as an indicator of name being split
        finder = preLine.find("Makar");
        if(finder > 0){
            pos.push_back(finder + 1);
            str.push_back(ALEXEEVICH);
            lines.push_back(l - 1);
        }
    }
}

//search given line for Joseph Bazdeev and store information in vectors
void findB(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine){
    long finder = line.find(BAZDEEV);
    if(finder >= 0){//makes sure name is found
        pos.push_back(finder + 1);
        str.push_back(BAZDEEV);
        lines.push_back(l);
        return;
    }
    finder = line.find("Bazdeev");
    if(finder == 0){//checks if line starts with last name, as an indicator of name being split
        finder = preLine.find("Joseph");
        if(finder > 0){
            pos.push_back(finder + 1);
            str.push_back(BAZDEEV);
            lines.push_back(l - 1);
        }
    }
}

//search given line for Boris Drubetskoy and store information in vectors
void findD(string line, vector<string>& str, vector<long>& pos, vector<int>& lines, int l, string preLine){
    long finder = line.find(DRUBETSKOY);
    if(finder >= 0){//makes sure name is found
        pos.push_back(finder + 1);
        str.push_back(DRUBETSKOY);
        lines.push_back(l);
        return;
    }
    finder = line.find("Drubetskoy");
    if(finder == 0){//checks if line starts with last name, as an indicator of name being split
        finder = preLine.find("Boris");
        if(finder > 0){
            pos.push_back(finder + 1);
            str.push_back(DRUBETSKOY);
            lines.push_back(l - 1);
        }
    }
}
