#include<iostream>
using namespace std;
  
int main(){
    int arr[4][4],sum=0,m=0,size=4,n=(size-1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if((i!=0 && j!=0) && (i!=n && j!=n)){
                    sum +=arr[i][j];
            }
        }
    }
    cout<<"output:- "<<sum<<endl;
    
}