//Generate All The Permutation:
#include <iostream>
#include <vector>
using namespace std;

void Help( vector<int>arr, int hashmap[], int n, vector<int>&vt, vector<vector<int>>&res){
	//Base Case:
	if(vt.size()==arr.size()){
	res.push_back(vt);
	return;
}

	for(int i=0;i<n;i++){
		// if that element not exist:
		if(!hashmap[i]){
			hashmap[i]=1;
			vt.push_back(arr[i]);
			Help(arr, hashmap, n, vt, res);
			// During Return time.
			hashmap[i]=0;
			vt.pop_back();
		}
	}

}
vector<vector<int>>Perm(vector<int>arr, int n){
	vector<int>vt;
	vector<vector<int>>res;
	int hashmap[arr.size()];

	// Setting all the value by default to 0:
	for(int i=0;i<n;i++){
	  hashmap[i]=0;
	}
	Help(arr,hashmap,  n, vt, res);
	return res;
}
int main(){
	vector<int>arr={1, 2, 3};
	int n=arr.size();
	int hashmap[n];
	//Answer should be: (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 2, 1), (3, 1, 2)
	//we've generated the based on the: n!=3*2*1
	// For the n=4 that can be: 4!=4*3*2*1=24
	vector<vector<int>>vt=Perm(arr, n);
	cout<<"[ ";
	for(int i=0;i<vt.size();i++){
		cout<<" [";
		for(int j=0;j<vt[0].size();j++){
			cout<<vt[i][j]<<", ";
		}
		cout<<"]";
	}
	cout<<" ]";
	return 0;
}
