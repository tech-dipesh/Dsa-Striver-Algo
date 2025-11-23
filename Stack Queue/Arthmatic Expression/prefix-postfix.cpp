#include <iostream>
#include <string>
#include <stack>
using namespace std;




bool isOperand(string s){
  if(
    (s>="A" && s<="Z" ) || 
    (s>="a" && s<="z")||
    (s>="0" && s<="9")
  ){
    return true;
  }
  else{
    return false;
  }
}

string preToPostfix(string st){
  stack<string>s;
  string res="";
  for(int i=st.size()-1;i>=0;i--){
    if(isOperand(string(1, st[i]))){
      s.push(string(1, st[i]));
    }
    else{
        string first=s.top();
        s.pop();
        string second=s.top();
        s.pop();
        s.push(first+second+st[i]);
    }
  }
  return s.top();
}
int main(){
   string st="+a*b-^cde";
  //  Result should be: +-*+abcdf
   cout<<"Postfix Conversion is:"<<preToPostfix(st)<<endl;
return 0;
}