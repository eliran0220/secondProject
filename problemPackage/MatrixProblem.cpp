//
// Created by afik on 1/13/19.
//

#include <sstream>
#include "MatrixProblem.h"

vector<vector<string>> MatrixProblem::createMatrix(string matrixString) {
    string row;
    string index;
    stringstream ssRow(matrixString);
    vector<vector<string>> matrix;
    vector<string> splitRow;
    while (getline(ssRow,row,SEP_ROW)) {
        stringstream ssCol(matrixString);
        while (getline(ssRow,index,SEP_COL)) {
            splitRow.push_back(index);
        }
        matrix.push_back(splitRow);
    }
    return matrix;
}