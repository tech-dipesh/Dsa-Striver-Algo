// Must Satisfy the 3 rules.
// Each 1-9 must occur only once on row and col
// Each 1-9 must occur once in the 3*3 subgrid.


#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool checkingGrid33(vector<vector<char>> grid, int row, int column, char valuechecking) {
  int startingRow = (row / 3) * 3;
  int startingColumn = (column / 3) * 3;
  
  for(int i = startingRow;i < startingRow + 3;i++) {
    for(int j = startingColumn;j < startingColumn + 3;j++) {
      if(grid[i][j] == valuechecking) {
        return true;
      }
    }
  }
  return false;
}




bool CheckSafeColumnRow(int row, int column, vector<vector<char>> vt, char value) {
  for(int i = 0;i < 9;i++) {
    // Checking the column side:
    if(vt[i][column] == value) {
      return false;
    }

    // row Side:
    if(vt[row][i] == value) {
      return false;
    }
    
    // 3*3 grid;
    if(checkingGrid33(vt, row, column, value)) {
      return false;
    }


  }
  return true;
}



// We've to take possiblites check that all valid number can be there.
bool backTrack(vector<vector<char>>& arr) {
  
  for(int i = 0;i < 9;i++) {
    for(int j = 0; j < 9;j++) {
      if(arr[i][j] == '.') {
        // Checking which number is fit there:
        for(char k = '1';k <= '9';k++) {
          if(CheckSafeColumnRow(i, j, arr, k)) {
            // Take Approach:
            arr[i][j] = k;
            if(backTrack(arr)) {
              return true;
            }
            else {
              // Take Back/Non Take:
              arr[i][j] = '.';
            }
          }
          }
          // Go back:
          return false;
        }
      }
    }
        // Go back to previous decision.
        return true;
  }
      
      
  vector<vector<char>>Sudoku(vector<vector<char>>&arr) {
    backTrack(arr);
    return arr;
  }

  int main() {
    // vector<vector<char>>arr = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    //   };
      vector<vector<char>>arr = {
        {'.','8','7','6','5','4','3','2','1'},
        {'2','.','.','.','.','.','.','.','.'}, 
        {'3','.','.','.','.','.','.','.','.'}, 
        {'4','.','.','.','.','.','.','.','.'}, 
        {'5','.','.','.','.','.','.','.','.'},
         {'6','.','.','.','.','.','.','.','.'},
          {'7','.','.','.','.','.','.','.','.'},
           {'8','.','.','.','.','.','.','.','.'}, 
           {'9','.','.','.','.','.','.','.','.'}
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