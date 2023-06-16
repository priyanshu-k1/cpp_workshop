#include<iostream>
using namespace std;
  
int main(){
int num,size,digit,arr[5],i=4;
cout<<"Enter the 5 digit number: \n";
cin >> num;
while(num!=0){
    digit=num%10; // extracting single digit from the number..
    arr[i]=digit; // inserting digit in the array...
    i--; // example is num is 12345 while extracting we will get digit as 5 4 3 2 1 to get in correct order i am using decrement
    num/=10;
}
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}
cout<<endl<<arr[0]<<" ";
for(int i=1;i<3;i++){
 if(arr[(i-1)]%2==0 && arr[(i+1)]%2==0){
    cout<<arr[i]<<" ";
 }
}
cout<<arr[4]<<" ";

return 0;
}