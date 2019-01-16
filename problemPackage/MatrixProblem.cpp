#include <sstream>
#include "MatrixProblem.h"

vector<vector<string>> MatrixProblem::createMatrix(string matrixString) {
    string row;
    string index;
    stringstream ssRow(matrixString);
    vector<vector<string>> matrix;
    vector<string> splitRow;
    while (getline(ssRow, row, SEP_ROW)) {
        stringstream ssCol(row);
        while (getline(ssCol, index, SEP_COL)) {
            splitRow.push_back(index);
        }
        matrix.push_back(splitRow);
        splitRow.clear();
    }
    return matrix;
}

Searchable<Point *> *MatrixProblem::createProblem(string problem) {
    vector<vector<string>> matrix = createMatrix(problem);
    if (searchable == nullptr) {
        this->searchable = new SearchableMatrix(matrix);
    } else {
        searchable->setAndInitialize(matrix);
    }
    return this->searchable;
}