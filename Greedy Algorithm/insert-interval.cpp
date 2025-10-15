  // on given question they give the currentInterval of the sorted order, it just the advance version of the non interval question with just insert the new interval so that there is no any interval overlap, if any overlap exist we can just remove that.

  #include <iostream>
  using namespace std;
  struct CurrentInterval {
    int start;
    int end;
  };
  struct newInterval {
    int start;
    int end;
  };

  struct Result{
    int start;
    int end;
  };
  int main() {
    // CurrentInterval arr[] = {
    //   {1, 3},
    //   {6, 9}
    // };
    CurrentInterval arr[] = {
      {1, 2},
      {3, 4},
      {5, 7},
      {8, 10},
      {12, 16},
    };
    newInterval ar[] = {
        {6, 8}
    };

    //  i see the patern first just i can insert that new interval element to teh currentInterval and make the merge interval and check after that is there any point where that overlap is exist if not we can just return the total count, if the any overlap exist we can just subtract with total overlap exist.

    int n=sizeof(arr)/sizeof(arr[0]);
    
    Result res[n]={
      
    };
    
    // First i've to insert the left msot section.
    int i=0, j=0;
    while(i<n &&arr[i].end<ar[0].start){
      res[j].start=arr[i].start;
      res[j].end=arr[i].end;
      i++;
      j++;
    }
    
    // where the overlap happedn i just insert the element here.
    while(i<n &&  arr[i].start<=ar[0].end){
      ar[0].start=min(arr[i].start, ar[0].start);
      ar[0].end=max(arr[i].end, ar[0].end);
      i++;
    }
    
    res[j].start=ar[0].start;
    res[j].end=ar[0].end;
    j++;
    
    
    while(i<n){
      res[j].start=arr[i].start;
      res[j].end=arr[i].end;
      i++;
      j++;
    }
    
    for(int i=0;i<j;i++){
      cout<<res[i].start<<". end: "<<res[i].end<<endl;
    }
    
    return 0;
  }

