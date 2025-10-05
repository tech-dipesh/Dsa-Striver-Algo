#include <iostream>
#include <string>
using namespace std;
    
int minimumIndex(int a, int b, int c){
  // if(a<b &&a<c){
  //   return a;
  // }
  // if(b<a && b<c){
  //   return b;
  // }
  // else{
  //   return c;
  // }
  // return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
     if(b>a && c>a){
        return a;
    }
    if(a>b && c>b){
        return b;
    }
    else{
        return c;
    }
}
int totalValidSubstring(string s){
  int sum=0;
  int hash[3]={-1};
  for(int i=0;i<s.size();i++){
    hash[s[i]-'a']=i;
    if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
        // sum+=1+(min(hash[0], hash[1], hash[2]);
        int smallestindex=minimumIndex(hash[0], hash[1], hash[2]);
        sum+=smallestindex+1;
    }
  }
  return sum;
}
int main(){
  string s="acabab";
  string s1="bbacba";
  cout<<totalValidSubstring(s)<<endl;
  cout<<totalValidSubstring(s1)<<endl;
  string lee="abcabc";
  cout<<totalValidSubstring(lee);

return 0;
}