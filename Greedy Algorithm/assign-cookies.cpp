// first is sort them and be greedy of each cookies to the children.
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  // a is the all children while b is the avaible cookies.
   int children[]={1, 5, 3, 3, 4};
   int n=sizeof(children)/sizeof(children[0]);
   
   int cookies[] ={4, 2, 1, 2, 5, 3};
   int n1=sizeof(cookies)/sizeof(cookies[0]);
  //  result is 3 due to get access the  1 children 3 childredn and anotehr  3 children not abiel for 4 and 5.
  sort(children, children+n);
  sort(cookies, cookies+n1);
  int count=0;
  
  int i=0, j=0;
  while(i<n-1 && j<n1-1){
      if(children[i]<=cookies[j]){
        i++;
        j++;
        count++;
      }
     else if(children[i]>cookies[j]){
        j++;
      }
    
  }

  cout<<count;
return 0;
}