// Must Satisfy the 3 rules.
// Each 1-9 must occur only once on row and col
// Each 1-9 must occur once in the 3*3 subgrid.


#include <iostream>
#include <vector>
#include <string>
using namespace std;


   bool grid3(int row, int column, vector<vector<char>>board, int value){
        //checking the grid 3*3 size where is that value exist on grid or not.
         int startRow=(row/3)*3, startColumn=(column/3)*3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startColumn;j<startColumn+3;j++){
                if(board[i][j]==value) {
                    return true;
                }
            }
        }
        return false;
    }
    bool safeAdd(vector<vector<char>>board, int row, int column, int value){
    //    Whether On Row and column exist or not:
    for(int i=0;i<9;i++){
        //Row Check
        if(board[i][column]==value){
            return false;
        }
        // Column Check
        if(board[row][i]==value){
            return false;
        }
        // Grid 3 check
        if(grid3(row, column, board, value)){
            return false;
        }
    }
    return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                // Checking is that need to add
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(safeAdd(board, i, j, k)){
                            // Take Approach
                            board[i][j]=k;
                            if(isValidSudoku(board)){
                                return true;
                            }
                            else{
                                // Non Take Approach:
                                board[i][j]='.';
                            }
                        }
                    }
                    //go back if not true:
                    return false;
                }
            }
        }
        return true;
    }


    
  vector<vector<char>>Sudoku(vector<vector<char>>&arr) {
    isValidSudoku(arr);
    return arr;
  }

  int main() {
    vector<vector<char>>arr = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    //  Result should be:
    // (5, 3, 4,     6, 7, 8,       9, 1, 2),
    // (6, 7, 2,     1, 9, 5,       3, 4, 8),
    // (1, 9, 8,     3, 4, 2,      5, 6, 7),

    // (8, 5, 9,     7, 6, 1,      4, 2, 3),
    // (4, 2, 6,     8, 5, 3,      7, 9, 1),
    // (7, 1, 3,     9, 2, 4,      8, 5, 6),

    // (9, 6, 1,     5, 3, 7,      2, 8, 4),
    // (2, 8, 7,     4, 1, 9,      6, 3, 5),
    // (3, 4, 5,     2, 8, 6,      1, 7, 9).

    vector<vector<char>>res = Sudoku(arr);

    for(int i = 0;i < res.size();i++) {
      for(int j = 0;j < res[i].size();j++) {
        cout <<res[i][j] << ' ';
      }
      cout<<endl;
    }
    return 0;
  }