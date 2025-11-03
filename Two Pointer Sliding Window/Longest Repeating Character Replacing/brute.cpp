#include <iostream>
using namespace std;

// At most the k character can can conver  then any other upper case leeter after converting find the maximum element.
int LongCharReplacemtn(string s, int n, int k){
  int maxCharRep=0;
    for(int i=0;i<n;i++){
      int count=0;
    for(int j=i;j<n;j++){
      if(s[i]!=s[j]){
          count++;
      }
      if(count<=k){
        maxCharRep=max(maxCharRep, j-i+1);
      }
      else{
        break;
      }
    }
    }
    return maxCharRep;
}
int main(){
  string s="AABABBA";
  int ssize=s.size();
  int k=1;

  string s1="AAHAADBACFGAC";
  int s1size=s1.size();
  int k1=3;

  string s2="ABBB";
  int s2size=s2.size();
  int k2=1;

  cout<<LongCharReplacemtn(s, ssize, k)<<endl;
  cout<<LongCharReplacemtn(s1, s1size, k1)<<endl;
  cout<<LongCharReplacemtn(s2, s2size, k2)<<endl;
return 0;
}