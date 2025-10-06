#include <iostream>
using namespace std;

int MaxOne(int arr[], int n, int k)
{
  int maxLength = 0;
  for (int i = 0; i < n; i++){
    int count = 0;
    for (int j = i; j < n; j++){
      if (arr[j] == 0){
        count++;
      }
      if (count <= k){
        maxLength = max(maxLength, j-i + 1);
      }
      else if(count>k)break;
    }
  }
  return maxLength;
}

int main(){
  int arr[] = {1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1};
  int arrn = sizeof(arr) / sizeof(arr[0]);
  int k = 2;
  int a1[] = {1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
  int a1n = sizeof(a1) / sizeof(a1[0]);
  int a2[] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0};
  int n2 = sizeof(a2) / sizeof(a2[0]);
  int k2 = 4;
  cout << "Max one flip is: "<<MaxOne(arr, arrn, k)<<endl;
  cout << "Max one flip is: " << MaxOne(a1, a1n, k) << endl;
  cout << "Max one flip is: " << MaxOne(a2, n2, k2) << endl;

  return 0;
}