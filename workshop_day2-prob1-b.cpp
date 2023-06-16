#include<iostream>
using namespace std;
  
int main(){
int arr[5]={1,2,3,4,5};

for(int i=0;i<3;i++){
    if(i==0){cout<<arr[0]<<" ";}
    cout<<arr[i]*arr[i+2]<<" ";
}
cout<<arr[4]<<" ";
return 0;
}