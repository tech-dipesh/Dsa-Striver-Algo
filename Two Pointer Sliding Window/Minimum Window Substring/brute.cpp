#include <iostream>
#include <string>
using namespace std;

string minLength(string s, string t){
  int startIndex=0, totalMiminumLength=INT16_MAX;

  for(int i=0;i<s.size();i++){
      int hash[256]={0};
      int count=0;
      // for inserting the t value to the hash map:
      for(int j=0;j<t.size();j++){
          hash[t[j]]++;
      }

  for(int j=i;j<s.size();j++){
    if(hash[s[j]]>0){
      count++;
      hash[s[j]]--;
    }

    // first i've to check is that a correct substint which all element exist.
    if(count==t.size()){
    if(j-i+1<totalMiminumLength){
        startIndex=i;
        totalMiminumLength=j-i+1;
        break;
    }
  }
}
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