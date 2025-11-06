#include <iostream>
#include <string>
#include <vector>
using namespace std;



bool isPalindrome(string s, int left, int right){
  while(left<right){
    if(s[left]!=s[right]){
        return false;
    }
    left++;
    right--;
  }
  return true;
}
void Helper(int index, vector<vector<string>>&res, vector<string>&vt, string s){
  if(index==s.size()){
    res.push_back(vt);
    return;
  }

  for(int i=index;i<s.size();i++){

    //Check Palindrome:
    if(isPalindrome(s, index, i)){
        string sub=s.substr(index, i-index+1);
        vt.push_back(sub);
        Helper(i+1, res, vt, s);

        // Take Back:
        vt.pop_back();
    }
  }
}

vector<vector<string>>PalPartition(string s){
  vector<vector<string>>res;
  vector<string>vt;
  int i=0;
  Helper(i, res, vt, s);
  return res;
}
int main(){
    string s="aab";
    vector<vector<string>>res=PalPartition(s);
    int n=res.size();
    for(int i=0;i<n;i++){
    for(int j=0;j<res[i].size();j++){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
    }
return 0;
}