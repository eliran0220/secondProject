//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_CACHEMANAGER_H
#define SECONDPROJECT_CACHEMANAGER_H

template<class P, class S>
class CacheManager {
public:
    virtual bool isSolutionExist(P problem) = 0;

    virtual S popSolution(P problem) = 0;

    virtual void saveSolution(P problem,S solution) = 0;

    virtual ~CacheManager(){};
};

#endif //SECONDPROJECT_CACHEMANAGER_H
