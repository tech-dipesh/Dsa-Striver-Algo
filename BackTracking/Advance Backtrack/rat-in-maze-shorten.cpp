#include <bits/stdc++.h>
using namespace std;


bool isRange(int nextrow, int nextcolumn, int n, vector<vector<int>>&arr, vector<vector<int>>&visitcheck){
  // 1 1 0
  // 0 1  1
  // it should be inside the range from al 4 side, and make sure that upcoming value is set to 1 and also that value is not yet visited.
  if(nextrow>=0 &&nextcolumn>=0 && nextrow<n && nextcolumn<n && arr[nextrow][nextcolumn]==1 && !visitcheck[nextrow][nextcolumn]){
    return true;
  }
  return false;
}



void Help(int row, int column,  vector<vector<int>>&arr, int n, vector<string>&res, string st, vector<vector<int>>&visitcheck, int comingrow[], int comingocolumn[]){
  if(row==n-1  && column ==n-1){
      res.push_back(st);
      return;
  }

  string move="DLRU";
  for(int i=0;i<4;i++){
    int nextrow=row+comingrow[i];
    int nextcolumn=column+comingocolumn[i];
    if(isRange(nextrow, nextcolumn, n, arr, visitcheck)){
        // First Take:
        visitcheck[row][column]=1;
        Help(nextrow, nextcolumn, arr, n, res, st+move[i], visitcheck, comingrow, comingocolumn);
        visitcheck[row][column]=0;
    }
  }
}
vector<string>Rat( vector<vector<int>>&arr, int n){
  vector<string>res;
  // By default set to 1.
  vector<vector<int>>visitcheck(n, vector<int>(n, 0));
  // Like for the dlru, i(row) order. now for the j(column) order.
  int arri[]={1, 0, 0, -1};
  int arrj[]={0, -1, +1, 0};

  // First always should be 1 to start.
  if(arr[0][0]==1){
    Help(0, 0, arr, n, res, "", visitcheck, arri, arrj);
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
      cout<<res[i]<<endl;
  }
return 0;
}