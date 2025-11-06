#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The queen can be considered safe if doesn't attck on 8 way:
// . . . .
// . . . .
// . . . .
// . . . .

// But only need to check on 3 wasy we've inserting from left so no need to check right safe and also no low check only the left safe approach. 


bool isQueenSafe(int row, int column, vector<string>&board, int n) {
    // .  . .
    // . . .
    // . . .
    //       .
    // <- and . and .
    //                .

    // Left Side
    int doesRow = row;
   int doesColumn = column;
    while(doesColumn>=0) {
        if(board[doesRow][doesColumn--] == 'Q') return false;
    }


    // Top Left Side
    doesRow = row;
    doesColumn = column;
    while(doesRow>=0 && doesColumn) {
        if(board[doesRow--][doesColumn--] == 'Q') return false;
    }

    // Bottom Left:
    doesRow = row;
    doesColumn = column;
    while(doesRow < n && doesColumn>=0) {
        if(board[doesRow++][doesColumn--] == 'Q') return false;
    }
    return true;

}
void Helper(int column, vector<vector<string>>&res, vector<string>&board, int n) {
    // Base Case:
    if(column == n) {
        res.push_back(board);
        return;
    }

    for(int row = 0;row < n;row++) {
        if(isQueenSafe(row, column, board, n)) {
            board[row][column] = 'Q';
            Helper(column + 1, res, board, n);
            board[row][column] = '.';
        }
    }
}

vector<vector<string>>nQueen(int n) {
    vector<vector<string>>res;
    // Settting by default 0 on board.
    vector<string>everyboard(n, string(n, '.'));
    Helper(0, res, everyboard, n);
    return res;
}
int main() {  
    int chess = 4;
    vector<vector<string>>res = nQueen(chess);
    cout<<"["<<endl;
    for(int i = 0;i < res.size();i++) {
        cout<<"[";
        for(int j = 0;j < res[0].size();j++) {
            cout << res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]";
    return 0;
}