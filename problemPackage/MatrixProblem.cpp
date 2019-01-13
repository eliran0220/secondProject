//
// Created by afik on 1/13/19.
//

#include <sstream>
#include "MatrixProblem.h"

template <class T>
vector<vector<string>> MatrixProblem<T>::createMatrix(string matrixString) {
    string row;
    string index;
    stringstream ssRow(matrixString);
    vector<vector<string>> matrix;
    vector<string> splitRow;
    while (getline(ssRow,row,'$')) {
        stringstream ssCol(matrixString);
        while (getline(ssRow,index,',')) {
            splitRow.push_back(index);
        }
        matrix.push_back(splitRow);
    }
    return matrix;
}