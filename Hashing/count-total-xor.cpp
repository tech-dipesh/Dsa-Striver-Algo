#include <iostream>
#include <unordered_map>
using namespace std;

int totalXor(int arr[], int n, int m){
  int count=0;
  unordered_map<int, int>mp;
  int Xor=0;
  for(int i=0;i<n;i++){
      Xor^=arr[i];
      if(Xor==m){
        count++;
      }
      if(mp.find(Xor^m)!=mp.end()){
          count+=mp[Xor^m];
      }
      mp[Xor]++;
  }
  return count;
}
int main(){
  int arr[]={4, 2, 2, 6, 4};
  int n=sizeof(arr)/sizeof(arr[0]);
  int m=6;
  

  int a1[]={5, 6, 7, 8, 9};
  int m1=5;
  int n1=sizeof(a1)/sizeof(a1[0]);
  cout<<"Count sum Xor is: "<<totalXor(arr, n, m)<<endl;
  cout<<"Second count sum Xor is: "<<totalXor(a1, n1, m1);

return 0;
}