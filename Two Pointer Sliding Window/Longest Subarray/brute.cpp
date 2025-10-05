#include <iostream>
using namespace std;
int Subs(string s){
  int  maxsize=0, length=0;
  int left=0, right=0;
  for(int i=0;i<s.size();i++){
    int hashing[256]={0};
    for(int j=i;j<s.size();j++){
      if(hashing[s[j]]==1)break;
      else{
       length=j-i+1;
        hashing[s[j]]==1;
        maxsize=max(maxsize, length);
        left=i;
        right=j;
      }
    }
  }
  return maxsize;
} 
int main(){
  string s="initilization";
  cout<<"Longest Unique Substring is: "<<Subs(s);
return 0;
}

