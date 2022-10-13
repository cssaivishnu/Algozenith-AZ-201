#include <bits/stdc++.h>
using namespace std;

int input[9][9];
int board[9][9];
bool possible = 0;

int maskUsedRow[9];
int maskUsedCol[9];
int maskUsedCell[3][3];

bool check(int i, int j, int ch){
    if(maskUsedRow[i]&(1<<ch)){
        return 0;
    }
    if(maskUsedCol[j]&(1<<ch)){
        return 0;
    }
    if(maskUsedCell[i/3][j/3]&(1<<ch)){
        return 0;
    }
    return 1;
}

void place(int i, int j, int ch){
    maskUsedRow[i] |= (1<<ch);
    maskUsedCol[j] |= (1<<ch);
    maskUsedCell[i/3][j/3] |= (1<<ch);
    board[i][j] = ch;
}

void unplace(int i, int j, int ch){
    maskUsedRow[i] ^= (1<<ch);
    maskUsedCol[j] ^= (1<<ch);
    maskUsedCell[i/3][j/3] ^= (1<<ch);
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
    if(input[i][j] != 0){
        if(!check(i,j,input[i][j]))
            return;
        place(i,j,input[i][i]);
        rec(i,j+1);
        unplace(i,j,input[i][i]);
    }
    for(int ch=1; ch<=9; ch++){
        if(check(i,j,ch)){
            place(i,j,ch);
            rec(i,j+1);
            unplace(i,j,ch);
        }
    }
}