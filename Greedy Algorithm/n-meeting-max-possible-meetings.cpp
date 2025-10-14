// now the answer should be that the possible meeting that can held, this is kind of almost similar question of the job sequence.
// with from teh if we do: (0, 5) that can be only 2 so that will not possible we' to make the maximum.
// max possible is: (1, 2), (3, 4), (5, 7) (8, 9)
// it also shouldn't be overlap like: if we finished job on 5 we can't start on 5.
#include <iostream>
#include <algorithm>
#include <queue>
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

  int n=sizeof(arr)/sizeof(arr[0]);

  // use stack ds for storign end tme and check any overlap of new element start time, the first start will always be the smallest ending time.
  sort(arr, arr+n, Sort);
  int count=1, endingMeetingTime=arr[0].end;
  queue<int>st;
  int res[n];
  
  // st.push(arr[0].id);
  res[0]=arr[0].id;
  int j=1;
  for(int i=1;i<n;i++){
    if(arr[i].start>endingMeetingTime){
      count++;
      endingMeetingTime=arr[i].end;
      // st.push(arr[i].id);
      res[j++]=arr[i].id;
    }
  }

  cout<<"total count is: "<<count<<endl;
  
  for(int i=0;i<j;i++){
    cout<<"All Id is: "<<res[i]<<" ";
  }

return 0;
}