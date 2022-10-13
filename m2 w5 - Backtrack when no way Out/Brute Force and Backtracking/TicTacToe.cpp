#include <bits/stdc++.h>
using namespace std;

struct Board{
    char board[3][3];
    Board(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board[i][j] = ' ';
            }
        }
    }
    char getCell(int x, int y){
        return board[x][y];
    }
    void setCell(int x, int y, char Player){
        // assert(board[x][y] == ' ');
        board[x][y] = Player;
    }
    char checkEnd(){
        for(int i=0; i<3; i++){
            if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]!=' ')){
                return board[i][0];
            }
        }
        for(int i=0; i<3; i++){
            if((board[0][i]==board[1][i]) && (board[1][i]==board[2][i]) && (board[0][i]!=' ')){
                return board[0][i];
            }
        }
        if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && (board[0][0]!=' ')){
            return board[0][0];
        }
        if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && (board[0][2]!=' ')){
            return board[0][2];
        }
        int cnt=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] == ' '){
                    cnt++;
                }
            }
        }
        if(cnt==0){
            return 'D';
        }
        else{
            return 'C';
        }
    }
    void print_board(){
        cout<<endl;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

inline char OtherPlayer(char Player){
    return Player^'X'^'O';
}

char decide_state(Board board, char Player, bool printWinMove){
    // board.print_board();
    char isAlreadyEnded = board.checkEnd();
    if(isAlreadyEnded != 'C'){
        if(isAlreadyEnded == Player){
            return 'W';
        }
        else if(isAlreadyEnded == 'D'){
            return 'D';
        }
        else{
            return 'L';
        }
    }
    else{
        int possible = 0;
        int losingMoves = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board.getCell(i,j) == ' '){
                    possible++;
                    board.setCell(i,j,Player);
                    // cout<<"set "<<i<<","<<j<<" : "<<Player<<endl;
                    char new_result = decide_state(board,OtherPlayer(Player),0);
                    board.setCell(i,j,' ');
                    // cout<<"unset "<<i<<","<<j<<" : "<<Player<<endl;
                    if(new_result == 'W'){
                        losingMoves++;
                    }
                    else if(new_result == 'L'){
                        if(printWinMove)    cout<<i<<" "<<j<<endl;
                        return 'W';
                    }
                }
            }
        }
        if(possible == losingMoves){
            return 'L';
        }
        else{
            return 'D';
        }
    }
}

Board CreateInput(){
    string s;
    Board b;
    cout<<"Enter Board Config.: \n";
    for(int i=0; i<3; i++){
        getline(cin,s);
        b.setCell(i,0,s[0]);
        b.setCell(i,1,s[1]);
        b.setCell(i,2,s[2]);
    }
    return b;
}

int main(){
    Board temp = CreateInput();
    cout<<"Input Current Move (X/O): ";
    char ch;
    cin>>ch;
    temp.print_board();
    cout<<decide_state(temp,ch,1);
}

