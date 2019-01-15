
#include "FileCacheManager.h"

FileCacheManager::FileCacheManager() {
    this->fileInput = ofstream(FILE_NAME, ios_base::app);
    this->fileOutput = fstream(FILE_NAME);
}

FileCacheManager::~FileCacheManager() {
    auto it = this->updateFile.begin();
    while (it != this->updateFile.end()) {
        (this->fileInput) << it->first + SEPRATE + it->second << endl;
        it++;
    }
    this->fileOutput.close();
    this->fileInput.close();
    this->mapProblemToSolution.clear();
    this->updateFile.clear();
}

bool FileCacheManager::isSolutionExist(string problem) {
    lock_guard<mutex> lock(this->mtx);
    string temp = problem;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    if (this->mapProblemToSolution.count(temp) > 0) {
        return true;
    }
    string line;
    string tempProblem;
    string tempSolution;
    while (!this->fileOutput.eof()) {
        getline(this->fileOutput, line);
        stringstream ss(line);
        getline(ss, tempProblem, '$');
        getline(ss, tempSolution, '$');
        if (!tempProblem.empty() && !tempSolution.empty()) {
            this->mapProblemToSolution[tempProblem] = tempSolution;
            if (temp == tempProblem) {
                return true;
            }
        }
    }
    return false;
}

string FileCacheManager::popSolution(string problem) {
    lock_guard<mutex> lock(this->mtx);
    string temp = problem;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    return this->mapProblemToSolution[temp];
}


void FileCacheManager::saveSolution(string problem, string solution) {
    lock_guard<mutex> lock(this->mtx);
    string temp = problem;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    this->mapProblemToSolution[temp] = solution;
    this->updateFile[temp] = solution;
}
