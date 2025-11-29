#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void Reverse(string &st){
  int left=0, right=st.size()-1;
  while(left<right){
    swap(st[left], st[right]);
    left++;
    right--;
  }
}
string removekDigits(vector<int>vt, int k){
  string res="";
  stack<char>st;
  // When k is equal to size, base Case;
  if(vt.size()==k){
    return "";
  }

  for(int i=0;i<vt.size();i++){
    while(st.size() && k>0 && st.top()>vt[i]){
        // s.pop();
        st.pop();
        k--;
       }
    st.push(vt[i]);
  }

  // Edge Case
  while(k>0){
    st.pop();
    k--;
  }

  // Still there is some element left on stack:
  while(st.size()){
    res+=st.top();
    st.pop();
  }
  
  // When there is the: 0 at the last:
  while(res.size() && res.back()=='0'){
    res.pop_back();
  }
  Reverse(res);
  return res;
}
int main(){
  //  string st="1432219";
  vector<int>vt={1, 4, 3, 2, 1, 9};
   int k=3;
   cout<<removekDigits(vt, k);
    //Remove: 1, 2, 1, 9 
return 0;
}