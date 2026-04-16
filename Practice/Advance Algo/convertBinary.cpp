#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void c(int n){
    int minRes=0;
        int convertBinary=0, mul=1;
        int dup=n;
        while(dup>0){
            convertBinary+=(dup%2)*mul;
            mul*=10;
            dup/=2;
        }
        string val=to_string(convertBinary);
        int output=0, m=1;
        reverse(val.begin(), val.end());
        
        for(int i=0;i<val.size();i++){
            cout<<val[i];
            // output+=VJ;
            // // cout<<output<<" ";
            // output*m;
            // m*=10;
            // cout<<output<<" ";
        }
        // return rev;
    }
int main(){
   int n=10;
    // cout<<c(n);
    c(n);
    
return 0;
}