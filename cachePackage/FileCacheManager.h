//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_FILECACHEMANAGER_H
#define SECONDPROJECT_FILECACHEMANAGER_H

using namespace std;
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CacheManager.h"



class FileCacheManager : public CacheManager<string, string> {
    ofstream* fileInput;
    fstream* fileOutput;
    map<string, string> mapProblemToSolution;
    map<string, string> updateFile;

public:
    FileCacheManager(string file);

    ~FileCacheManager();

    bool isSolutionExist(string problem);

    string popSolution(string problem);

    void saveSolution(string problem, string solution);

};


#endif //SECONDPROJECT_FILECACHEMANAGER_H
