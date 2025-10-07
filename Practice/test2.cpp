#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
 string version1 = "1.2", version2 = "1.10";
   for(int i=1;i<version1.size() && version2.size();i++){
        if(version1[i]=='.' || version2[i]=='.') {
            continue;
        }
        cout<<"both values are: "<<version1[i]<<" "<<version2[i]<<endl;
            if(version1[i]==0 || version2[i]==0){
                cout<<"output is 0";
                break;
              }
              if(version1[i]<version2[i]){
                cout<<"output is 0";
                break;
              }
              if(version1[i]>version2[i]){
                cout<<"output is 0";
                break;
            }
          }
return 0;
}