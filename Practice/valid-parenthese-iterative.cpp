// but the any moment when that the count become less than 0 that we've to stop.
#include <iostream>
using namespace std;

bool Res(string s, int n){
  int count=0;

for(int i=0;i<n;i++){
  if(count>0){
    return false;
  }
  if(s[i]=='('){
    count++;
  }

  else if(s[i]==')'){
    count--;
  }
}

return count==0?true:false;
}

int main(){
string s="((()))";
int n=s.size();
string s1="()))()()))";
int n1=s1.size();
  
string s2="())(";
int n2=s2.size();
  
if(Res(s, n)){
  cout<<"first is valid parenthese."<<endl;
}
else{
  cout<<"First is not valid parenthese."<<endl;
}
  
if(Res(s1, n1)){
  cout<<"Second is valid parenthese."<<endl;
}
else{
  cout<<"Second is not valid parenthese."<<endl;
}
if(Res(s2, n2)){
  cout<<"Third is valid parenthese."<<endl;
}
else{
  cout<<"Third is not valid parenthese."<<endl;
}

return 0;
}