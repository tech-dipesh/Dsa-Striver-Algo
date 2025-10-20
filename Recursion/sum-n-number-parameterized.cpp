#include <iostream>
using namespace std;
void Sum(int n, int sum){
  if(n==0){
    cout<<sum<<endl;
    return;
  }
  // sum+=n;
  Sum(n-1, sum+=n);
} 
int main(){
  cout<<"Please enter the numbers that you want to make sum.";
  int n, sum=0;
  cin>>n;
  Sum(n, sum);
return 0;
}