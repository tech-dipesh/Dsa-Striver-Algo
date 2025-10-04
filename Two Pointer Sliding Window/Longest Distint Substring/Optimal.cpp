#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#define S 1000
using namespace std;
    
int LongestSubstring(string s, int k){
  int maxSize=0;
 int left=0, right=0;
//  It's o(2n) due to innner while which at least run the o(n), sc: o(256) which when all ascci all charas are there..
// we can shrink to the o(n) with using inner if condition but that time, make sure we've to increase the left each time. 
 unordered_map<char, int>mp;
 while(right<s.size()){
  mp[s[right]]++;
    while(mp.size()>k){
      mp[s[left]]--;
      if(mp[s[left]]==0)mp.erase(mp[s[left]]);
       left++;
    }
  if(mp.size()<=k){
      maxSize=max(maxSize, right-left+1);
  }
  right++;
 }
  return maxSize;
 
}
int main(){
  string st="aaabbccddeefgytjs";
  int k=2;
  string s1="abchalkwidhlotulaacccdjjgglkakdnchauptwhszkls";
  int k1=3;
  cout<<"First String is: "<<LongestSubstring(st, k)<<endl;
  cout<<"SEcond String is: "<<LongestSubstring(s1, k1);
return 0;
}