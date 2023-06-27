#include<iostream>
using namespace std;

int counter(int array[],int size,int num){
    int count=0;
    for(int i=0;i<size;i++){
        if (array[i] == num) {
            count++;
            }
    }
    return count;
}
int main(){
int size,count=0,no_repeat=-1;
cout<<"Enter the size of list:\n";
cin >>size;
int arr[size];
for(int i=0; i<size; i++){
   cout<<"Enter the "<<i+1<<" element"<<endl;
   cin>>arr[i];
}
for(int i=0;i<size;i++){
    if(counter(arr,size,arr[i])==2){
            cout<<arr[i]<<" is repeated twice"<<endl;
    }
}
return 0;
}