
#include "FileCacheManager.h"

FileCacheManager::FileCacheManager(string fileInput, string fileOutput) {
    this->fileInput = new ofstream(fileInput, ios_base::app);
    this->fileOutput = new fstream(fileOutput);
}

FileCacheManager::~FileCacheManager() {
    map<string, string>::iterator it = this->updateFile.begin();
    while (it != this->updateFile.end()) {
        *this->fileInput << it->first + "$" +it->second <<endl;
        it++;
    }
    this->fileOutput->close();
    this->fileInput->close();
    delete (this->fileInput);
    delete (this->fileOutput);
}

bool FileCacheManager::isSolutionExist(string problem) {
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
        this->mapProblemToSolution[tempProblem] = tempSolution;
        if (problem == tempProblem) {
            return true;
        }
    }
    return false;
}

string FileCacheManager::popSolution(string problem) {
    return this->mapProblemToSolution[problem];
}


void FileCacheManager::saveSolution(string problem, string solution) {
    this->mapProblemToSolution[problem] = solution;
    this->updateFile[problem] = solution;
}
