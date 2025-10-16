// we're using teh concept of teh current and right concept fo improving the o(2n)
#include <iostream>
#include <algorithm>
using namespace std;
int CandySlope(int candy [], int n){
  int array[n];
  int  arrayCandy=1, totalCandy=0;
  array[0]=1, array[n-1]=1;
  int left=0, right=0;
  
  for(int i=1;i<n;i++){
      if(candy[i]<=candy[i-1]){
          array[i]=1;
          arrayCandy=1;
      }
      else{
          arrayCandy++;
          array[i]=arrayCandy;
      }
  } 

  int current
  for(int i=n-2;i>=0;i--){
    if(candy[i]>=candy[i+1]){
      array[i]=1;
      arrayCandy=1;
    }
    else{
      arrayCandy++;
      array[i]=arrayCandy;
    }
  }
  
  
  return totalCandy;
}
int main(){
  int candy[] = {1, 2, 3 };
  int n = sizeof(candy) / sizeof(candy[0]);

  int candy1[] = { 1, 3, 2, 1 };
  int n1 = sizeof(candy1) / sizeof(candy1[0]);
  int candy2[] = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};
  int n2 = sizeof(candy2) / sizeof(candy2[0]);
  int candy3[] = {0, 2, 4, 7, 6, 5, 4, 3, 2, 1, 1, 1, 2, 3, 4, 2, 1, 1, 1};
  int n3 = sizeof(candy3) / sizeof(candy3[0]);



  cout<<"Total Candy that the candy can get is:"<<CandySlope(candy, n)<<endl;
  cout<<"Second candy is: "<<CandySlope(candy1, n1)<<endl;
  cout<<"Second candy is: "<<CandySlope(candy2, n2)<<endl;
  cout<<"Third candy is: "<<CandySlope(candy3, n3)<<endl;
 
return 0;
}