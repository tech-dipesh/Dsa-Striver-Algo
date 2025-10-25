// Print from 1 to n but don't use the i-1, n like this.  which kind of the basic backtracking.
// it's a opposite way of writing after function call.

#include <iostream>
using namespace std;

void F(int i, int n){
  if(i<1){
    return;
  }
  // where the each time will be the n(3),
  //  1: i(3), n(3): after 2 pring during return time.
  //  2: (2), n(3): after 1 print 2 during return time.
  //  3: i(1), n(3): during return time it print.

  F(i-1, n);
  cout<<i<<endl;
}


void nToOne(int i, int n){
  if(i==n){
    return;;
  }
  nToOne(i+1, n);
  cout<<i<<endl;
}
int main(){
  // F(10, 10);
  nToOne(0, 10);
return 0;
}