//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_ISEARCHER_H
#define SECONDPROJECT_ISEARCHER_H


template<class Solution, class Searchable> class ISearcher {
    virtual Solution search(Searchable searchable);
};
#endif //SECONDPROJECT_ISEARCHER_H
