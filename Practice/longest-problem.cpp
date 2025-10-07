#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    string s = "mounteverset";
        // t.c.: o(2n) which become: o(n) and s.c.: o(n)
        if(s.size()==0) return 0;
            int maxRes = 1;
      int left=0, right=0;
        unordered_map<char, int>mp;
        while(right<s.size()){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
           }
            maxRes=max(maxRes, right-left+1);
           right++;
        }
    cout<<maxRes;
    return 0;
}