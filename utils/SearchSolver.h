//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_SEARCHCLIENT_H
#define SECONDPROJECT_SEARCHCLIENT_H

#include "../solverPackage/Solver.h"
#include "../searchPackage/Searcher.h"

using std::string;

template<class T>
class SearchSolver : public Solver<Searchable<T>*, vector<State<T>*>> {
    Searcher<T> *searcher;
    string solution;

public:
    SearchSolver(Searcher<T> *searcher) {
        this->searcher = searcher;
    }

    vector<State<T>*> solver(Searchable<T>* problem) override {
        vector<State<T>*> solutionPath =  searcher->search(problem);
        this->solution = problem->pathToString(solutionPath);
        return solutionPath;
    }

    string solutionToString(vector<State<T>*> solution) override{
        return this->solution;
    }




};

#endif //SECONDPROJECT_SEARCHCLIENT_H
