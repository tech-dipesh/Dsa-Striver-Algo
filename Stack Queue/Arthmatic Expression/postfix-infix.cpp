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

  string poToInFix(string st){
    stack<string>s;
    for(int i=0;i<st.size();i++){
      if(isOperand(string(1, st[i]))){
        string temp="";
        temp+=st[i];
        s.push(temp);
      }
      else{
          string second=s.top();
          s.pop();
          string first=s.top();
          s.pop();
          string res="("+first+st[i]+second+")";
          s.push(res);
      }
    }
    return s.top();
  }
  int main(){
    string st="abcd^e-*+";
    //  Result should be: a+b*(c^d-e)
    cout<<"Postfix to Infix Conversion is:"<<poToInFix(st)<<endl;
  return 0;
  }