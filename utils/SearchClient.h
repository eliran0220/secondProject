//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_SEARCHCLIENT_H
#define SECONDPROJECT_SEARCHCLIENT_H

#include "../solverPackage/Solver.h"
#include "../searchPackage/Searcher.h"

template<class T, class P, class S>
class SearchClient : public Solver<P, S> {

    Searcher<T> *searcher;
public:


    SearchClient(Searcher<T> *searcher) {
        this->searcher = searcher;
    }

    virtual S solver(P problem) override {
        searcher->search(problem);
    }

    virtual ~SearchClient() {
        delete (searcher);
    }


};

#endif //SECONDPROJECT_SEARCHCLIENT_H
