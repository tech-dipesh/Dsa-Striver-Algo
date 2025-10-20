#include <iostream>
using namespace std;
int Fact(int n){
  if(n==0){
    return 1;
  }
  return n*Fact(n-1);
}
int main(){
  int n;
  cout<<"Please enter the number you want to factorial: ";
  cin>>n;
  cout<<Fact(n); 
return 0;
}