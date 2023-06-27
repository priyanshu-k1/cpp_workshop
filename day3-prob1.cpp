//Fix the code not accurate
#include<iostream>
using namespace std;


int main(){
    int arr[3][3];
    int size=3;
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    int for_sum=0,rev_sum=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                for_sum+=arr[i][j];
            }
            else if( i+j==(size-1)){
                rev_sum+=arr[i][j];
            }
        }   
 
    }
    cout<<"Output:-"<<for_sum-rev_sum;
return 0;

}