#include <iostream>
#include <unordered_map>
#include <set>
#define S 1000
using namespace std;
    
// int Fruit(int arr[], int n){
//   int left=0, right=0, maxSize=0;
//   unordered_map<int, int>mp;
//   while(right<n){
//     mp[arr[right]]++;
//     while(mp.size()<2){
//       mp[arr[right]]--;
//       if(mp[arr[right]]==0){
//         mp.erase(mp[left]);
//       }
//       left++;
//     }
//     if(mp.size()<=2){
//       maxSize=max(maxSize, right-left+1);
//     }
//     right++;
//   }
//   return maxSize;
// }
int Fruit(int arr[], int n){
   int maxRes=0;
    set<int>st;
        int left=0, right=0;
        while(right<n){
            st.insert(arr[right]);
            if(st.size()<=2){
                maxRes=max(maxRes, right-left+1);
            }
            while(st.size()>2){
                st.erase(st.begin());
                left++;
            }
            right++;
        }
        
        return maxRes;
}
int main(){
  int arr[]={3, 2, 3, 6, 9, 9, 9, 6, 8, 6, 2, 8, 2, 5, 1, 7};
  int n1=sizeof(arr)/sizeof(arr[0]);
  // cout<<Fruit(arr, n1);
  int a1[]={3 ,3,3,1,2,1,1,2,3,3,4};
  int asize=sizeof(a1)/sizeof(a1[0]);
  cout<<Fruit(a1, asize);
return 0;
}