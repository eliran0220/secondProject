//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_FILECACHEMANAGER_H
#define SECONDPROJECT_FILECACHEMANAGER_H


#include "CacheManager.h"

template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {

public:

    bool isSolutionExist(P problem);

    S popSolution(P problem);

    void saveSolution(S solution);

};


#endif //SECONDPROJECT_FILECACHEMANAGER_H
