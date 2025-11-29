#include <iostream>
#include <vector>
using namespace std;
int largestHistogram(vector<int>arr, int n){
  int highHistoGram=0;
  for(int i=0;i<n;i++){
    int j=i, k=i;
    int leftCount=0, rightCount=0;
    j--;k++;
    while(j>=0 && arr[i]<=arr[j]){
      leftCount++;
      j--;
    }
    
    while(k<n && arr[i]<=arr[k]){
      rightCount++;
      k++;
    }
      int eachHistogram=(leftCount+rightCount+1)*arr[i];
      highHistoGram=max(highHistoGram, eachHistogram);
  }
  return highHistoGram;
}


int maximumRectangle(int arr[][5], int row, int column){
  vector<vector<int>>suffix(row, vector<int>(column, 0));
  int maxRes=0;
  for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<column;j++){
      if(arr[i][j]==1){
        sum++;
      }
      else{
        sum=0;

      }
      suffix[i][j]=sum;
    }
  }

      for(int i = 0; i < row; i++){
        // Convert row to vector
        vector<int> currentRow;
        for(int j = 0; j < column; j++){
            currentRow.push_back(suffix[i][j]);
        }
        int rowMax = largestHistogram(currentRow, column);
        maxRes = max(maxRes, rowMax);
    }
  vector<int>res(column);
for(int j=0;j<column;j++){
  res[j]=suffix[0][j];
}
  return maxRes;  
}


int main(){
   int arr[][5]={
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0},
   }; 
   int row=sizeof(arr)/sizeof(arr[0]);
   int column=sizeof(arr[0])/sizeof(arr[0][0]);
   
   cout<<maximumRectangle(arr, row, column);
  maximumRectangle(arr, row, column);
return 0;
}