#include <iostream>
#include <string>
#include <stack>
using namespace std;




string reverseString(string& st) {
  int left = 0, right = st.size() - 1;
  while(left < right) {
    if(st[left] == '(') st[left] = ')';
    else if(st[left] == ')') st[left] = '(';

    if(st[right] == '(') st[right] = ')';
    else if(st[right] == ')') st[right] = '(';

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


string preToInFix(string st){
  stack<string>s;
  string res="";
  
  // reverseString(st);
  for(int i=st.size()-1;i>=0;i--){
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
      res+='('+second+st[i]+first+')';
      // all the parenthese match string:
      s.push(res);
    }
  }
  // reverseString(st);
  return s.top();
}
int main(){
   string st="*+ab-^cde";
  //  Result should be: +-*+abcdf
   cout<<"Postfix Conversion is:"<<preToInFix(st)<<endl;
return 0;
}