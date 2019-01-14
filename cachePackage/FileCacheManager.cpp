
#include "FileCacheManager.h"

FileCacheManager::FileCacheManager(string file) {
    this->fileInput = new ofstream(file, ios_base::app);
    this->fileOutput = new fstream(file);
}

FileCacheManager::~FileCacheManager() {
    map<string, string>::iterator it = this->updateFile.begin();
    while (it != this->updateFile.end()) {
        *(this->fileInput) << it->first + SEPRATE + it->second << endl;
        it++;
    }
    this->fileOutput->close();
    this->fileInput->close();
    delete (this->fileInput);
    delete (this->fileOutput);
}

bool FileCacheManager::isSolutionExist(string problem) {
    lock_guard<mutex> lock(this->mtx);
    if (this->mapProblemToSolution.count(problem) > 0) {
        return true;
    }
    string line;
    string tempProblem;
    string tempSolution;
    while (!this->fileOutput->eof()) {
        getline(*this->fileOutput, line);
        stringstream ss(line);
        getline(ss, tempProblem, '$');
        getline(ss, tempSolution, '$');
        if (tempProblem != "" && tempSolution != "") {
            this->mapProblemToSolution[tempProblem] = tempSolution;
            if (problem == tempProblem) {
                return true;
            }
        }
    }
    return false;
}

string FileCacheManager::popSolution(string problem) {
    //lock_guard<mutex> lock(this->mtx);
    return this->mapProblemToSolution[problem];
}


void FileCacheManager::saveSolution(string problem, string solution) {
    lock_guard<mutex> lock(this->mtx);
    this->mapProblemToSolution[problem] = solution;
    this->updateFile[problem] = solution;
}
