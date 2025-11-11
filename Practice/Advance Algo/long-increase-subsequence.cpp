#include <iostream>
#include <vector>
using namespace std;
 int lengthOfLIS(vector<int>& nums) {
       int longest=0;
       for(int i=0;i<nums.size();i++){
        int maxsub=0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                    maxsub++;
                  }
                  longest=max(maxsub, longest);
        }
       }
       return longest;
    }
int main(){
    vector<int>vt={10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(vt);
return 0;
}