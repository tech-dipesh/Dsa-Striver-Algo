#include <iostream>
#include <vector>
using namespace std;

  void moveZeroes(vector<int>& nums) {
        int count=0;
        vector<int>vt;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                vt.push_back(nums[i]);
            }
            else{
              nums[i]=nums[i];
              count++;
            }
        }

  for(int i=count;i<vt.size();i++){
      nums[i]=vt[i];
      
  }
  }

int main(){
  vector<int>res={2, 6, 0, 7, 0, 0, 3};
  moveZeroes(res);
  for(int i:res){
    cout<<i<<" ";
  }
return 0;
}