// count inversion solution: (5, 3) (5, 2), (5, 4)
#include <iostream>
#include <vector>
using namespace std;


void mergetwoSortedArray(int low, int medium, int high, vector<int>&res){
  vector<int>temp;
  int i=low, j=medium;
  while(i<=medium && j<=high){
      if(res[i]<res[j]){
          temp.push_back(res[i]);
          i++;
      }
      else{
        temp.push_back(res[j]);
        j++;
      }
  }

  // there might still some element left:
  while(i<=medium){
    temp.push_back(res[i++]);
  }
  while(j<=high){
    temp.push_back(res[j++]);
  }

  // Move back to the original array:
  for(int i=low;i<high;i++){
      res[i]=temp[i-low];
  }
}
void mergeSort(int low, int high, vector<int>res, int n){
  if(low==high)return;
    int medium=low+high;
    mergeSort(low, medium, res, n);
    mergeSort(medium+1, high, res, n);
    mergetwoSortedArray(low, medium, high, res);
}
vector<int>countInversion(vector<int>&res, int n){
  vector<vector<int>>vt;
  int low=0, high=n-1;
  mergeSort(low, high, res, n);
  return res;
}
int main(){
  vector<int>res={5, 3, 2, 4, 1};
  // the answer i want is: 5, 3, 5, 2, 5, 4, 5, 1.  3, 2), 3, 1). 2, 1.) 4, 1.
  int n=res.size();
  vector<int>out=countInversion(res, n);
  for(int i:out){
    cout<<i<<" ";
  }
return 0;
}