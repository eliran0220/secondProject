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

#define SIZE 4

class MatrixDomain : public Searchable<int> {
    int matrix[SIZE + 1][SIZE + 1];
    map <string,State<int>*> s;

public:
    MatrixDomain() {
        for (int i = 0; i <= SIZE; ++i) {
            matrix[i][0] = 2;
            matrix[i][1] = 2;
            matrix[i][2] = 2;
            matrix[i][3] = 2;
        }
        matrix[SIZE-1][SIZE-1] = 1;
    }

    State<int >* getInitialState() {
        string t = to_string(0) + "," + to_string(0);
        State<int>* temp =new State<int>(1,matrix[0][0], 0,0);
        s[t] = temp;
        return temp;
    }

    State<int >* getGoalState(){
        string t = to_string(SIZE) + "," + to_string(SIZE);
        State<int>* temp =new State<int>(1,matrix[SIZE][SIZE], SIZE,SIZE);
        s[t] = temp;
        return temp;
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
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (x == 0 && y !=SIZE){
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
                s[t] = temp;
            }
            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0 && x!=SIZE) {
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }

            v.push_back(temp);
        } else if (y == 0) {
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }
            v.push_back(temp);
        } else if(x==0) {
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }
            v.push_back(temp);
        }


        else if (x==SIZE & y == SIZE) {

            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }

            v.push_back(temp);
        }

        else if (x == SIZE) {
            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }


            v.push_back(temp);
        }else if (y == SIZE) {
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }

            v.push_back(temp);
        } else {
            t = to_string(x-1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x-1][y], x-1,y);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x+1) + "," + to_string(y);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x+1][y], x+1,y);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y-1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y-1], x,y-1);
                s[t] = temp;
            }

            v.push_back(temp);
            t = to_string(x) + "," + to_string(y+1);
            if (s.count(t)== 1) {
                temp = s[t];
            } else {
                temp = new State<int>(1,matrix[x][y+1], x,y+1);
                s[t] = temp;
            }

            v.push_back(temp);
        }
        return v;
    }
};

#endif //SECONDPROJECT_MATRIXDOMAIN_H
