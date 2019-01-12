//
// Created by eliran on 1/12/19.
//

#include "CreateMatrix.h"

template<class T>
Searchable<T> *CreateMatrix<T>::create(string data) {
    string copyData = data;
    int index = 0;
    string row = "";
    int rowIndex = 0;
    int *p = &rowIndex;
    vector<State<T> *> vec;
    int startEndIndex = startEndIndex(data);

    while (index != startEndIndex) {
        index = static_cast<int>(copyData.find(':'));
        row = copyData.substr(0, index);
        vec = convertToStates(copyData, p);
        this->matrix.push_back(vec);
        copyData = copyData.substr(index + 1, copyData.length() - 1);
    }
    // עכשיו השניים האחרונים זה הסטייט התחלה וסוף זה יראה ככה:
    // 2,1,3:7,8,5:2,3,6 : 1,2:6,7: this 2 are the last, NOT STATES TO INCLUDE IN VECTOR

}

template<class T>
vector<State<T> *> CreateMatrix<T>::convertToStates(string data, int *rowIndex) {
    vector<State<T> *> vec;
    State<T> state;
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != ',') {
            state = new State<T>(state, data[i] - '0', rowIndex, i);
        } else {
            continue;
        }
        vec.push_back(state);
    }
    (*rowIndex)++;
    return vec;
}

template<class T>
unsigned long int CreateMatrix<T>::beginAndEndIndexes(string data) {
    int counter = 0;
    for (unsigned long int i = data.length(); i > 0; i--) {
        if (counter == START_END_INDEXES) {
            return i;
        }
        if (data[i] == ':') {
            counter++;
        }
    }
}


template<class T>
void CreateMatrix<T>::setStates(string data, unsigned long int index) {
    this->initialState.push_back(data[index + 1]);
    this->initialState.push_back(data[index + 3]);
    this->goalState.push_back(data[index + 5]);
    this->goalState.push_back(data[index + 7]);
}


//**************************************************************************************************************8
template<class T>
State<T> *CreateMatrix<T>::getInitialState() {
    return this->matrix.at(this->initialState.at(0),this->initialState.at(1));
}

template<class T>
State<T> *CreateMatrix<T>::getGoalState() {
    return nullptr;
}

template<class T>
vector<State<T> *> CreateMatrix<T>::getAllPossibleStates(State<T> *state) {
    return vector<State<T> *>();
}




