//
// Created by afik on 1/13/19.
//

#ifndef SECONDPROJECT_MATRIXPROBLEM_H
#define SECONDPROJECT_MATRIXPROBLEM_H

#include "ProblemCreator.h"
#include "../searchPackage/Searchable.h"
#include "../searchPackage/SearchableMatrix.h"

template<class T>
class MatrixProblem : public ProblemCreator<Searchable<Point *> *> {
    SearchableMatrix *searchable;

public:
    MatrixProblem() {
        this->searchable = nullptr;
    }

    ~MatrixProblem() {
        if (searchable != nullptr) {
            delete (searchable);
        }
    }

    vector<vector<string>> createMatrix(string matrixString);

    Searchable<Point *> *createProblem(string problem) override{
        vector<vector<string>> matrix = createMatrix(problem);
        if (searchable == nullptr) {
            this->searchable = new SearchableMatrix(matrix);
        } else {
            searchable->setAndInitialize(matrix);
        }
        return this->searchable;
    }
};

#endif //SECONDPROJECT_MATRIXPROBLEM_H
