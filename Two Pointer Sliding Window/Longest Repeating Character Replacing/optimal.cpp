#include <iostream>
using namespace std;

// At most the k character can can conver  then any other upper case leeter after converting find the maximum element.
int LongCharReplacemtn(string s, int n, int k){
  int maxCharRep=0, totalfrequency=0;
    int left=0, right=0;
    int hash[26]={0};
    while(right<n){
      {
        hash[s[right]-'A']++;
        totalfrequency++;
        totalfrequency=max(totalfrequency, hash[s[right]-'A']);
        
        if((right-left+1)-totalfrequency>k){
          // maxCharRep=max(maxCharRep, right-left+1);
          hash[s[left]-'A']--;
          totalfrequency=0;
          left++;
        }
        if((right-left+1)-totalfrequency<=k){
          maxCharRep=max(maxCharRep, totalfrequency);
        }
        right++;
        
      }
    }
    return maxCharRep;
}
int main(){
  string s="AABABBA";
  int ssize=s.size();
  int k=2;
  string s1="AAHAADBACFGAC";
  int s1size=s1.size();
  int k1=3;
  cout<<LongCharReplacemtn(s, ssize, k)<<endl;
  cout<<LongCharReplacemtn(s1, s1size, k1);
return 0;
}