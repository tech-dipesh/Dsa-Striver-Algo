#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#define S 1000
using namespace std;
    
int LongestSubstring(string s, int k){
  int maxSize=0;
  for(int i=0;i<s.size();i++){
    set<char>st;
  for(int j=i;j<s.size();j++){
    st.insert(s[j]);
    if(st.size()<=k){
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
  string st="aaabbccddeefgytjs";
  int k=2;
  string s1="abchalkwidhlotulaacccdjjgglkakdnchauptwhszkls";
  int k1=3;
  cout<<"First String is: "<<LongestSubstring(st, k)<<endl;
  cout<<"SEcond String is: "<<LongestSubstring(s1, k1);
return 0;
}