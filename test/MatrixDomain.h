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

#define SIZE 10


class MatrixDomain : public Searchable<Point *> {


    int matrix[SIZE + 1][SIZE + 1]{
            {4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8},
            { 4, 0, 10, 8, 1, 0, 5, 5, 7, 8, 4 },
            { 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7 },
            { 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7 },
            { 0, 3, 7, 3, 7, 10, 4, 8, 9, 1, 1 },
            { 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9 },
            { 6, 9, 8, 1, 10, 3, 9, 8, 3, 4, 8 },
            { 10, 8, 0, 2, 3, 8, 0, 10, 10, 2, 7 },
            { 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1 },
            { 7, 7, 5, 10, 8, 10, 1, 6, 9, 9, 1 },
            { 5, 10, 1, 10, 7, 7, 3, 10, 8, 0, 6 },

    };

    /*
string matrix[SIZE + 1][SIZE + 1]{
        {"4", "2", "9", "5", "7", "0", "7", "6", "3", "7", "8"},
        {"4", "0", "10", "8", "1", "0", "5", "5", "7", "8", "4"},
        {"4", "5", "2", "8", "1", "1", "9", "3", "3", "0", "7"},
        {"3", "3", "6","2", "8", "9", "6", "8", "3", "5", "70", "3", "7", "3", "7", "10", "4", "8", "9", "1", "1"},
        {"7", "3", "2", "3", "5", "0", "2", "1", "6", "0", "9"},
        {"6", "9", "8", "1", "10", "3", "9", "8", "3", "4","8"},
        {"10", "8", "0", "2", "3", "8", "0", "10", "10", "2", "7"},
        {"5", "7", "0", "8", "8", "8", "0", "3", "4","5","1"},
        {"7", "7", "5", "10", "8", "10", "1", "6", "9", "9", "1"},
        {"5", "10", "1", "10", "7", "7", "3", "10", "8", "0", "6"},

};
 */


    map<string, State<Point *> *> s;


public:
    MatrixDomain() {

    }


    State<Point *> *getInitialState() {
        string t = to_string(1) + "," + to_string(1);
        State<Point *> *temp = new State<Point *>(new Point(0, 0), matrix[0][0]);
        s[t] = temp;
        return temp;
    }

    State<Point *> *getGoalState() {
        string t = to_string(2) + "," + to_string(2);
        State<Point *> *temp = new State<Point *>(new Point(36, 36), matrix[36][36]);
        s[t] = temp;
        return temp;
    }

    vector<State<Point *> *> getAllPossibleStates(State<Point *> *state) {
        int x = state->getData()->getX();
        int y = state->getData()->getY();
        vector<State<Point *> *> v;
        State<Point *> *temp;
        string t;
        if (y == 0 && x == 0) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (x == 0 && y != SIZE) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0 && x != SIZE) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0) {
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }
            v.push_back(temp);
        } else if (x == 0) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }
            v.push_back(temp);
        } else if (x == SIZE & y == SIZE) {

            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (x == SIZE) {
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }


            v.push_back(temp);
        } else if (y == SIZE) {
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
        } else {
            t = to_string(x - 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x - 1, y), matrix[x - 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x + 1) + "," + to_string(y);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x + 1, y), matrix[x + 1][y]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y - 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y - 1), matrix[x][y - 1]);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y + 1);
            if (s.count(t) == 1) {
                temp = s[t];
            } else {
                temp = new State<Point *>(new Point(x, y + 1), matrix[x][y + 1]);
                s[t] = temp;
            }

            v.push_back(temp);
        }
        vector<State<Point *> *> vtemp;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]->getPositionCost() != -1) {
                vtemp.push_back(v[i]);
            }
        }
        return vtemp;
    }

    string pathToString(vector<State<Point *> *> path) {
        return "";
    }
};

#endif //SECONDPROJECT_MATRIXDOMAIN_H
