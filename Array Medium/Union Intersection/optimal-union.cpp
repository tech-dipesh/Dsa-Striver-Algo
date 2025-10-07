// timme will be taking about t.c.: o(n) and s.c.: o(n)
#include <iostream>
#include <set>
using namespace std;
int main(){
   int a[]={2, 9, 10,  18,  21, 25, 30, 34, 35};
   int n=sizeof(a)/sizeof(a[0]);
   int b[]={7, 10, 15, 18, 15, 30, 34, 37};
   int n1=sizeof(b)/sizeof(b[0]);

  set<int>st;

  int i=0, j=0, k=0;
  while(i<n && j<n1){
      while(a[i]>=b[j]){
        st.insert(b[j]);
        j++;
        k++;
      }
      while(a[i]<b[j]){
        st.insert(a[i]);
        i++;
        k++;
      }
  }

  for(auto i:st){
    cout<<i<<" ";
  }

return 0;
}