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

class MatrixDomain : public Searchable<int> {
    int matrix[10][10];
    map <string,State<int>*> s;
public:
    MatrixDomain() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = j;
            }
        }
    }

    State<int >* getInitialState() {
        return new State<int >(1,matrix[0][0], 0,0);
    }

    State<int >* getGoalState(){
        return new State<int >(1,matrix[2][2], 2,2);
    }

    vector<State<int>*> getAllPossibleStates(State<int>* state) {
        int x = state->getX();
        int y = state->getY();
        vector<State<int>*> v;
        State<int>* temp;
        string t;
        if (y==0 && x == 0) {
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
            }
            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
            }

            v.push_back(temp);
        } else if (x == 0){
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
            }
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
            }
            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
            }

            v.push_back(temp);
        } else if (y == 0) {
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
            }

            v.push_back(temp);
        } else if (x==2 & y == 2) {

            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
            }

            v.push_back(temp);
        }

        else if (x == 2) {
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
            }


            v.push_back(temp);
        }else if (y == 2) {
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
            }

            v.push_back(temp);
        } else {
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
            }

            v.push_back(temp);
        }
        return v;
    }
};

#endif //SECONDPROJECT_MATRIXDOMAIN_H
