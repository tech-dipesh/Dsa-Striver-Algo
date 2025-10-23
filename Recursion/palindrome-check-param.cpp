#include <iostream>
using namespace std;

bool Palindrome(int arr[], int i, int n){
  if(i>=n/2){
    return true;
  }
  if(arr[i]!=arr[n-1]){
    return false;
  }
  Palindrome(arr, i+1, n-i-1);
}
int main(){
  int arr[]={9, 7, 5, 7, 9};
  int n=sizeof(arr)/sizeof(arr[0]);
   int i=0;
  if(Palindrome(arr, i, n)){
    cout<<"It's a palidnrome.";
  }
  else{
    cout<<"No it's not a palindrome.";
}

   
return 0;
}