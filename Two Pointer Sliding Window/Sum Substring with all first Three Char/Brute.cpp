#include <iostream>
#include <string>
using namespace std;
    

int totalValidSubstring(string s){
  int sum=0;
  for(int i=0;i<s.size();i++){
    int hash[3]={0};
    for(int j=i;j<s.size();j++){
      hash[s[j]-'a']=1;
      if(hash[0]+hash[1]+hash[2]==3){
        // sum++;
        sum+=(s.size())-j;
        break;
      }
    }
  }
  return sum;
}
int main(){
  string s="acabab";
  string s1="bbacba";
  cout<<totalValidSubstring(s)<<endl;
  cout<<totalValidSubstring(s1);
return 0;
}