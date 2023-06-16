#include<iostream>
using namespace std;
  
int main(){
  int arr[10];
  int temp;
  for(int i=0; i<10; i++){
    cout<<"Enter the "<<i+1<<" element"<<endl;
    cin>>arr[i];
  }
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        if(arr[j]<arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
  }
  cout<<"Smallest value: "<<arr[0]<<endl;
  cout<<"Largest  value: "<<arr[9]<<endl;
return 0;
}