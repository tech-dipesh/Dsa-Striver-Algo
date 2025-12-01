// The Condition Are: Everyone other shoudl know me but i should know noone. know represent 1 not know by 0.
#include <iostream>
#include <vector>
using namespace std;

int celeBrityProblem(int arr[][4], int n){
  int mainCelebrity=0;
  // vector<pair<int, int>>vt;
  // vector<int>PersonKnowMe;
  // vector<int>iKnowPerson;
  int personKnowMe[n]={0}, iKnowPerson[n]={0};

  int ColumnSave=0;
  for(int i=0;i<n;i++){
    int maxOnes=0;
  for(int j=0;j<n;j++){
      if(arr[i][j]==1){
        personKnowMe[j]++;   
        iKnowPerson[i]++;   
      }
  }
}

for(int i=0;i<n;i++){
  if(personKnowMe[i]==n-1 && iKnowPerson[i]==0){
    return i+1;
  }
}
  return -1;
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