#include <iostream>
#include <string>
#include <stack>
using namespace std;



string reverseString(string &st){
  int left=0, right=st.size()-1;
  while(left<right){
    swap(st[right], st[left]);
    left++;
    right--;
  }
  return st;
}
bool isOperand(char s){
  if(
    (s>='A' && s<='Z' ) || 
    (s>='a' && s<='z')||
    (s>='0' && s<='9')
  ){
    return true;
  }
  else{
    return false;
  }
}

int highPriority(char ch){
  if(ch=='^'){
    return 3;
  }
  else if(ch=='/' ||ch=='*'){
    return 2;
  }
 else if(ch=='+' || ch=='-'){
    return 1;
  }
  else{
    return 0;
  }
}

string inToPre(string st){
  stack<char>s;
  reverseString(st);
  string res="";
for(int i=0;i<st.size();i++){
  if(isOperand(st[i])){
    res+=st[i];
  }
 else if(st[i]==')'){
      while(s.size() && s.top()!='('){
          res+=s.top();
          s.pop();
      }
  }
 else if(highPriority(s.top())>highPriority(st[i])){
    while(highPriority(s.top())>highPriority(st[i])){
      res+=s.top();
      s.pop();
    }
  }
  else{
    s.push(st[i]);
  }
}
  while(s.size()){
    res+=s.top();
    s.pop();
  }
  reverseString(res);
  return res;
}
int main(){
   string st="a+b*(c^d-e)";
  //  Result should be: +-*+abcdf
   cout<<"Postfix Conversion is:"<<inToPre(st)<<endl;
return 0;
}