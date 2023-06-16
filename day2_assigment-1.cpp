#include<iostream>
using namespace std;
  
int main(){
int num,size,digit,arr[5],i=4;
// 1 2 3 4 5 
cout<<"Enter the 5 digit number: \n";
cin >> num;
while(num!=0){
    digit=num%10;
    for(int i=0;i<digit;i++){
        cout<<"*";
    }
    cout<<"\n";
    num/=10;
}
return 0;
}