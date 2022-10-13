#include <bits/stdc++.h>
using namespace std;

int board[9][9];
bool possible = 0;

bool check(int i, int j, int ch){
    for(int k=0; k<9; k++){
        if(k!=j && ch==board[i][k])
            return 0;
        if(k!=i && ch==board[k][j])
            return 0;
    }
    int basex = (i/3)*3;
    int basey = (j/3)*3;
    for(int delx=0; delx<3; delx++){
        for(int dely=0; dely<3; dely++){
            if(((basex+delx!=i) || (basey+dely!=j)) && ch==board[basex+delx][basey+dely]){
                return 0;
            }
        }
    }
    return 1;
}

void place(int i, int j, int ch){
    board[i][j] = ch;
}

void unplace(int i, int j, int ch){
    board[i][j] = 0;
}

void rec(int i, int j){
    if(i==9){
        possible = 1;
        return;
    }
    if(j==9){
        rec(i+1,0);
    }
    if(board[i][j] != 0){
        rec(i,j+1);
    }
    for(int ch=1; ch<=9; ch++){
        if(check(i,j,ch)){
            place(i,j,ch);
            rec(i,j+1);
            unplace(i,j,ch);
        }
    }
}