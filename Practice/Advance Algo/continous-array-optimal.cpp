#include <iostream>
#include <vector>
using namespace std;
 int findMaxLength(vector<int>& nums) {
        int maxValue = 0;
        int left = 0, right = 0;
        int ones = 0, zero = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zero++;
            }
            else {
                ones++;
            }
            if (abs(zero - ones) == 0) {
                maxValue = max(maxValue, right - left + 1);
            }
            while(abs(zero-ones)>0){
               if(nums[left]==0){
                   zero--;
               }
               else{
                   ones--;
               }
               left++;
           }
            right++;
        }
        return maxValue; 
    }
int main(){
    vector<int>vt={0, 1, 0};
    vector<int>vt1={0,1,1,1,1,1,0,0,0};
    // cout<<findMaxLength(vt)<<endl;
    cout<<findMaxLength(vt1)<<endl;
return 0;
}