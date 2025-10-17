// noe that we can replace the * with the any opening or close so check can make parenthese after making opening or closing.
#include <iostream>
using namespace std;

bool Res(string s, int n){
  int open=0, close=0, astrict=0;
  int count=0;

  
for(int i=0;i<n;i++){
  if(s[i]=='('){
    open++;
  }
  else if(s[i]==')'){
    close++;
  }
  else if(s[i]=='*'){
    astrict++;
  }
}
return abs(open-close)-  astrict==0?true:false;
 
}


int main(){
string s="(*)";
int n=s.size();
string s1="(*))";
int n1=s1.size();

string s2="(**(";
int n2=s2.size();
  
string s3="(**(";
int n3=s3.size();
  
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
if(Res(s3, n3)){
  cout<<"Third is valid parenthese."<<endl;
}
else{
  cout<<"Third is not valid parenthese."<<endl;
}

return 0;
}