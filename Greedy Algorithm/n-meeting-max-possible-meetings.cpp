#include <iostream>
#include <algorithm>
using namespace std;
struct Meet{
  int id;
  int start;
  int end;
};

bool Sort(Meet a, Meet b){
  return a.end<b.end;
}
int main(){
  Meet arr[]={
    {1, 0, 5},
    {2, 3, 4},
    {3, 1, 2},
    {4, 5, 9},
    {5, 5, 7},
    {6, 8, 9}
  };

  int n=6;

  // now the answer should be that the possible meeting that can held, this is kind of almost similar question of the job sequence.
  // with from teh if we do: (0, 5) that can be only 2 so that will not possible we' to make the maximum.
  // max possible is: (1, 2), (3, 4), (5, 7) (8, 9)
  // it also shouldn't be overlap like: if we finished job on 5 we can't start on 5.

  sort(arr, arr+n, Sort);

  int count=0, startmeeting=0;



  // our approach is to preserver the stack ds for teh storing the ending time for checking a any overlap, and counting the size for the final result.

  // start with the shortest possible ending time and store that ending time on the stack, now on the next step get the starting value from the array where that is greater then the stack top until not get the top.
  // do that if we found out that the new starting time is equal or smaller just skip that and go to next.
  

  for(int i=0;i<n;i++){
     cout<<arr[i].end<<" "<<endl<<arr[i].start<<endl<<" "<<arr[i].id;
  }


return 0;
}