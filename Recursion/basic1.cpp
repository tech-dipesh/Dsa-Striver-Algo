// Print linear from 1 to n..
// Print from  n to 1.
// Print linearly from 1 to n(With the backtracking).
// Print linearly from n to 1(With the backtracking).


#include <iostream>
using namespace std;
void N(int count){
  if(count==0){
    return;
  }
  count--;
  cout<<count<<" ";
  N(count);
  cout<<endl;
}


void Online(int i, int n, string st){
  if(i>n){
    return;
  }
  cout<<st<<" ";
  Online(i++, n, st);
}

int main(){
  // int n=99;
  // N(n);
  int i=0, n;
  string name;
  cout<<"Please enter your name: ";
  cin>>name;
  cout<<"Please enter how many time you want to print your name: ";
  cin>>n;
  Online(i, n, name);
return 0;
}