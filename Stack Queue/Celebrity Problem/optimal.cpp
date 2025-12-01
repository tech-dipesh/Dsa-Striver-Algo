// The Condition Are: Everyone other shoudl know me but i should know noone. know represent 1 not know by 0.
#include <iostream>
#include <vector>
using namespace std;

int celeBrityProblem(int arr[][4], int n){
  int mainCelebrity=0;
  int top=0, bottom=n-1;
  while(top<bottom){
      if(arr[top][bottom]==1){
        top++;
      }
      // Assume the bottom is not celebrity.
      else{
        bottom--;
      }
    }
    // This probable celebrity

    for(int i=0;i<n;i++){
      // WE don't check intersection diagonal:
      if(i==top){
        continue;
      }
      // If they don't match:
      if(!(arr[top][i]==0 && arr[i][top]==1)){
        return -1;
    }
  }
  return top+1;
}
int main(){
  int arr[][4]={
  {0, 1, 1, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  };
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<celeBrityProblem(arr, n);
return 0;
}