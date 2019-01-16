#ifndef SECONDPROJECT_MATRIXPROBLEM_H
#define SECONDPROJECT_MATRIXPROBLEM_H

#include "ProblemCreator.h"
#include "../searchPackage/Searchable.h"
#include "../searchPackage/SearchableMatrix.h"

#define SEP_ROW ':'
#define SEP_COL ','

/**
 * MatrixProblem class.
 */
class MatrixProblem : public ProblemCreator<Searchable<Point*> *> {
    SearchableMatrix *searchable;

public:
    /**
     * constructor.
     */
    MatrixProblem() {
        this->searchable = nullptr;
    }

    ~MatrixProblem() override{
        if (searchable != nullptr) {
            delete (searchable);
        }
    }

    /**
     * Function operation - Given a concreted string, it creates a matrix in the
     * form of vector of vector of strings. each vector, is a row of the matrix,
     * and the last two vectors contain the initial state and the goal
     * state by order.
     * @param matrixString
     * @return
     */
    vector<vector<string>> createMatrix(string matrixString);

    /**
     * Function name: createProblem
     * The function operation: creates a problem from a given string
     * @param problem given problem
     * @return P
     */
    Searchable<Point *> *createProblem(string problem) override;
};

#endif
