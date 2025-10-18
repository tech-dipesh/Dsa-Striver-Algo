// just satisy these two condition:
// each child should get at least one candy.
// children with higher rating from left and right neighbour should get more candies that it's neighbour.
#include <iostream>
#include <algorithm>
using namespace std;
int CandySlope(int candy[], int n){
    int sum=0, i=0;
  while(i<n){
    // also same value on the neighbour
    if(candy[i]==candy[i-1]){
      sum++;
      i++;
      continue;
    }
    // where the the neighour is increasing.
    int up=1, down=1;;
    while(i<n && candy[i]>candy[i-1]){
        up++;
        sum+=up;
        i++;
    }

    // where neighur is decreasing:
    while(i<n && candy[i]<candy[i-1]){
        sum+=down;
        up++;
        i++;
    }
    if(down>up){
      sum+=up-down;
    }
  }
  return sum;
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