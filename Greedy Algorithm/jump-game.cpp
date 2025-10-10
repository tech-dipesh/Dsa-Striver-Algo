// For this case, we've to take care about the, max that we can reach, with tracking the indexes, whenever we face the new array and is that array the smaller than what we can reach the maxValue just return the false that mean we can't reach the end.
#include <iostream>
using namespace std;


bool jumpGame(int arr[], int n){
  int maxIndexThatWeCanReach=0, maxSum=0;
  for(int i=0;i<n;i++){
    if(i>maxIndexThatWeCanReach) return false;
      maxSum=max(maxSum, arr[i]+i);
      maxIndexThatWeCanReach=max(maxIndexThatWeCanReach, maxSum);
}
  return true;
}

int main(){
   int arr[]={2, 3, 1, 0, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
    //yes we can jump the question is state that w can jump the maximum: 2 go to 2 jump but that will not make the completer rather we will jump with 1th place that way we can reach to the: 3 and then we can just jump instantly at the last that's it.
    
    int a1[]={3, 2, 1, 0, 4};
    int n1=sizeof(a1)/sizeof(a1[0]);
    // we can't do that what we do: first if we jump: 3 steps that way we can reach the 0, tha's not going forward. now if we jump to the: only one steps after once that is also not possible and also with the 1 that will not become the possible.


    int a2[]={1, 2, 3, 1, 1, 0, 2, 5};
    int n2=sizeof(a2)/sizeof(a2[0]);
  // let's check if we jump one step, we can now jump to the 2 or one: let's jump 2 that after that we can't reach if we jump one then 3 tthat way we also can't reach there, that mean it's not possible on here.

    if(jumpGame(arr, n)){
      cout<<"Yes it can reach at the end with jumping game."<<endl;
    }
    else{
      cout<<"No it will stuck forever on the array can't reach at end with jumping game."<<endl;
    }

    if(jumpGame(a1, n1)){
      cout<<"Yes it can reach at the end with jumping game."<<endl;
    }
    else{
      cout<<"No it will stuck forever on the array can't reach at end with jumping game."<<endl;
    }

    if(jumpGame(a2, n2)){
      cout<<"Yes it can reach at the end with jumping game."<<endl;
    }
    else{
      cout<<"No it will stuck forever on the array can't reach at end with jumping game."<<endl;
    }
    


return 0;
}