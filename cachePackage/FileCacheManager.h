#ifndef FILECACHEMANAGER_H
#define FILECACHEMANAGER_H

using namespace std;

#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <mutex>
#include "CacheManager.h"

#define SEPRATE "$"
#define FILE_NAME "cacheSolution.txt"

/**
 * FileCacheManager class, implements CacheManager
 */
class FileCacheManager : public CacheManager<string, string> {
    ofstream fileInput;
    fstream fileOutput;
    map<string, string> mapProblemToSolution;
    map<string, string> updateFile;
    mutex mtx;

public:

    /**
     * Function name: FileCacheManager
     * The function operation: constructs a new FileCacheManager
     */
    FileCacheManager();

    /**
     * Function name: ~FileCacheManager
     * The function operation: destructs the FileCacheManager
     */
    ~FileCacheManager();

    /**
    * Function name: isSolutionExist
    * The function operation: given a string, checks if the solution exists
     * on the cache,if so return true, else return false
    * @return bool
    */
    bool isSolutionExist(string problem);

    /**
     * Function name: popSolution
     * The function operation: given a string, pops the solution
     * @param problem given string
     * @return string
     */
    string popSolution(string problem);

    /**
     * Function name: saveSolution
     * The function operation: given a problem and it's solution,
     * save it in the cache
     * @param problem given problem
     * @param solution given solution
     */
    void saveSolution(string problem, string solution);

};

#endif
