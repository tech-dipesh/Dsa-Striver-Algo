#include <iostream>
#include <string>
#include <stack>
using namespace std;


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

string poToPrefix(string st){
  stack<string>s;
  string res="";
  for(int i=0;i<st.size();i++){
    if(isOperand(st[i])){
      string temp="";
      temp+=st[i];
      s.push(temp);
    }
    else{
        string first=s.top();
        s.pop();
        string second=s.top();
        s.pop();
        // res+=st[i]+second+first;
        // s.push(res);
        s.push(st[i]+second+first);
    }
  }
  return s.top();
}
int main(){
   string st="abcd^e-*+";
  //  Result should be: +-*+abcdf
   cout<<"Post to Prefix Conversion is:"<<poToPrefix(st)<<endl;
return 0;
}