#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The queen can be considered safe if doesn't attck on 8 way:
// . . . .
// . . . .
// . . . .
// . . . .


void Helper(int column, vector<vector<string>>&res, vector<string>&board, int n,
  // For Checking Attack:
  vector<int>&upperLeft, vector<int>&lowerLeft, vector<int>&centerSide
) {
  // Base Case:
  if(column == n) {
    res.push_back(board);
    return;
  }
  
  for(int row = 0;row < n;row++) {
      // Need 3 way prevoius check with the hash approach.
      if(
        // For the Left Row:
        upperLeft[row]==0 &&

        //Left Below:
        lowerLeft[row+column]==0 &&
        //Left top:
        upperLeft[row+column]==0 
       ){
            board[row][column] = 'Q';
            upperLeft[row]=1;
            lowerLeft[row+column]=1;
            upperLeft[row+column]=1;
            Helper(column + 1, res, board, n, upperLeft, lowerLeft, centerSide);

            //Going back to possiblities.
            board[row][column] = '.';
            upperLeft[row]=0;
            lowerLeft[row+column]=0;
            upperLeft[row+column]=0;
        }
    }
}

vector<vector<string>>nQueen(int n) {
    vector<vector<string>>res;
    vector<string>board;
    // Settting by default 0 on board.

    // need the String of each 
    string str(n, '.');
    for(int i = 0;i < n;i++) {
        board[i]=str;
    }
    vector<int>upperLeft(n*2, 0);
    vector<int>lowerLeft(n, 0);
    vector<int>centerSide(n, 0);
    Helper(0, res, board, n, upperLeft,  lowerLeft, centerSide);
    return res;
}
int main() {  
    int chess = 4;
    vector<vector<string>>res = nQueen(chess);
    for(int i = 0;i < res.size();i++) {
        for(int j = 0;j < res[0].size();j++) {
            cout << res[i][j];
        }
    }
    return 0;
}