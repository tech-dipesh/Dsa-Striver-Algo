#include <iostream>
#include <unordered_map>
using namespace std;

int Long(string s, int n){
  unordered_map<int, int>mp;
  int longest=1;
  for(int i=0;i<n;i++){
      if(mp.find(s[i])!=mp.end()){
        int maxelement=i-mp[s[i]];
        longest=max(longest, maxelement);
      }
      mp[s[i]]=i;
  }
  return longest;
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