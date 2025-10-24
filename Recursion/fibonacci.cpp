#include <iostream>
using namespace std;
int Fib(int n){
  // Base case where below 1 mean either 0 or 1 that will be return a n.
  if(n<=1){
    return n;
  }
  // return Fib(n-1)+Fib(n-2);
  int last=Fib(n-1);
  int secondlast=Fib(n-2);
  return last+secondlast;
}
int main(){
   int n=5;
   cout<<Fib(n)<<endl; 
return 0;
}