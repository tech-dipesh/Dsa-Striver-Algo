#include <iostream>
using namespace std;
int main() {
   // int arr[]={7, 9, 10, 75, 25, 9, 72}; 
   int arr[] = { 7, 4, 6, 2, 5, 9 };
   int n = sizeof(arr) / sizeof(arr[0]);
   // Output should be: 72 7 9 10 75 25 9
   int k = arr[n - 1];

   int j=arr[0];
   for(int i=1;i<n-1;i++){
      arr[i]=arr[i];
   }
   arr[0]=k;
   arr[n-1]=j;

   for (int i = 0;i < n;i++) {
      cout << arr[i] << " ";
   }
   return 0;
}