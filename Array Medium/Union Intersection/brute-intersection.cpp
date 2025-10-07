#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
  int a[] = { 2, 9, 10,  18,  21, 25, 30, 34, 35 };
  int n = sizeof(a) / sizeof(a[0]);
  int b[] = { 7, 10, 15, 18, 15, 30, 34, 37 };
  int n1 = sizeof(b) / sizeof(b[0]);

  set<int>st;

  for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    if(a[i]==b[j]){
      st.insert(a[i]);
    }
  }
  }

  int arr[st.size()];


  int i = 0;
  for (auto it : st) {
    arr[i++] = it;
  }
  for (int i : st) {
    cout << i << " ";
  }
  return 0;
}