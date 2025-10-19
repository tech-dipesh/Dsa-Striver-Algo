#include <iostream>
using namespace std;
// void fun(int n){
//   if(n==1000){
//     return;
//   }
//   cout<<n<<endl;
//   n++;
//   fun(n);
// }

// int count=100;
// void P(){
//   if(count==0){
//     return ;
//   }
//   cout<<count<<endl;
//   count--;
//   P();
// }

string name="Dipesh";
int count=0;
void Name(){
  if(count==5){
    return;
  }
  cout<<name<<endl;
  count++;
  Name();
}

int main(){
  //  fun(5); 
  // P();
  Name();
return 0;
}