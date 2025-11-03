// No Space 
// Rather with extra space at any point that value is repeated we can just swap with other indexes.
#include <iostream>
#include <vector>
using namespace std;


void Help(int index, vector<int>arr, vector<vector<int>>&res){
	//Base Case: 
	if(index==arr.size()){
		res.push_back(arr);
return;
	}
		for(int i=index;i<arr.size();i++){
			// Take With Swap 
			swap(arr[i], arr[index]);
			Help(index+1, arr, res);
			// Non Take Swap 
				swap(arr[i], arr[index]);
		}
}

vector<vector<int>>Perm(vector<int>arr){
	vector<vector<int>>res;
	vector<int>vt;

	Help(0, arr, res);
return res;
}

int main(){
vector<int>arr={1, 2, 3};
vector<vector<int>>res=Perm(arr);
	cout<<"["<<endl;
	for(int i=0;i<res.size();i++){
		cout<<" [";
		for(int j=0;j<res[0].size();j++){
			cout<<", "<<res[i][j];
		}
		cout<<"]";
		cout<<endl;
	}
	cout<<"]";
return 0;
}