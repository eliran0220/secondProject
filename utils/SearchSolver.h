#ifndef SEARCHCLIENT_H
#define SEARCHCLIENT_H

#include "../solverPackage/Solver.h"
#include "../searchPackage/Searcher.h"

using std::string;

/**
 * SearchSolver class, an object adapter which involves the searcher and the solver
 * @tparam T
 */
template<class T>
class SearchSolver : public Solver<Searchable<T> *, vector<State<T> *>> {
    Searcher<T> *searcher;
    string solution;

public:
    /**
     * Function name: SearchSolver
     * The function operation: constructs a new searcher by a given one
     * @param searcher given search
     */
    SearchSolver(Searcher<T> *searcher) {
        this->searcher = searcher;
    }

    /**
     * Function name: solver
     * The function operation: given a problem, the searcher uses this function to solve the problem
     * keeps it in a vector of states, and then this vector is converted to a string path, which is
     * lastly returned
     * @param problem a given searchable problem
     * @return vector<State>*>
     */
    vector<State<T> *> solver(Searchable<T> *problem) override {
        vector<State<T> *> solutionPath = searcher->search(problem);
        this->solution = problem->pathToString(solutionPath);
        return solutionPath;
    }

    /**
     * Function name: solutionToString
     * The function operation: returns the string solution
     * @param solution a given solution represented in a vector of states
     * @return string
     */
    string solutionToString(vector<State<T> *> solution) override {
        return this->solution;
    }

};

#endif SEARCHCLIENT_H
