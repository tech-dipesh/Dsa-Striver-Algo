#include <iostream>
#include <string>
using namespace std;

string minLength(string s, string t){
  int startIndex=-1, totalMiminumLength=INT16_MAX, count=0;

  // using hashmap, to track the frequency of the value:
  int hash[256]={0};
  for(int i=0;i<t.size();i++){
    hash[t[i]]++;
  }

  int left=0, right=0;
  while(right<s.size()){
    // hash[t[right]]--;
    // this only for the when case is that t value exist on here.
    if(hash[s[right]]>0){
      count++;
    }
    hash[s[right]]--;

    while(count==t.size()){
        if(right-left+1<totalMiminumLength){
        startIndex=left;
        totalMiminumLength=right-left+1;
      }

      // subtract that valeu from left side.
      hash[s[left]]++;
      
      // for the only t existing element we've to decreaes the count.

      if(hash[s[left]]>0){
          count--;
      }
      left++;
    }
    right++;
  }
  if(startIndex==-1){
    return "0";
  }
  string res=s.substr(startIndex, totalMiminumLength);
    return res;
}
    
int main(){
  string s="ddaaabbca";
  string t="abc";
  cout<<minLength(s, t);
return 0;
}