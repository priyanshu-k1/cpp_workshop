#include<iostream>
using namespace std;
  
int main(){
    int range,num1=0,num2=1;
    cout<<"Enter the range :\n";
    cin >> range;
    int arr[range];
    for(int i=0; i<range; i++){
        arr[i]=num1;
        int temp=num2;
        num2=num1+num2;
        num1=temp;
        
    }
    for(int j=range-1;j>=0;j--){
        cout<<arr[j]<<" ";
    }

return 0;
}