#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool checkBalance(string str){
  stack<int>st;
  st.push(str[0]);
  int i=1;
  while(st.size() && i<str.size()){
    if(st.empty()){
      return false;
    }
    // Inserting to the stack top element
    if(str[i]=='('|| str[i]=='{' || str[i]=='['){
        st.push(str[i]);
    }
    else if(st.top()=='(' && str[i]==')'){
        st.pop();
    }
   else if(st.top()=='{' && str[i]=='}'){
        st.pop();
    }
    else if(st.top()=='[' && str[i]==']'){
        st.pop();
    }
    i++;
  }
  return st.empty()?true:false;
}

int main(){
   string st="({[]})";
   string st1="([{}(]))";
   if(checkBalance(st)){
    cout<<"First is balance Parnethese."<<endl;
   }
   else{
    cout<<"NO First is not balance parenthese."<<endl;
   }

   if(checkBalance(st1)){
    cout<<"First is balance Parnethese."<<endl;
   }
   else{
    cout<<"NO First is not balance parenthese."<<endl;
   }

return 0;
}