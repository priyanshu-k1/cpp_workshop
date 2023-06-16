#include<iostream>
using namespace std;
  
int main(){
int size;
cout<<"Enter the size of array\n";
cin>>size;
int arr[size];
int val,sum;
for(int i=0; i<size; i++){
    cout<<"Enter the "<<i+1<<" element"<<endl;
    cin>>arr[i];}
cout<<"Enter the number you want to find pair of\n";
cin>>val;
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]+arr[j]==val){
            cout<<"("<<arr[i]<<","<<arr[j]<<")";
        }
    }
}
return 0;
}