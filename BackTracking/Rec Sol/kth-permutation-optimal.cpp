#include <iostream>
#include <vector>
using namespace std;


int main(){
    // On the given permutation we've to find out the kth number of the permutation:
    int n=3, k=5;
    // 3 perm:
    // 1, 2, 3
    // 1, 3, 2
    // 2, 3, 1
    // 2, 1, 3
    // 3, 1, 2
    // 3, 2, 1
    // Add all number and find total factorial.
    vector<int>vt;
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
        vt.push_back(i);
    }

    k-=1;
    vector<string>final;
    string s="";
    while(true){
        int startPosition=k/factorial;
        final.push_back(to_string(vt[startPosition]));
        
        vt.erase(vt.begin()+k/factorial);
        if(vt.empty()){
            break;
        }
        k%=factorial;
        factorial/=vt.size();
    }

    for(auto i:final){
        cout<<i<<" ";
    }
return 0;
}