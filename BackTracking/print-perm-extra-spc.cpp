// No Space 
// Rather with extra space at any point that value is repeated we can just swap with other indexes.
#include <iostream>
#include <vector>
using namespace std;


void Help(vector<int>arr, vector<vector<int>>&res, vector<int>&vt, int hashmap[]){
	//Base Case: 
	if(vt.size()==arr.size()){
		res.push_back(vt);
return;
}

	for(int i=0;i<arr.size();i++){
	//Add only non exist value:
	if(!hashmap[i]){
		hashmap[i]=1;
		vt.push_back(arr[i]);
		Help(arr, res, vt, hashmap);
		
vt.pop_back();
hashmap[i]=0;			
}
	}
}
vector<vector<int>>Perm(vector<int>arr, int n){
	vector<vector<int>>res;
	vector<int>vt;

       //REquied the HashMap:
	int hashmap[arr.size()];
	//SEt all hashmap to 0 to track.
	for(int i=0;i<arr.size();i++){
		hashmap[i]=0;
}

	Help(arr, res, vt, hashmap);
return res;
}

int main(){
	//Answer should be: (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 2, 1), (3, 1, 2)
	//we've generated the based on the: n!=3*2*1
	// For the n=4 that can be: 4!=4*3*2*1=24
vector<int>arr={1, 2, 3};
int n=arr.size();
	vector<vector<int>>vt=Perm(arr, n);
	cout<<"["<<endl;
	for(int i=0;i<vt.size();i++){
		cout<<" [";
		for(int j=0;j<vt[0].size();j++){
			cout<<", "<<vt[i][j];
		}
		cout<<"]";
		cout<<endl;
	}
	cout<<"]";
	return 0;
}
