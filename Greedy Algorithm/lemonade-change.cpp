#include <iostream>
using namespace std;


bool Lemonade(int arr[], int n){
    
    int fives=0, tens=0, twenty=0;

    int i=0;
    while(i<n){
      if(arr[i++]==5){
        fives++;
      }
      else if(arr[i++]==10){
        if(fives){
            tens++;
            fives--;
        }
        else{
          // cout<<"Lemmonade it can't be possible."<<endl;
          return false;
        }
      }
      else if(arr[i++]==20){
          if(fives && tens){
              tens--;
              fives--;
          }
          else if(fives>=5){
            fives-=3;
          }
          else {
            return false;
          }
      }
    } 

    return true;
}
int main(){
    //every lemonade cost the $5, avaible cards are the 5 10 and 20, we've to return the money if they give 10 or 20.
    // and  5 5 10 20 20 is not possible.
    // the denominator are: 5 10 10
    // on first: 5 5 5 that becomees: 5: 3, 10: 0, 20: 0
    // now on the next 10, we've to return to the: 5 so now it becomes the: 5: 2 10:1 20: 0
    // now when 20 comes that we can simply return him of: total 15 with 5: 1 and 10: 1 that's possible.


    // on another example on the first 2: 5 5 that becomes the: 5: 2, 10: 0, 20: 0
    // on the next time when 10 comes we can simply return him the: 5: 1 that now become the: 5: 1 and 10: 1 and 20: 0
    // now on the next steps for the 20, if we check the 20 that not become possible as we only have the 1 5 and 1 10 which becomes the 15 that not become the output.



    int arr[]={5, 5, 5, 10, 20};
    int a1[]={5, 5, 10, 20, 20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int n1=sizeof(a1)/sizeof(a1[0]);


    if(Lemonade(arr, n)){
      cout<<"Lemondate is possible."<<endl;
    }
    else{
      cout<<"Not possible"<<endl;
    }

    if(Lemonade(a1, n1)){
      cout<<"Second Lemondate is possible."<<endl;
    }
    else{
      cout<<"SEcond Lemonde Not possible"<<endl;
    }
return 0;
}