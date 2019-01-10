//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_MATRIXDOMAIN_H
#define SECONDPROJECT_MATRIXDOMAIN_H
using namespace std;

#include <vector>
#include "../searchPackage/Searchable.h"

class MatrixDomain : public Searchable<int> {
    int matrix[10][10];
public:
    MatrixDomain() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                matrix[i][j] = j;
            }
        }
    }

    State<int >* getInitialState() {
        return new State<int >(1,matrix[0][0], 0,0);
    }

    State<int >* getGoalState(){
        return new State<int >(1,matrix[9][9], 9,9);
    }

    vector<State<int>*> getAllPossibleStates(State<int>* state) {
        int x = state->getX();
        int y = state->getY();
        vector<State<int>*> v;
        State<int>* temp;
        if (y==0 && x == 0) {
            temp = new State<int>(1,matrix[x][y+1], x,y+1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x+1][y], x+1,y);
            v.push_back(temp);
        } else if (x == 0){
            temp = new State<int>(1,matrix[x][y-1], x,y-1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x][y+1], x,y+1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x+1][y], x+1,y);
            v.push_back(temp);
        } else if (y == 0) {
            temp = new State<int>(1,matrix[x][y+1], x,y+1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x+1][y], x+1,y);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x-1][y], x-1,y);
            v.push_back(temp);
        } else if (x==9 & y == 9) {
            temp = new State<int>(1,matrix[x][y-1], x,y-1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x-1][y], x-1,y);
            v.push_back(temp);
        }

        else if (x == 9) {
            temp = new State<int>(1,matrix[x][y+1], x,y+1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x][y-1], x,y-1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x-1][y], x-1,y);
            v.push_back(temp);
        }else if (y == 9) {
            temp = new State<int>(1,matrix[x][y-1], x,y-1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x+1][y], x+1,y);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x-1][y], x-1,y);
            v.push_back(temp);
        } else {
            temp = new State<int>(1,matrix[x-1][y], x-1,y);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x+1][y], x+1,y);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x][y-1], x,y-1);
            v.push_back(temp);
            temp = new State<int>(1,matrix[x][y+1], x,y+1);
            v.push_back(temp);
        }
        return v;
    }
};

#endif //SECONDPROJECT_MATRIXDOMAIN_H
