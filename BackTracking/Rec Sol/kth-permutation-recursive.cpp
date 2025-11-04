#include <iostream>
#include <vector>
using namespace std;


void Helper(int index, int n, vector<vector<char>>&res, vector<char>&vt){
    if(n==vt.size()){
        res.push_back(vt);
        return;
    }
    for(char i=index;i<=n;i++){
        // Take
        vt.push_back(index);
        Helper(i+1, n, res, vt);
        // Take back:
            vt.pop_back();
    }
}
vector<vector<char>>KthPerm(int n, int k){
    vector<vector<char>>res;
    vector<char>vt;
    Helper(1, n, res, vt);
    return res;
}

int main(){
    // On the given permutation we've to find out the kth number of the permutation:
    int n=3, k=4;
    // 3 perm:
    // 1, 2, 3
    // 1, 3, 2
    // 2, 3, 1
    // 2, 1, 3
    // 3, 1, 2
    // 3, 2, 1
    
    // now return the 4th k from the given perm: 2, 1, 3 res.
    vector<vector<char>>res=KthPerm(n, k);
    int startIndex=k;
    for(int i=0;i<1;i++){
        for(int j=startIndex;i<n;i++){
            cout<<res[i][j];
        }
    }
    
return 0;
}