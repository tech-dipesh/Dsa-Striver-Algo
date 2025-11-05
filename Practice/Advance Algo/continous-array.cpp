#include <iostream>
#include <vector>
using namespace std;
   int findMaxLength(vector<int>& nums) {
   int maxValue=0;
     for(int i=0;i<nums.size();i++){
        int ones=0, zero=0;
        for(int j=i;j<nums.size();j++){
            if(abs(zero-ones)==0){
                maxValue=max(maxValue, j-i+1);
            }
            if(nums[j]%2==0){
                    zero++;
            }
            else{
                ones++;
            }
        }
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