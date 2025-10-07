#include <iostream>
using namespace std;
    
    int lengthOfLongestSubstring(string s) {
    // Brute Force Approach:
    // if(s.size()==1) return 1;
    int maxSize=0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]!=s[j]){
                maxSize=max(maxSize, j-i+1);
            }
            if(s[i]==s[j]){
               break;
            }
        }
    }
       return maxSize;
    }
int main(){
   string s1="abcabcbb";
   cout<<lengthOfLongestSubstring(s1);
return 0;
}