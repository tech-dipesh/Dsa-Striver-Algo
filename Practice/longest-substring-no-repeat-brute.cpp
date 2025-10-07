#include <iostream>
using namespace std;
    
int Long(string s, int n){
  int longest=1;
  for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
      if(s[i]!=s[j]){
        longest=max(longest, j-i+1);
      }
      else{
        break;
      }
  }
  return longest;
  }
}
int main(){
  string s="abcdabcbb";
  int n=s.size();
  string s1="bbbbb";
  int n1=s1.size();
  
  cout<<Long(s, n)<<endl;
  cout<<Long(s1, n1)<<endl;
return 0;
}