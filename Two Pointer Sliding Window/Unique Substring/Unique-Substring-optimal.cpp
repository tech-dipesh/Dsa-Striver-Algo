// we'll be using the hash map on here: 
// this is the pseudo code for this problem:
// we'll be taking the unordered-map where we'll storing that key value, and that index .
// with using two pointer & slidingn window approach:
// first we'll be start the left and right index at the 0th index.
// now we can run the loop of the until right not becoming a equal or greater of the size of the string:
// for that we'l be checking the condition of the if that the value of teh right index liek:
// s[right] which can be the abcda, can choose the a, for that we can check the, if mp[s[right]].find!=mp.end() if no then only include that res with right - left and find the max of each time.
// and if that value exist, just make left++, now and at last just return the length.


#include <iostream>
#include <unordered_map>
using namespace std;
int Subs(string s){
  int  maxsize=0, length=0, left=0, right=0;
  // int hashmap[256]={-1};
  unordered_map<int, int>mp;
  while(right<s.size()){
    // if(mp[s[right]]!=-1) {
    if(mp[s[right]]){
      if(mp[right]>=left){
        // length=hashmap[s[right]]+1;
        left=mp[s[right]]+1;
      }
    }
    maxsize=max(maxsize, right-left+1);
    mp[s[right]]=right;
    right++;
  }
  // return maxsize;
}
int main(){
  string s="initilization";
  cout<<"Longest Unique Substring is: "<<Subs(s); 
return 0;
}