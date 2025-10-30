#include <iostream>
#include <algorithm>
using namespace std;

struct Jobs{
  int id;
  int deadline;
  int price;
};
bool Sort(Jobs a, Jobs b){
  return a.price>b.price;
}
int main(){
//   id:     1,  2,  3,  4;
// deadline: 4,  1,  1,  1;
// profit:   40, 10, 40, 30;

// the order is this that the question is this how can we phasherve order of the: we can solve teh question first gettting the deadline of teh shortest one first and then keep moving shortest, but the probem is that how can we phasherver that id order as we've to phasherver either we also can do with the help of the struct, but i've not done those kind of question.
  // Jobs arr[]={
  //   {1, 4, 40},
  //   {2, 1, 10},
  //   {3, 1, 40},
  //   {4, 1, 30},
  // };


  Jobs arr[]={
    {1, 4, 20},
    {2, 5, 60},
    {3, 6, 70},
    {4, 6, 65},
    {5, 4, 25},
    {6, 2, 80},
    {7, 2, 10},
    {8, 2, 22},
  }; 

  // the answer should be: (6, 2, 80), (4, 25), (5, 60), (6, 70): count is: 4, totalprofit: 210+25=235


  int n=8;
  sort(arr, arr+n, Sort);



  
//  for(int i=0;i<n;i++){
  //   int maxValue=-1;
  //  for(int j=i;j<n;j++){
   //       maxValue=max(maxValue, arr[j].price);
   //  }
    //  if(maxValue){
    //   hash[i]=maxValue;
    //  }
    //  }

int maxDeadline=0, count=0, totalProfit;
  for(int i=0;i<n;i++){
      maxDeadline=max(maxDeadline, arr[i].deadline);
}
cout<<"maxdeadlien is: "<<maxDeadline<<endl;
  int hash[maxDeadline+1]={-1};
  for(int i=0;i<maxDeadline+1;i++){
    hash[i]=-1;
  }

for(int i=0;i<n-1;i++){
   for(int j=arr[i].deadline;j>0;j--){
      if(hash[j]==-1){
        count++;
        hash[i]=arr[i].id;
        totalProfit+=arr[i].price;
        break;
      }
  }
}
  cout<<"Total Profit is: "<<totalProfit;
return 0;
}