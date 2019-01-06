//
// Created by eliran on 1/6/19.
//

#include "FileCacheManager.h"


template<class P, class S>
bool FileCacheManager<P, S>::isSolutionExist(P problem) {
    return false;
}

template<class P, class S>
S FileCacheManager<P, S>::popSolution(P problem) {
    return nullptr;
}

template<class P, class S>
void FileCacheManager<P,S>::saveSolution(S solution) {

}
