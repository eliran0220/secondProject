//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_MATRIXDOMAIN_H
#define SECONDPROJECT_MATRIXDOMAIN_H

using namespace std;

#include <vector>
#include <string>
#include <map>
#include "../searchPackage/Searchable.h"

#define SIZE 36


class MatrixDomain : public Searchable<Point*> {

    int matrix[SIZE + 1][SIZE + 1]{
            {0, 0, 8, 6, 8, 2, 10, 2, 4, 1, 9, 9, 5, 10, 1, 1, 1, 0, 7, 3, 1, 6, 9, 3, 9, 7, 7, 9, 5, 6, 4, 5, 1, 6, -1, 1, 7},
            {0, 10, 2, 3, 0, 5, 2, 1, 10, 2, 4, 5, 4, 3, 3, 4, 10, 2, 3, 9, 6, 9, 1, 6, 7, 7, 5, 8, 7, 2, -1, 3, 2, 5, -1, 9, 2},
            {0, 5, 8, 9, 0, 1, 2, 4, 7, 8, 2, 9, 8, 4, 2, 2, 10, 8, 8, 2, 3, 3, 1, 5, 10, -1, 2, 7, 1, 4, -1, -1, -1, 0, -1, 5, 6},
            {0, 6, 2, 4, 10, 8, 9, 9, 7, 1, 0, 8, 8, 2, 4, 2, 1, 7, 6, 8, 3, -1, 8, 1, 8, 6, 1, 3, 3, 0, 7, 3, 4, 0, 9, 10, 0},
            {0, 0, 0, 10, 7, 8, 1, -1, 5, 8, 8, 1, 1, 5, 8, 9, 9, 1, 8, 5, 1, 8, 4, 5, 4, 5, 8, 7, 6, 6, 8, 2, 0, 8, 8, 8, 8},
            {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {10, 5, 1, 7, 5, 10, 6, 6, 6, 5, 8, 9, 4, 3, 9, 0, 10, 4, 9, 5, 3, 10, 3, 9, 3, 4, -1, 8, 5, 0, 10, 5, 2, 3, 7, 6, 0},
            {1, 10, 0, 9, 9, 1, 0, 2, -1, 0, 6, 10, 1, 10, 10, 0, 7, 5, 2, 7, 7, 6, 9, 0, 3, 2, 4, 9, -1, 5, 7, -1, 9, 8, 6, 3, 0},
            {10, 0, 1, 0, 6, 10, 2, 6, -1, -1, 3, 9, 9, 8, 3, 7, 4, 3, 4, 5, -1, 9, 3, 5, 10, 2, 3, -1, 10, 2, 0, 0, 7, 8, -1, 10, 0},
            {7, 4, 8, 0, 8, 7, -1, 3, -1, 0, -1, 7, 9, 6, 7, 6, 1, 10, 6, 0, 5, 8, 1, 2, 8, 3, 0, 10, 7, 10, 1, 2, 6, 9, 7, 3, 0},
            {6, 0, 4, 7, 7, 10, 8, 0, 1, 6, 2, 6, 4, 6, 6, 7, 5, 5, 8, 2, 10, 2, 6, 8, 10, 8, 10, 9, 9, 0, 2, 0, 9, 6, 5, 4, 0},
            {7, 0, 9, 4, 7, 4, 5, 8, 2, 2, 4, 3, 6, 1, 4, 7, 4, 9, -1, 5, 10, 3, 4, 9, 7, 10, 3, 5, 2, 9, 7, 0, -1, 5, 10, 7, 0},
            {6, 6, 8, 2, 10, 4, -1, 4, -1, 2, 9, 6, 5, 7, 0, 4, 9, 10, 4, 9, 0, 9, 2, 6, 7, 1, 10, 5, 6, 6, 5, 10, 4, 5, 7, 6, 0},
            {3, 9, 1, 4, 8, 2, -1, 2, -1, 7, 8, 3, 6, 6, 9, 4, 6, -1, 4, -1, 1, 4, 5, 9, 2, 0, 1, 9, 3, 7, 0, 1, 10, 5, 6, -1, 0},
            {10, 8, 9, 1, 10, 7, 0, 10, 9, 10, 10, 1, 9, 3, 7, 5, 9, 3, 8, 6, 6, 7, 1, 1, 5, 6, 2, 7, 2, 3, 4, 9, 9, 9, 10, 2, 0},
            {10, 2, 8, 5, -1, 2, 5, 8, 7, 0, 5, 1, 3, 0, 4, 3, 9, 5, 9, 7, 7, 2, -1, 2, 8, 4, 1, 5, 9, 6, 0, 4, 0, 9, 1, -1, 0},
            { 4, 4, 5, 10, 2, 5, 2, 3, 2, 2, 0, 4, 5, 3, 10, 9, 3, 6, 2, 9, 9, 1, 4, 3, 2, 10, 3, 1, 8, 6, 7, 4, 6, 7, 5, 1, 0},
            { 4, -1, 9, 7, 5, 5, 3, 10, 8, 3, 3, 9, 5, 6, 1, 10, 7, 4, 9, 9, 5, 9, 8, 9, 9, 1, 6, 9, 7, 5, 3, 5, 4, 6, 3, 0, 0 },
            { 9, 0, 1, 5, 1, 3, 8, 0, 1, 2, 5, 0, 9, 9, 3, 4, 0, 2, 0, 10, 7, 0, 10, 3, 7, 0, 8, 9, 0, 1, 0, 2, 0, 3, 4, 10, 0 },
            { 6, 6, 1, -1, 10, 7, 1, 5, 2, 3, 5, 8, 10, 7, 3, 0, 6, 8, 5, 1, 10, 0, 6, 6, 8, 0, 7, -1, 0, 7, 9, 5, 5, 7, 1, 5, 0 },
            { 3, 6, 4, 10, 7, 8, 2, 9, 8, 3, 4, 3, 8, 7, 6, 6, 2, 7, 9, 6, 6, 0, 0, 6, 5, 9, 2, 3, 3, 3, 10, 7, 10, 6, 7, 2, 0 },
            { 10, 1, 2, -1, 7, 0, 5, 10, 2, 8, 4, 7, 8, 7, 7, 5, 2, 5, 7, 4, 2, 4, 3, 10, 6, 8, 5, 2, 1, 4, 9, 0, 1, 4, 0, 2, 0 },
            { 10, 4, 9, 10, 9, 10, 9, 10, 7, 9, 0, 1, 6, 5, 3, 0, 6, 4, 7, 9, 10, 4, 4, 9, 8, 1, 7, 8, 0, 0, 9, 3, 8, 5, 3, 7, 0 },
            { 7, 4, 6, 0, 7, 7, 8, 6, 8, 9, 1, 2, 9, 3, 4, 9, 0, 8, 10, 1, 0, 5, 9, 8, 7, 9, 3, 3, 10, 7, 9, 8, 3, 2, 10, 3, 0 },
            { 9, 2, 1, 8, 4, 8, 1, 8, 6, 0, 3, 9, 1, 7, 3, 8, 5, 8, 5, 4, 4, 10, 5, 0, 9, 2, 1, 9, 0, 6, 8, 4, 4, -1, -1, -1, 0 },
            { 7, 7, 0, 8, 4, 4, 1, 9, 8, 0, 9, 8, 10, 5, 5, 2, 8, 1, 5, 9, 9, 10, 6, 5, 9, 8, 1, 4, 4, 7, 6, 10, 4, 9, 1, 8, 0 },
            { 1, 6, 7, 2, 8, 7, 6, 10, 1, 0, 9, 5, 10, 7, 6, 4, 9, 2, 2, 5, 1, 9, 2, 1, 6, 8, 3, 0, 8, 1, 0, 6, 9, 8, 3, -1, 0 },
            { 5, 5, 7, 10, 1, 8, 4, 4, 0, 10, 10, 1, 1, 2, 8, 4, 8, 0, 6, 8, 3, 8, 5, 5, 3, 8, 10, 8, 5, 10, 1, 10, 2, 5, 0, -1, 0 },
            { 9, 0, 8, 1, 3, 5, 6, 0, 7, 9, 2, 1, 6, 8, 1, 2, 1, 5, 0, 0, 10, 0, 4, 9, 0, 0, 4, 7, 4, 3, 6, 9, 6, 5, 10, 0, 0 },
            { 1, 7, 2, 0, 5, 6, 10, 6, 6, 10, 10, 2, 1, 0, 2, 7, 1, 1, 8, 3, 5, 0, 10, 1, 8, 2, 6, 3, 0, 9, 3, 2, 4, 9, 8, 5, 0 },
            { 1, 3, 2, 1, 1, 6, 3, -1, 0, 4, 8, 7, 3, 4, 7, 6, 1, 9, 7, 0, 10, 4, 6, 5, 7, 8, 2, 10, 1, 2, 6, 7, 8, 2, 3, 10, 0 },
            { 3, 6, 4, 9, 2, 10, 9, 8, 2, 7, 6, 6, 8, 3, 7, 9, 3, 7, 0, 0, 3, 2, 4, 5, 8, 7, 2, 10, 10, 4, 10, 2, 10, -1, 6, -1, 0 },
            { 6, 4, 4, 10, 8, 3, 0, 7, 3, 8, 4, 7, 3, 1, 5, 6, 0, 2, 2, 6, 2, 1, 4, 3, 1, 4, 0, 5, 7, 1, 6, 5, 10, 7, 5, -1, 0 },
            { 4, 8, 0, 2, 10, 9, 3, 3, 8, 7, 7, 8, 10, 6, 10, 2, 4, 10, 0, 10, 7, 8, 7, 1, 9, 5, 10, 4, 2, 0, 9, 7, 1, 8, 3, 8, 0 },
            { 2, 2, 5, 1, 7, 1, 8, 2, 10, 3, 10, 5, 7, 9, 10, 10, 10, 0, 4, 4, 2, 10, 2, 0, 1, 6, 9, 10, 7, 4, 6, 10, 8, 4, 8, 0, 00 },
            { 3, 1, 0, 8, 1, 4, 7, 9, 3, 7, 3, 6, 6, 6, 3, 9, 9, 3, 9, 3, 3, 7, 5, 10, 0, 8, 2, 2, 5, 4, 9, 8, 5, 3, 2, 6, 0 },
            { 10, 1, 9, 5, 9, 2, 6, 10, 3, 4, 10, -1, 10, 7, 9, 2, 1, 2, 0, 4, 6, 10, 2, 0, 0, 3, 4, 1, 4, 4, 0, 4, 10, 6, 2, 5, 0 },
    };

    /*
    int matrix[SIZE + 1][SIZE + 1]{
            {1,-1,1},
            {2,9,-1},
            {12,45,0}};
    */
    map<string, State<Point*> *> s;


public:
    MatrixDomain() {

    }


    State<Point*> *getInitialState(){
        string t = to_string(0) + "," + to_string(0);
        State<Point*>  *temp = new State<Point*>(new Point(0,0), matrix[0][0]);
        s[t] = temp;
        return temp;
    }

    State<Point*> *getGoalState() {
        string t = to_string(SIZE) + "," + to_string(SIZE);
        State<Point*> *temp = new State<Point*>(new Point(SIZE,SIZE), matrix[SIZE][SIZE]);
        s[t] = temp;
        return temp;
    }

    vector<State<Point*> *> getAllPossibleStates(State<Point*> *state) {
        int x = state->getData()->getX();
        int y = state->getData()->getY();
        vector<State<Point*> *> v;
        State<Point*> *temp;
        string t;
        if (y == 0 && x == 0) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (x == 0 && y != SIZE) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0 && x != SIZE) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }
            v.push_back(temp);
        } else if (x == 0) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }
            v.push_back(temp);
        } else if (x == SIZE & y == SIZE) {

            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (x == SIZE) {
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }


            v.push_back(temp);
        } else if (y == SIZE) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else {
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x-1,y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x+1,y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y-1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point*>(new Point(x,y+1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
        }
        vector<State<Point*> *> vtemp;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]->getPositionCost()!= -1) {
                vtemp.push_back(v[i]);
            }
        }
        return vtemp;
    }

    string pathToString(vector<State<Point*>*> path) {
        return "";
    }
};

#endif //SECONDPROJECT_MATRIXDOMAIN_H
