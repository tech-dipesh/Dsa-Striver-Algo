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

string inToPost(string st){
  stack<char>s;
  string res="";
for(int i=0;i<st.size();i++){
  if(isOperand(st[i])){
    res+=st[i];
  }
  else if(st[i]=='('){
    s.push(st[i]);
  }

  // When close brack appear pop out all element and store on res.
 else if(st[i]==')'){
      while(s.size() &&s.top()!='('){
          res+=s.top();
          s.pop();
      }
      if(s.size()){
        // Remove '(' from the stack. 
        s.pop();
      }
  }
 else {
    while(s.size() && highPriority(s.top())>highPriority(st[i])){
      res+=s.top();
      s.pop();
    }
    // Store appear operator.
    s.push(st[i]);
  }
}
  while(s.size()){
    res+=s.top();
    s.pop();
  }
  return res;
}
int main(){
   string st="a+b*(c^d-e)";
  //  Result should be: abcd^-*+
   cout<<"Postfix Conversion is:"<<inToPost(st)<<endl;
return 0;
}