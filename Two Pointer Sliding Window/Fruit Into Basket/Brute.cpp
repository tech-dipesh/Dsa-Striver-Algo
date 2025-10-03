#include <iostream>
#include <set>
using namespace std;
    
int Fruit(int arr[], int n){
  int maxSize=0;
  for(int i=0;i<n;i++){
    set<int>st;
    for(int j=i;j<n;j++){
      st.insert(arr[j]);
      if(st.size()<=2){
        maxSize=max(maxSize, j-i+1);
      }
      else{
        break;
      }
    }
  }
  return maxSize;
}
int main(){
  int arr[]={3, 2, 3, 6, 9, 9, 9, 6, 8, 6, 2, 8, 2, 5, 1, 7};
  int n1=sizeof(arr)/sizeof(arr[0]);
  cout<<Fruit(arr, n1);
return 0;
}