//
// Created by afik on 1/13/19.
//

#ifndef SECONDPROJECT_SEARCHABLEMATRIX_H
#define SECONDPROJECT_SEARCHABLEMATRIX_H

#include "../utils/Point.h"
#include "Searchable.h"
#include "../utils/MyUnorderedSet.h"

enum POSITION {
    LEFT, RIGHT, UP, DOWN
};
using std::vector;


class SearchableMatrix : public Searchable<Point*> {
    vector<vector<string>> matrix;
    MyUnorderedSet<Point*> set;
    vector<string> initialState;
    vector<string> goalState;
    int row;
    int col;

private:

    State<Point*>*createState(int x, int y) {
        double cost = stod(matrix[x][y]);
        State<Point*> *state = nullptr;
        // if cost != -1
        if (cost >= 0) {
            Point* position = new Point(x, y);
            state = new State<Point*>(position, cost);
            if (set.contains(state)) {
                State<Point*> *temp = state;
                state = set.getState(temp);
                delete (temp->getData());
                delete(temp);
            } else {
                set.insertState(state);
            }
        }
        return state;
    }

    vector<POSITION> getNeighbors(int &x, int &y) {
        vector<POSITION> neighbors;
        if (x == 0 && y == 0) {
            neighbors.push_back(RIGHT);
            neighbors.push_back(DOWN);
            //x == 0 && y != col
        } else if (x == 0 && y != col) {
            neighbors.push_back(RIGHT);
            neighbors.push_back(DOWN);
            neighbors.push_back(LEFT);
        } else if (x == row && y == 0) {
            neighbors.push_back(RIGHT);
            neighbors.push_back(UP);

        } else if (x == row && y != col) {
            neighbors.push_back(RIGHT);
            neighbors.push_back(UP);
            neighbors.push_back(LEFT);
            //x !=0 && y == 0
        } else if (y == 0) {
            neighbors.push_back(RIGHT);
            neighbors.push_back(DOWN);
            neighbors.push_back(UP);
            //y == col && x == 0
        } else if (y == col && x == 0) {
            neighbors.push_back(DOWN);
            neighbors.push_back(LEFT);
        } else if (y == col && x != row) {
            neighbors.push_back(DOWN);
            neighbors.push_back(UP);
            neighbors.push_back(LEFT);
        } else if (x == row && y == col) {
            neighbors.push_back(UP);
            neighbors.push_back(LEFT);
        } else {
            neighbors.push_back(RIGHT);
            neighbors.push_back(DOWN);
            neighbors.push_back(LEFT);
            neighbors.push_back(UP);
        }
        return neighbors;
    }

    void deleteState() {
        vector<State<Point*>*> states = this->set.getPointersStates();
        for(State<Point*>* state: states) {
            //states.push_back(state);

            delete (state->getData());
            delete(state);
            //state1 = state;
        }
        this->set.initialize();

        //State<Point*>* state1;
        /*
        vector<State<Point*>*> states;
        set.swap(set);
        for(State<Point*>* state: set) {
            //states.push_back(state);

            delete (state->getData());
            delete(state);
            //state1 = state;
        }
        this->set.clear();
         */
        /*
        for (int i = 0; i < (int)states.size(); ++i) {
            delete (states[i]->getData());
            delete(states[i]);
        }
         */

    }

    void initializeMembers(vector<vector<string>> &matrix) {
        this->goalState = matrix[(int) matrix.size() - 1];
        matrix.pop_back();
        this->initialState = matrix[(int) matrix.size() - 1];
        matrix.pop_back();
        this->row = (int) matrix.size() - 1;
        this->col = (int) matrix[0].size() - 1;
        this->matrix = matrix;
    }
public:
    SearchableMatrix(vector<vector<string>> &matrix) {
        initializeMembers(matrix);
    }

    ~SearchableMatrix() {
        deleteState();
    }


    State<Point*> *getInitialState() {
        Point* position = new Point((int) stod(initialState[0]),
                                    (int) stod(initialState[1]));
        State<Point*> *initialState = new State<Point*>(position,
                                                          stod(matrix[position->getX()][position->getY()]));
        this->set.insertState(initialState);
        return initialState;
    }

    State<Point*> *getGoalState() {
        Point* position = new Point((int) stod(goalState[0]),
                                    (int) stod(goalState[1]));
        State<Point*> *goalState = new State<Point*>(position,
                                                          stod(matrix[position->getX()][position->getY()]));
        this->set.insertState(goalState);
        return goalState;
    }



    vector<State<Point*> *> getAllPossibleStates(State<Point*> *state) {
        vector<State<Point*> *> possibleNeighbors;
        Point* data = state->getData();
        State<Point*>* tempState = nullptr;
        int x = data->getX();
        int y = data->getY();
        vector<POSITION> neighbors = getNeighbors(x, y);
        for (POSITION position : neighbors) {
            switch (position) {
                case LEFT : {
                    tempState = createState(x, y-1);
                    break;
                }
                case RIGHT: {
                    tempState = createState(x, y + 1);
                    break;
                }
                case UP: {
                    tempState = createState(x - 1, y);
                    break;
                }
                case DOWN: {
                    tempState = createState(x + 1, y);
                    break;
                }
                default: {

                }
            }
            if (tempState != nullptr) {
                possibleNeighbors.push_back(tempState);
            }
        }
        return possibleNeighbors;
    }


    string pathToString(vector<State<Point*>*> path) {
        string pathString = "{";
        Point* prev;
        Point* current;
        for (int i = 1; i < (int)path.size(); ++i) {
            current = path[i]->getData();
            prev = path[i]->getCameFrom()->getData();
            if (current->getX() > prev->getX()) {
                pathString += "Down,";
            } else if (current->getX() < prev->getX()) {
                pathString += "Up,";
            } else if (current->getY() > prev->getY()) {
                pathString += "Right,";
            } else if (current->getY() < prev->getY()) {
                pathString += "Left,";
            }
        }
        pathString[pathString.size() -1] = '}';
        return pathString;
    }


    void setAndInitialize(vector<vector<string>> &matrix) {
        initializeMembers(matrix);
        this->deleteState();

    }


};

#endif //SECONDPROJECT_SEARCHABLEMATRIX_H
