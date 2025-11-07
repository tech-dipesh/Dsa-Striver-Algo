#include <bits/stdc++.h>
using namespace std;
// arred path so important so we don't have to go upword or that previous stesp

// we should check with is that inside boundary with i<n or j<n
bool canMoveDown(int row, int column, vector<vector<int>>&arr, int n){
  if(row+1<n && arr[row+1][column]==1){
    return true;
  }
  else {
    return false;
  }
}
bool canMoveLeft(int row, int column, vector<vector<int>>&arr, int n){
  if(column-1>=0 && arr[row][column-1]==1){
    return true;
  }
  else {
    return false;
  }
}

bool canMoveRight(int row, int column, vector<vector<int>>&arr, int n){
  // Every element shouldn't be arred prevously so take the arr element.
  if( column+1<n &&arr[row][column+1]==1){
    return true;
  }
  else {
    return false;
  }
}
bool canMoveUp(int row, int column, vector<vector<int>>&arr, int n){
  if(row-1>=0 && arr[row-1][column]==1 ){
    return true;
  }
  else {
    return false;
  }
}




void Help(int row, int column,  vector<vector<int>>&arr, int n, vector<string>&res, string st){
  if(row==n-1  && column ==n-1){
      res.push_back(st);
      return;
  }
    arr[row][column]=0;
    if(canMoveDown(row, column, arr, n)){
      Help(row+1, column, arr,  n, res, st+'D');
    }
    
    if(canMoveLeft(row, column, arr, n)){
      Help(row, column-1, arr,  n, res, st+"L");
    }
    if(canMoveRight(row, column, arr, n)){
      Help(row, column+1, arr,  n, res, st+'R');
    }
    
    
    if(canMoveUp(row, column, arr, n)){
      Help(row-1, column, arr,  n, res, st+"U");
    }
    arr[row][column]=1;
}
vector<string>Rat( vector<vector<int>>&arr, int n){
  vector<string>res;
  vector<string>vt;
  // First path should always be the 1 to start.
  if(arr[0][0]==1){
    Help(0, 0, arr, n, res, "");
  }
  return res;
}

int main(){
  int n=4;
  vector<vector<int>>arr={
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1},
  };
  // Result should be:
  // DDRDRR, DRDDRR
  vector<string>res=Rat(arr, n);
  for(int i=0;i<res.size();i++){
      cout<<res[i];
  }
return 0;
}