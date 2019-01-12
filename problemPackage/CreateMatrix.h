//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_CREATEMATRIX_H
#define SECONDPROJECT_CREATEMATRIX_H


#include <string>
#include "../searchPackage/Searchable.h"

template<class T>
class CreateMatrix : public Searchable<T> {

private:
    vector<vector<State<T>>> matrix;
    vector<int> initialState;
    vector<int> goalState;
public:

    Searchable<T> *create(string data);

    vector<State<T> *> convertToStates(string data, int *rowIndex);

    unsigned long int beginAndEndIndexes(string data);

    State<T> *getInitialState() override;

    State<T> *getGoalState() override;

    vector<State<T> *> getAllPossibleStates(State<T> *state) override;

    void setStates(string data, unsigned long int index);

};


#endif //SECONDPROJECT_CREATEMATRIX_H
