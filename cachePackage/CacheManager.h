#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

/**
 * CacheManager class, responsible of finding and saving solutions
 * @tparam P given problem
 * @tparam S solution
 */
template<class P, class S>
class CacheManager {
public:

    /**
     * Function name: isSolutionExist
     * The function operation: given a problem, checks if soltution exists, if so returns true
     * else returns false
     * @param problem given problem
     * @return bool
     */
    virtual bool isSolutionExist(P problem) = 0;

    /**
     * Function name: popSolution
     * The function operation: given a problem, return the solution
     * @param problem given problem
     * @return S
     */
    virtual S popSolution(P problem) = 0;

    /**
     * Function name: saveSolution
     * The function operation: given a problem and it's solution, save it to the cache
     * @param problem given problem
     * @param solution given solution
     */
    virtual void saveSolution(P problem,S solution) = 0;

    /**
     * Function name: ~CacheManager
     * The function operation: destructs the CacheManager
     */
    virtual ~CacheManager() = default;
};

#endif
